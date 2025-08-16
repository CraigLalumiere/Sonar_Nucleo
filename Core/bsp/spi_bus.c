#include "gpio_stm32.h"
#include "qsafe.h"
#include "spi_bus_stm32.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

Q_DEFINE_THIS_MODULE("spi_bus");

static SPI_Bus_T *s_spi_bus_table[] = {NULL, NULL, NULL, NULL, NULL, NULL};
static_assert(
    sizeof(s_spi_bus_table) / sizeof(s_spi_bus_table[0]) == SPI_BUS_MAX_SUPPORTED,
    "s_spi_bus_table bad length");

void SPI_Bus_Init(SPI_Bus_T *p_spi_bus, SPI_Bus_ID_T id)
{
    Q_ASSERT(id < SPI_BUS_MAX_SUPPORTED);
    s_spi_bus_table[id]                   = p_spi_bus;
    p_spi_bus->id                         = id;
    p_spi_bus->last_params.clock_phase    = SPI_CLOCK_INVALID_PHASE;
    p_spi_bus->last_params.clock_polarity = SPI_CLOCK_INVALID_POLARITY;

    p_spi_bus->active_chip_select.port = GPIO_PORT_NONE_ID;
    p_spi_bus->active_chip_select.pin  = 0xFF; // invalid value
    p_spi_bus->active_complete_cb      = NULL;
    p_spi_bus->active_error_cb         = NULL;
    p_spi_bus->active_cb_data          = NULL;
}

static void Generic_SPI_Complete_CB(SPI_HandleTypeDef *hspi, bool is_error)
{
    for (unsigned i = 0; i < SPI_BUS_MAX_SUPPORTED; i++)
    {
        if (s_spi_bus_table[i] != NULL)
        {
            if (hspi == STM32_GetSPIHandle(s_spi_bus_table[i]->id))
            {
                SPI_Chip_Select_T chip_select = s_spi_bus_table[i]->active_chip_select;

                if (chip_select.port != GPIO_PORT_NONE_ID)
                {
                    HAL_GPIO_WritePin(
                        STM32_GPIO_GetPort(chip_select.port),
                        STM32_GPIO_GetPin(chip_select.pin),
                        GPIO_PIN_SET);
                }

                if (is_error)
                {
                    if (s_spi_bus_table[i]->active_error_cb != NULL)
                    {
                        // If there is a valid error callback waiting for this spi bus, call it
                        s_spi_bus_table[i]->active_error_cb(s_spi_bus_table[i]->active_cb_data);
                    }
                }
                else
                {
                    if (s_spi_bus_table[i]->active_complete_cb != NULL)
                    {
                        // If there is a valid complete callback waiting for this spi bus, call it
                        s_spi_bus_table[i]->active_complete_cb(s_spi_bus_table[i]->active_cb_data);
                    }
                }

                break;
            }
        }
    }
}

// Externally available callback function, called by the STM32 HAL SPI Interrupt handler
//   once a SPI Transfer is complete
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
    Generic_SPI_Complete_CB(hspi, false);
}

// Externally available callback function, called by the STM32 HAL SPI Interrupt handler
//   once a SPI Write is complete
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    Generic_SPI_Complete_CB(hspi, false);
}

// Externally available callback function, called by the STM32 HAL SPI Interrupt handler
//   if there is an error during SPI transmission
void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
    Generic_SPI_Complete_CB(hspi, true);
}

// Externally available callback function, called by the STM32 HAL SPI Interrupt handler
//   if the SPI transaction is aborted
void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef *hspi)
{
    Generic_SPI_Complete_CB(hspi, true);
}

SPI_Return_T SPI_Bus_Transfer(
    SPI_Bus_ID_T bus_id,
    SPI_Chip_Select_T chip_select,
    uint8_t *tx_buffer,
    uint8_t *rx_buffer,
    const uint16_t data_len,
    SPI_Transfer_Params_T params,
    SPI_Xfer_Complete_Callback complete_cb,
    SPI_Xfer_Error_Callback error_cb,
    void *cb_data)
{
    Q_ASSERT(bus_id < SPI_BUS_MAX_SUPPORTED);
    Q_ASSERT(s_spi_bus_table[bus_id] != NULL); // means you didn't call SPI_Bus_Init for this bus
    Q_ASSERT(tx_buffer != NULL);
    Q_ASSERT(rx_buffer != NULL);
    Q_ASSERT(data_len > 0);
    Q_ASSERT(params.clock_polarity != SPI_CLOCK_INVALID_POLARITY);
    Q_ASSERT(params.clock_phase != SPI_CLOCK_INVALID_PHASE);

    SPI_Bus_T *p_spi_bus                  = s_spi_bus_table[bus_id];
    SPI_HandleTypeDef *p_stm32_spi_handle = STM32_GetSPIHandle(bus_id);

    if (HAL_SPI_GetState(p_stm32_spi_handle) != HAL_SPI_STATE_READY)
    {
        return SPI_RTN_BUSY;
    }

    p_spi_bus->active_complete_cb = complete_cb;
    p_spi_bus->active_error_cb    = error_cb;
    p_spi_bus->active_cb_data     = cb_data;
    p_spi_bus->active_chip_select = chip_select;

    // Reconfigure SPI bus with new parameters before starting transaction,
    //   if the parameters have changed since the last bus usage
    if (params.clock_polarity != p_spi_bus->last_params.clock_polarity ||
        params.clock_phase != p_spi_bus->last_params.clock_phase)
    {
        p_stm32_spi_handle->Init.CLKPolarity = STM32_SPI_GetPolarity(params.clock_polarity);
        p_stm32_spi_handle->Init.CLKPhase    = STM32_SPI_GetPhase(params.clock_phase);
        HAL_SPI_Init(p_stm32_spi_handle);
    }

    if (chip_select.port != GPIO_PORT_NONE_ID)
    {
        HAL_GPIO_WritePin(
            STM32_GPIO_GetPort(chip_select.port),
            STM32_GPIO_GetPin(chip_select.pin),
            GPIO_PIN_RESET);
    }

    HAL_StatusTypeDef retval = HAL_SPI_TransmitReceive_DMA(
        p_stm32_spi_handle, tx_buffer, rx_buffer, data_len);

    switch (retval)
    {
        case HAL_BUSY:
            return SPI_RTN_BUSY;
        case HAL_ERROR:
            return SPI_RTN_ERROR;
        case HAL_TIMEOUT:
            return SPI_RTN_TIMEOUT;
        default:
            return SPI_RTN_SUCCESS;
    }
}

SPI_Return_T SPI_Bus_Write(
    SPI_Bus_ID_T bus_id,
    SPI_Chip_Select_T chip_select,
    uint8_t *tx_buffer,
    const uint16_t data_len,
    SPI_Transfer_Params_T params,
    SPI_Xfer_Complete_Callback complete_cb,
    SPI_Xfer_Error_Callback error_cb,
    void *cb_data)
{
    Q_ASSERT(bus_id < SPI_BUS_MAX_SUPPORTED);
    Q_ASSERT(s_spi_bus_table[bus_id] != NULL); // means you didn't call SPI_Bus_Init for this bus
    Q_ASSERT(tx_buffer != NULL);
    Q_ASSERT(data_len > 0);
    Q_ASSERT(params.clock_polarity != SPI_CLOCK_INVALID_POLARITY);
    Q_ASSERT(params.clock_phase != SPI_CLOCK_INVALID_PHASE);

    SPI_Bus_T *p_spi_bus                  = s_spi_bus_table[bus_id];
    SPI_HandleTypeDef *p_stm32_spi_handle = STM32_GetSPIHandle(bus_id);

    if (HAL_SPI_GetState(p_stm32_spi_handle) != HAL_SPI_STATE_READY)
    {
        return SPI_RTN_BUSY;
    }

    p_spi_bus->active_complete_cb = complete_cb;
    p_spi_bus->active_error_cb    = error_cb;
    p_spi_bus->active_cb_data     = cb_data;
    p_spi_bus->active_chip_select = chip_select;

    // Reconfigure SPI bus with new parameters before starting transaction,
    //   if the parameters have changed since the last bus usage
    if (params.clock_polarity != p_spi_bus->last_params.clock_polarity ||
        params.clock_phase != p_spi_bus->last_params.clock_phase)
    {
        p_stm32_spi_handle->Init.CLKPolarity = STM32_SPI_GetPolarity(params.clock_polarity);
        p_stm32_spi_handle->Init.CLKPhase    = STM32_SPI_GetPhase(params.clock_phase);
        HAL_SPI_Init(p_stm32_spi_handle);
    }

    if (chip_select.port != GPIO_PORT_NONE_ID)
    {
        HAL_GPIO_WritePin(
            STM32_GPIO_GetPort(chip_select.port),
            STM32_GPIO_GetPin(chip_select.pin),
            GPIO_PIN_RESET);
    }

    HAL_StatusTypeDef retval = HAL_SPI_Transmit_DMA(p_stm32_spi_handle, tx_buffer, data_len);

    return (retval == HAL_OK) ? SPI_RTN_SUCCESS
                              : ((retval == HAL_BUSY) ? SPI_RTN_BUSY : SPI_RTN_ERROR);
}
