#include "spi_bus_stm32.h"
#include "qsafe.h"
#include "stddef.h"

Q_DEFINE_THIS_MODULE("spi_bus_stm32");

static SPI_HandleTypeDef hspi1;
static SPI_HandleTypeDef hspi2;
static SPI_HandleTypeDef hspi3;
static SPI_HandleTypeDef hspi4;
static SPI_HandleTypeDef hspi5;
static SPI_HandleTypeDef hspi6;

SPI_HandleTypeDef *STM32_GetSPIHandle(SPI_Bus_ID_T bus_id)
{
    switch (bus_id)
    {
        case SPI_BUS_ID_1:
            return &hspi1;
        case SPI_BUS_ID_2:
            return &hspi2;
        case SPI_BUS_ID_3:
            return &hspi3;
        case SPI_BUS_ID_4:
            return &hspi4;
        case SPI_BUS_ID_5:
            return &hspi5;
        case SPI_BUS_ID_6:
            return &hspi6;
        default:
            return NULL;
    }
}

uint32_t STM32_SPI_GetPolarity(SPI_Clock_Polarity_T polarity)
{
    Q_ASSERT(polarity < SPI_CLOCK_INVALID_POLARITY);
    if (polarity == SPI_CLOCK_LOW)
    {
        return SPI_POLARITY_LOW;
    }
    else
    {
        return SPI_POLARITY_HIGH;
    }
}

uint32_t STM32_SPI_GetPhase(SPI_Clock_Phase_T phase)
{
    Q_ASSERT(phase < SPI_CLOCK_INVALID_PHASE);
    if (phase == SPI_CLOCK_FIRST_EDGE)
    {
        return SPI_PHASE_1EDGE;
    }
    else
    {
        return SPI_PHASE_2EDGE;
    }
}
