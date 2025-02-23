#include "bsp.h"
#include "pubsub_signals.h"
#include "stm32g4xx_hal.h"

extern ADC_HandleTypeDef hadc2;

inline void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc->Instance == hadc2.Instance)
    {
        static QEvt const event = QEVT_INITIALIZER(PUBSUB_ADC2_COMPLETE_SIG);
        QACTIVE_PUBLISH(&event, NULL);
    }
}