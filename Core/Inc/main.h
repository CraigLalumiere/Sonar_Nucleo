/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define GainSel0_Pin             GPIO_PIN_0
#define GainSel0_GPIO_Port       GPIOC
#define GainSel1_Pin             GPIO_PIN_1
#define GainSel1_GPIO_Port       GPIOC
#define GainSel2_Pin             GPIO_PIN_2
#define GainSel2_GPIO_Port       GPIOC
#define XDCR_RX_Pin              GPIO_PIN_0
#define XDCR_RX_GPIO_Port        GPIOA
#define XDCR_RX_AC_Pin           GPIO_PIN_1
#define XDCR_RX_AC_GPIO_Port     GPIOA
#define FW_LED_Pin               GPIO_PIN_5
#define FW_LED_GPIO_Port         GPIOA
#define XDCR_PWR_SENSE_Pin       GPIO_PIN_6
#define XDCR_PWR_SENSE_GPIO_Port GPIOA
#define WATER_TEMP_Pin           GPIO_PIN_5
#define WATER_TEMP_GPIO_Port     GPIOC
#define XRDC_RX_AMP_Pin          GPIO_PIN_11
#define XRDC_RX_AMP_GPIO_Port    GPIOB
#define FW_LEDC10_Pin            GPIO_PIN_10
#define FW_LEDC10_GPIO_Port      GPIOC
#define XDCR_PWR_EN_Pin          GPIO_PIN_11
#define XDCR_PWR_EN_GPIO_Port    GPIOC
#define DEBUG_GPIO_Pin           GPIO_PIN_6
#define DEBUG_GPIO_GPIO_Port     GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
