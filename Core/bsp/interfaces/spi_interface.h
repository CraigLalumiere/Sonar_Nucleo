#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    SPI_RTN_SUCCESS,
    SPI_RTN_BUSY,
    SPI_RTN_ERROR,
    SPI_RTN_TIMEOUT,
} SPI_Return_T;

typedef void (*SPI_Xfer_Complete_Callback)(void *cb_data);
typedef void (*SPI_Xfer_Error_Callback)(void *cb_data);

/**
 ***************************************************************************************************
 *
 * @brief   Non-blocking SPI transaction, sending the tx data buffer over MOSI and storing
 *          the received MISO data in the rx data buffer.
 *
 * The TX buffer and RX buffer must *both* be at least 'data_len' bytes long.
 *
 * @param   *tx_buffer              data to be transmitted
 * @param   *rx_buffer              buffer for received data
 * @param   data_len                length of transaction in bytes
 * @param   complete_cb             callback to call when transfer is complete
 * @param   error_cb                callback to call when there is an error with the transfer
 * @param   cb_data                 pointer that will be passed as a parameter to the callback
 * @retval  SPI_RTN_SUCCESS         Success
 * @retval  SPI_RTN_BUSY            SPI transfer currently in progress
 * @retval  SPI_RTN_ERROR           An error occurred
 *
 **************************************************************************************************/
typedef SPI_Return_T (*SPI_Transfer)(
    uint8_t *tx_buffer,
    uint8_t *rx_buffer,
    const uint16_t data_len,
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
 * @param   *tx_buffer              data to be transmitted
 * @param   data_len                length of transaction in bytes
 * @param   complete_cb             callback to call when transfer is complete
 * @param   error_cb                callback to call when there is an error with the transfer
 * @param   cb_data                 pointer that will be passed as a parameter to the callback
 * @retval  SPI_RTN_SUCCESS         Success
 * @retval  SPI_RTN_BUSY            SPI transfer currently in progress
 * @retval  SPI_RTN_ERROR           An error occurred
 *
 **************************************************************************************************/
typedef SPI_Return_T (*SPI_Write)(
    uint8_t *tx_buffer,
    const uint16_t data_len,
    SPI_Xfer_Complete_Callback complete_cb,
    SPI_Xfer_Error_Callback error_cb,
    void *cb_data);

#ifdef __cplusplus
}
#endif

#endif // SPI_INTERFACE_H_
