#ifndef SPI_BUS_STM32_H_
#define SPI_BUS_STM32_H_

#include "interfaces/spi_bus.h"
#include "stm32g4xx.h"

SPI_HandleTypeDef *STM32_GetSPIHandle(SPI_Bus_ID_T bus_id);

uint32_t STM32_SPI_GetPolarity(SPI_Clock_Polarity_T polarity);
uint32_t STM32_SPI_GetPhase(SPI_Clock_Phase_T phase);
#endif // SPI_BUS_STM32_H_
