#ifndef SPI_BUS_H_
#define SPI_BUS_H_

#include "gpio.h"
#include "spi_interface.h"
#include "stdbool.h"
#include "stdint.h"

typedef enum
{
    SPI_BUS_ID_1,
    SPI_BUS_ID_2,
    SPI_BUS_ID_3,
    SPI_BUS_ID_4,
    SPI_BUS_ID_5,
    SPI_BUS_ID_6,
    SPI_BUS_MAX_SUPPORTED,
} SPI_Bus_ID_T;

typedef struct
{
    GPIO_Port_ID_T port;
    uint8_t pin;
} SPI_Chip_Select_T;

typedef enum
{
    SPI_CLOCK_LOW,  // CPOL = 0, clock is low at idle
    SPI_CLOCK_HIGH, // CPOL = 1, clock is high at idle
    SPI_CLOCK_INVALID_POLARITY
} SPI_Clock_Polarity_T;

typedef enum
{
    SPI_CLOCK_FIRST_EDGE,  // CPHA = 0 (rising edge if SPI_CLOCK_LOW, falling if SPI_CLOCK_HIGH)
    SPI_CLOCK_SECOND_EDGE, // CPHA = 1 (falling edge if SPI_CLOCK_LOW, rising if SPI_CLOCK_HIGH)
    SPI_CLOCK_INVALID_PHASE
} SPI_Clock_Phase_T;

typedef struct
{
    SPI_Clock_Polarity_T clock_polarity;
    SPI_Clock_Phase_T clock_phase;
} SPI_Transfer_Params_T;

typedef struct
{
    SPI_Bus_ID_T id;
    SPI_Transfer_Params_T last_params;

    // info on transaction currently in progress
    SPI_Chip_Select_T active_chip_select;
    SPI_Xfer_Complete_Callback active_complete_cb;
    SPI_Xfer_Error_Callback active_error_cb;
    void *active_cb_data;
} SPI_Bus_T;

/**
 ***************************************************************************************************
 *
 * @brief   Initializes the SPI_Bus_T data structure.  Must be called before SPI_Bus_Transfer or
 *          SPI_Bus_Write.  This function does NOT initialize hardware pins or peripherals.  The
 *          application is responsible for configuring hardware prior to calling SPI_Bus_Transfer or
 *          SPI_Bus_Write.
 *
 * @param   p_spi_bus               pointer to SPI_Bus_T data structure
 * @param   id                      id of bus
 *
 **************************************************************************************************/
void SPI_Bus_Init(SPI_Bus_T *p_spi_bus, SPI_Bus_ID_T id);

/**
 ***************************************************************************************************
 *
 * @brief   Non-blocking SPI transaction, sending the tx data buffer over MOSI and storing
 *          the received MISO data in the rx data buffer.
 *
 * The TX buffer and RX buffer must *both* be at least 'data_len' bytes long.
 *
 * @param   bus_id                  id of the SPI bus
 * @param   chip_select             port and pin of the desired device
 * @param   *tx_buffer              data to be transmitted
 * @param   *rx_buffer              buffer for received data
 * @param   data_len                length of transaction in bytes
 * @param   params                  data structure with SPI configuration for this device
 * @param   complete_cb             callback to call when transfer is complete
 * @param   error_cb                callback to call when there is an error with the transfer
 * @param   cb_data                 pointer that will be passed as a parameter to the callback
 * @retval  SPI_RTN_SUCCESS         Success
 * @retval  SPI_RTN_BUSY            SPI transfer currently in progress
 * @retval  SPI_RTN_INVALID_PARAM   a parameter is not valid
 *
 **************************************************************************************************/
SPI_Return_T SPI_Bus_Transfer(
    SPI_Bus_ID_T bus_id,
    SPI_Chip_Select_T chip_select,
    uint8_t *tx_buffer,
    uint8_t *rx_buffer,
    const uint16_t data_len,
    SPI_Transfer_Params_T params,
    SPI_Xfer_Complete_Callback complete_cb,
    SPI_Xfer_Error_Callback error_cb,
    void *cb_data);

/**
 ***************************************************************************************************
 *
 * @brief   Non-blocking SPI write, sending the tx data buffer over MOSI.  Incoming data
 *          on the MISO pin is ignored.  This saves the space of the receive buffer if you don't
 *          care about the received data.
 *
 * @param   bus_id                  id of the SPI bus
 * @param   chip_select             port and pin of the desired device
 * @param   *tx_buffer              data to be transmitted
 * @param   data_len                length of transaction in bytes
 * @param   params                  data structure with SPI configuration for this particular device
 * @param   complete_cb             callback to call when transfer is complete
 * @param   error_cb                callback to call when there is an error with the transfer
 * @param   cb_data                 pointer that will be passed as a parameter to the callback
 * @retval  SPI_RTN_SUCCESS         Success
 * @retval  SPI_RTN_BUSY            SPI transfer currently in progress
 * @retval  SPI_RTN_INVALID_PARAM   a parameter is not valid
 *
 **************************************************************************************************/
SPI_Return_T SPI_Bus_Write(
    SPI_Bus_ID_T bus_id,
    SPI_Chip_Select_T chip_select,
    uint8_t *tx_buffer,
    const uint16_t data_len,
    SPI_Transfer_Params_T params,
    SPI_Xfer_Complete_Callback complete_cb,
    SPI_Xfer_Error_Callback error_cb,
    void *cb_data);

#endif // SPI_BUS_H_
