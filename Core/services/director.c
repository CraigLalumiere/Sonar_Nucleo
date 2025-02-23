#include "director.h"
#include "bsp.h"
#include "pc_com.h"
#include "private_signal_ranges.h"

/**************************************************************************************************\
* Private macros
\**************************************************************************************************/

/**************************************************************************************************\
* Private type definitions
\**************************************************************************************************/

enum DirectorSignals
{
    TIMEOUT_SIG = PRIVATE_SIGNAL_DIRECTOR_START,
};

typedef struct
{
    QActive super;    // inherit QActive
    QTimeEvt timeEvt; // private time event generator

    uint16_t adc_dma_buffer[2];
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
static QState running(Director *const me, QEvt const *const e);

/**************************************************************************************************\
* Public functions
\**************************************************************************************************/
void Director_ctor(void)
{
    Director *const me = &Director_inst;
    QActive_ctor(&me->super, Q_STATE_CAST(&initial));
    QTimeEvt_ctorX(&me->timeEvt, &me->super, TIMEOUT_SIG, 0U);
}

/**************************************************************************************************\
* Private functions
\**************************************************************************************************/

// HSM definition ----------------------------------------------------------
QState initial(Director *const me, void const *const par)
{
    Q_UNUSED_PAR(par);

    QActive_subscribe((QActive *) me, PUBSUB_SAMPLE_TEMP_SIG);
    QActive_subscribe((QActive *) me, PUBSUB_ADC2_COMPLETE_SIG);

    // arm the time event to expire in half a second and every half second
    // QTimeEvt_armX(&me->timeEvt, BSP_TICKS_PER_SEC / 2U, BSP_TICKS_PER_SEC / 2U);

    return Q_TRAN(&running);
}

//............................................................................
QState running(Director *const me, QEvt const *const e)
{
    QState status;
    switch (e->sig)
    {
        case Q_ENTRY_SIG: {
            status = Q_HANDLED();
            break;
        }
        case PUBSUB_SAMPLE_TEMP_SIG: {
            BSP_Temp_Pwr_ADC_Begin_Conversion(me->adc_dma_buffer);
            status = Q_HANDLED();
            break;
        }
        case PUBSUB_ADC2_COMPLETE_SIG: {
            status = Q_HANDLED();
            break;
        }
        default: {
            status = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status;
}