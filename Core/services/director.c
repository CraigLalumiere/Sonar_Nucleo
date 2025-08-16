#include "director.h"
#include "bsp.h"
#include "hvpot.h"
#include "pc_com.h"
#include "private_signal_ranges.h"
#include <math.h>
#include <stdio.h>

/**************************************************************************************************\
* Private macros
\**************************************************************************************************/

/**************************************************************************************************\
* Private type definitions
\**************************************************************************************************/

enum DirectorSignals
{
    ADC_READ_TIMEOUT_SIG = PRIVATE_SIGNAL_DIRECTOR_START,
    SPI_WRITE_HV_POT_COMPLETE_SIG,
    SPI_WRITE_HV_POT_ERROR_SIG,
    WAIT_SIG,
};

typedef struct
{
    QActive super;          // inherit QActive
    QTimeEvt sampleTimeEvt; // private time event generator
    QTimeEvt waitTimeEvt;   // private time event generator

    uint16_t adc_dma_buffer[2];

    SPI_Write spi_write_hv_pot;

    uint16_t hv_target_volts;
    uint8_t hv_pot_data;

    float hv_set_volts;
    bool hv_enabled;
} Director;

/**************************************************************************************************\
* Private memory declarations
\**************************************************************************************************/

Director Director_inst; // TODO: should this be static?
QActive *const AO_Director = &Director_inst.super;

/**************************************************************************************************\
* Private prototypes
\**************************************************************************************************/

static QState initial(Director *const me, void const *const par);
static QState top(Director *const me, QEvt const *const e);
static QState standby(Director *const me, QEvt const *const e);
static QState active(Director *const me, QEvt const *const e);
static QState charging(Director *const me, QEvt const *const e);
static QState charging_enable_minimum(Director *const me, QEvt const *const e);
static QState charging_rising(Director *const me, QEvt const *const e);
static QState charging_falling(Director *const me, QEvt const *const e);
static QState discharging(Director *const me, QEvt const *const e);
static QState discharging_disable(Director *const me, QEvt const *const e);
static QState discharging_discharge(Director *const me, QEvt const *const e);

static void SPI_Write_HV_Pot_Complete_CB(void *cb_data);
static void SPI_Write_HV_Pot_Error_CB(void *cb_data);

/**************************************************************************************************\
* Public functions
\**************************************************************************************************/
void Director_ctor(SPI_Write spi_write_hv_pot)
{
    Director *const me = &Director_inst;
    QActive_ctor(&me->super, Q_STATE_CAST(&initial));
    QTimeEvt_ctorX(&me->sampleTimeEvt, &me->super, ADC_READ_TIMEOUT_SIG, 0U);
    QTimeEvt_ctorX(&me->waitTimeEvt, &me->super, WAIT_SIG, 0U);

    me->spi_write_hv_pot = spi_write_hv_pot;
}

/**************************************************************************************************\
* Private functions
\**************************************************************************************************/

// HSM definition ----------------------------------------------------------
QState initial(Director *const me, void const *const par)
{
    Q_UNUSED_PAR(par);

    QActive_subscribe((QActive *) me, PUBSUB_ADC2_COMPLETE_SIG);
    QActive_subscribe((QActive *) me, PUBSUB_HV_CHARGE_SIG);
    QActive_subscribe((QActive *) me, PUBSUB_HV_DISCHARGE_SIG);
    QActive_subscribe((QActive *) me, PUBSUB_HV_SENSE_SIG);
    QActive_subscribe((QActive *) me, PUBSUB_ECHO_BEGIN_SIG);
    QActive_subscribe((QActive *) me, PUBSUB_RECEIVE_COMPLETE_SIG);

    // arm timer to sample HV and water temp every 10ms
    QTimeEvt_armX(&me->sampleTimeEvt, MILLISECONDS_TO_TICKS(10), MILLISECONDS_TO_TICKS(10));

    me->hv_set_volts = 12;
    me->hv_enabled   = false;

    return Q_TRAN(&top);
}

//............................................................................
QState top(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_ENTRY_SIG: {
            status = Q_HANDLED();
            break;
        }
        case Q_INIT_SIG: {
            status = Q_TRAN(&standby);
            break;
        }
        case PUBSUB_HV_DISCHARGE_SIG: {
            status = Q_TRAN(&discharging);
            break;
        }
        case ADC_READ_TIMEOUT_SIG: {
            // sample ADC to read water temp and HV
            BSP_Temp_Pwr_ADC_Begin_Conversion(me->adc_dma_buffer);
            status = Q_HANDLED();
            break;
        }
        case PUBSUB_ADC2_COMPLETE_SIG: {
            uint16_t hv_raw = me->adc_dma_buffer[0];
            // *6 determine by voltage divider on PCB
            float hv_sense      = (float) hv_raw * AVREF / ADC_RESOLUTION * 116.384;
            uint16_t water_temp = me->adc_dma_buffer[1];

            ADCEvent_T *temp_event = Q_NEW(ADCEvent_T, PUBSUB_WATER_TEMP_SIG);
            temp_event->raw        = water_temp;
            temp_event->value      = 0; // to do
            QACTIVE_PUBLISH(&temp_event->super, AO_Director);

            ADCEvent_T *pwr_event = Q_NEW(ADCEvent_T, PUBSUB_HV_SENSE_SIG);
            pwr_event->raw        = hv_raw;
            pwr_event->value      = hv_sense;
            QACTIVE_PUBLISH(&temp_event->super, AO_Director);

            status = Q_HANDLED();
            break;
        }
        case PUBSUB_HV_CHARGE_SIG: {
            me->hv_target_volts = Q_EVT_CAST(ChargeHighVoltageEvent_T)->target_volts;
            status              = Q_TRAN(&charging);
            break;
        }
        default: {
            status = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status;
}
//............................................................................
QState standby(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_ENTRY_SIG: {
            status = Q_HANDLED();
            break;
        }
        case PUBSUB_ECHO_BEGIN_SIG: {
            status = Q_TRAN(&active);
            break;
        }
        default: {
            status = Q_SUPER(&top);
            break;
        }
    }
    return status;
}
//............................................................................
QState active(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_ENTRY_SIG: {
            BSP_Begin_Sonar_Transceive();
            status = Q_HANDLED();
            break;
        }
        case PUBSUB_RECEIVE_COMPLETE_SIG: {
            status = Q_TRAN(&standby);
            break;
        }
        default: {
            status = Q_SUPER(&top);
            break;
        }
    }
    return status;
}
//............................................................................
QState charging(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_INIT_SIG: {
            // special startup procedure if converter is off
            if (!me->hv_enabled)
                status = Q_TRAN(&charging_enable_minimum);
            else
            {
                // increase converter voltage
                if (me->hv_target_volts > me->hv_set_volts)
                    status = Q_TRAN(&charging_rising);
                // lower converter voltage
                else
                    status = Q_TRAN(&charging_falling);
            }
            break;
        }
        case Q_ENTRY_SIG: {
            PC_COM_print("Charging HV");
            status = Q_HANDLED();
            break;
        }
        default: {
            status = Q_SUPER(&top);
            break;
        }
    }
    return status;
}
//............................................................................
static QState charging_enable_minimum(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_ENTRY_SIG: {
            me->hv_set_volts = 40;
            me->hv_pot_data  = 255; // Minimum possible voltage

            SPI_Return_T retval = me->spi_write_hv_pot(
                &me->hv_pot_data, 1, SPI_Write_HV_Pot_Complete_CB, SPI_Write_HV_Pot_Error_CB, me);

            if (retval != SPI_RTN_SUCCESS)
            {
                SPI_Write_HV_Pot_Error_CB((void *) me);
            }
            status = Q_HANDLED();
            break;
        }

        case SPI_WRITE_HV_POT_COMPLETE_SIG: {
            // Now that we've set the DPOT to a safe level, enable the converter
            me->hv_enabled = true;
            BSP_HV_Enable();
            status = Q_TRAN(&charging_rising);
            break;
        }
        default: {
            status = Q_SUPER(&charging);
            break;
        }
    }

    return status;
}
//............................................................................
static QState charging_rising(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_ENTRY_SIG: {
            status = Q_HANDLED();
            break;
        }
        case PUBSUB_HV_SENSE_SIG: {
            float voltage = Q_EVT_CAST(ADCEvent_T)->value;

            // If we've reached our target voltage
            if (me->hv_target_volts - voltage < 10 &&
                fabs(me->hv_set_volts - me->hv_target_volts) < 0.5)
            {
                char print_buffer[PC_COM_EVENT_MAX_MSG_LENGTH] = {0};
                snprintf(print_buffer, sizeof(print_buffer), "Charged to %.2fV", voltage);
                PC_COM_print(print_buffer);
                status = Q_TRAN(&standby);
                break;
            }
            // If we've reached an intermediate voltage step
            if (me->hv_set_volts - voltage < 10)
            {
                me->hv_set_volts += 50;
                if (me->hv_set_volts > me->hv_target_volts)
                    me->hv_set_volts = me->hv_target_volts;

                char print_buffer[PC_COM_EVENT_MAX_MSG_LENGTH] = {0};
                snprintf(print_buffer, sizeof(print_buffer), "Charging to %.2fV", me->hv_set_volts);
                PC_COM_print(print_buffer);

                me->hv_pot_data = HVPot_CalcRegisterValue(me->hv_set_volts);

                SPI_Return_T retval = me->spi_write_hv_pot(
                    &me->hv_pot_data,
                    1,
                    SPI_Write_HV_Pot_Complete_CB,
                    SPI_Write_HV_Pot_Error_CB,
                    me);

                if (retval != SPI_RTN_SUCCESS)
                {
                    SPI_Write_HV_Pot_Error_CB((void *) me);
                }
            }
            status = Q_HANDLED();
            break;
        }

        case SPI_WRITE_HV_POT_COMPLETE_SIG: {
            status = Q_HANDLED();
            break;
        }
        default: {
            status = Q_SUPER(&charging);
            break;
        }
    }

    return status;
}
//............................................................................
static QState charging_falling(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_ENTRY_SIG: {
            me->hv_set_volts = me->hv_target_volts;
            me->hv_pot_data  = HVPot_CalcRegisterValue(me->hv_target_volts);

            SPI_Return_T retval = me->spi_write_hv_pot(
                &me->hv_pot_data, 1, SPI_Write_HV_Pot_Complete_CB, SPI_Write_HV_Pot_Error_CB, me);

            if (retval != SPI_RTN_SUCCESS)
            {
                SPI_Write_HV_Pot_Error_CB((void *) me);
            }
            status = Q_HANDLED();
            break;
        }
        // wait until voltage has settled to desired value
        case PUBSUB_HV_SENSE_SIG: {
            float voltage = Q_EVT_CAST(ADCEvent_T)->value;
            if (voltage - me->hv_set_volts < 10)
            {
                char print_buffer[PC_COM_EVENT_MAX_MSG_LENGTH] = {0};
                snprintf(print_buffer, sizeof(print_buffer), "Discharged to %.2fV", voltage);
                PC_COM_print(print_buffer);
                status = Q_TRAN(&standby);
            }
            else
            {
                char print_buffer[PC_COM_EVENT_MAX_MSG_LENGTH] = {0};
                snprintf(print_buffer, sizeof(print_buffer), "Discharging... %.2fV", voltage);
                PC_COM_print(print_buffer);
                status = Q_HANDLED();
            }
            break;
        }

        case SPI_WRITE_HV_POT_COMPLETE_SIG: {
            status = Q_HANDLED();
            break;
        }
        default: {
            status = Q_SUPER(&charging);
            break;
        }
    }

    return status;
}
//............................................................................
QState discharging(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_INIT_SIG: {
            status = Q_TRAN(&discharging_disable);
            break;
        }
        case Q_ENTRY_SIG: {
            PC_COM_print("Discharging HV");
            status = Q_HANDLED();
            break;
        }
        default: {
            status = Q_SUPER(&top);
            break;
        }
    }
    return status;
}
//............................................................................
static QState discharging_disable(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_ENTRY_SIG: {
            BSP_HV_Disable();
            me->hv_enabled = false;
            // wait 2ms before discharging HV caps
            // QTimeEvt_armX(&me->waitTimeEvt, MILLISECONDS_TO_TICKS(2), 0);
            status = Q_HANDLED();
            break;
        }
        case PUBSUB_HV_SENSE_SIG: {
            float voltage = Q_EVT_CAST(ADCEvent_T)->value;

            char print_buffer[PC_COM_EVENT_MAX_MSG_LENGTH] = {0};
            snprintf(print_buffer, sizeof(print_buffer), "Discharging... %.2fV", voltage);
            PC_COM_print(print_buffer);

            if (voltage < 180.0)
                status = Q_TRAN(&discharging_discharge);
            else
                status = Q_HANDLED();
            break;
        }
        // case WAIT_SIG: {
        //     status = Q_TRAN(&discharging_discharge);
        //     break;
        // }
        default: {
            status = Q_SUPER(&discharging);
            break;
        }
    }
    return status;
}
//............................................................................
static QState discharging_discharge(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_ENTRY_SIG: {
            BSP_HV_Discharge();
            status = Q_HANDLED();
            break;
        }
        case PUBSUB_HV_SENSE_SIG: {
            float voltage = Q_EVT_CAST(ADCEvent_T)->value;

            char print_buffer[PC_COM_EVENT_MAX_MSG_LENGTH] = {0};
            snprintf(print_buffer, sizeof(print_buffer), "Discharging... %.2fV", voltage);
            PC_COM_print(print_buffer);
            if (voltage < 18.0)
            {
                BSP_HV_Stop_Discharge();
                status = Q_TRAN(&standby);
            }
            else
                status = Q_HANDLED();
            break;
        }
        default: {
            status = Q_SUPER(&discharging);
            break;
        }
    }
    return status;
}

static void SPI_Write_HV_Pot_Complete_CB(void *cb_data)
{
    static QEvt const event = QEVT_INITIALIZER(SPI_WRITE_HV_POT_COMPLETE_SIG);

    QActive *me = (QActive *) cb_data;
    QACTIVE_POST(me, &event, me);
}

static void SPI_Write_HV_Pot_Error_CB(void *cb_data)
{
    static QEvt const event = QEVT_INITIALIZER(SPI_WRITE_HV_POT_ERROR_SIG);

    QActive *me = (QActive *) cb_data;
    QACTIVE_POST(me, &event, me);
}