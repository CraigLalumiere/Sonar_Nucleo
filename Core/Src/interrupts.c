#include "bsp.h"
#include "main.h"
#include "pubsub_signals.h"
#include "stm32g4xx_hal.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim15;
extern ADC_HandleTypeDef hadc2;

inline void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc->Instance == hadc2.Instance)
    {
        static QEvt const event = QEVT_INITIALIZER(PUBSUB_ADC2_COMPLETE_SIG);
        QACTIVE_PUBLISH(&event, NULL);
    }
}

inline void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    static int i = 0;
    if (htim->Instance == htim2.Instance)
    {
        static QEvt const event = QEVT_INITIALIZER(PUBSUB_RECEIVE_COMPLETE_SIG);
        QACTIVE_PUBLISH(&event, NULL);
    }
    if (htim->Instance == htim15.Instance)
    {
        i++;
        // uint32_t cnt = htim15.Instance->CNT;
    }
}

inline void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    static int i = 0;
    if (htim->Instance == htim8.Instance)
    {
        // __HAL_TIM_MOE_DISABLE(&htim8);
        // __HAL_TIM_MOE_DISABLE(&htim15);

        // HAL_GPIO_WritePin(PWM_A_L_GPIO_Port, PWM_A_L_Pin, GPIO_PIN_RESET);
        // HAL_GPIO_WritePin(PWM_A_H_GPIO_Port, PWM_A_H_Pin, GPIO_PIN_RESET);

        uint32_t cnt = htim8.Instance->CNT;

        if (cnt == 0)
            HAL_NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);
    }
    if (htim->Instance == htim15.Instance)
    {
        i++;
        TIM8->CCER |= TIM_CCER_CC1P;  // invert CH1
        TIM15->CCER |= TIM_CCER_CC1P; // invert CH1N
        HAL_NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);
    }
}