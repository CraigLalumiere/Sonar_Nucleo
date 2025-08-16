#include "bsp.h" // Board Support Package
#include "halt_if_debugging.h"
#include "interfaces/spi_interface.h"
#include "interfaces/uart.h"
#include "main.h"
#include "pubsub_signals.h"
#include "qpc.h" // QP/C real-time embedded framework
#include "reset.h"
#include "spi_bus_stm32.h"
#include "stm32g4xx_hal.h"
#include <stdio.h>

Q_DEFINE_THIS_MODULE("bsp.c")

/**************************************************************************************************\
* Private macros
\**************************************************************************************************/

#define UART1_RX_BUFFER_LEN 128
#define UART1_TX_BUFFER_LEN 8192

/**************************************************************************************************\
* Private type definitions
\**************************************************************************************************/

extern ADC_HandleTypeDef hadc2;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim15;

typedef enum
{
    SPI_DEVICE_HV_DPOT
} SPI_Device_ID_T;

typedef struct
{
    SPI_Device_ID_T device_id;
    SPI_Bus_ID_T bus_id;
    SPI_Chip_Select_T chip_select;
    SPI_Transfer_Params_T params;
} SPI_Device_T;

/**************************************************************************************************\
* Private prototypes
\**************************************************************************************************/

static uint16_t lpuart1_TransmitData(const uint8_t *data_ptr, const uint16_t data_len);
static uint16_t lpuart1_ReceiveData(uint8_t *data_ptr, const uint16_t max_data_len);
static void lpuart1_RegisterDataReadyCB(Serial_IO_Data_Ready_Callback cb, void *cb_data);
static void Configure_lpuart1(UART_Config_T *p_uart_config);
static void SPI_Init();

static SPI_Return_T BSP_SPI_Write_HV_DPOT(
    uint8_t *tx_buffer,
    const uint16_t data_len,
    SPI_Xfer_Complete_Callback complete_cb,
    SPI_Xfer_Error_Callback error_cb,
    void *cb_data);

/**************************************************************************************************\
* Private memory declarations
\**************************************************************************************************/

const Serial_IO_T s_bsp_serial_io_uart = {
    .tx_func          = lpuart1_TransmitData,
    .rx_func          = lpuart1_ReceiveData,
    .register_cb_func = lpuart1_RegisterDataReadyCB,
};

extern UART_HandleTypeDef hlpuart1; // defined in main.c by cubeMX

static UART_T s_lpuart1;
static uint8_t s_rx_data_buffer[UART1_RX_BUFFER_LEN] = {0};
static uint8_t s_tx_data_buffer[UART1_TX_BUFFER_LEN] = {0};

static bool debug_gpio_state = false;

SPI_Device_T spi_devices[] = {
    {SPI_DEVICE_HV_DPOT,
     SPI_BUS_ID_1,
     {GPIO_PORT_A_ID, 10},
     {SPI_CLOCK_LOW, SPI_CLOCK_FIRST_EDGE}}};

static SPI_Bus_T s_spi_bus1;

/**************************************************************************************************\
* Public functions
\**************************************************************************************************/

/**
 ***************************************************************************************************
 * @brief   QP Assert handler
 **************************************************************************************************/
Q_NORETURN Q_onError(char const *const module, int_t const loc)
{
    // NOTE: this implementation of the error handler is intended only
    // for debugging and MUST be changed for deployment of the application
    // (assuming that you ship your production code with assertions enabled).
    Q_UNUSED_PAR(module);
    Q_UNUSED_PAR(loc);
    QS_ASSERTION(module, loc, 10000U);

#ifndef NDEBUG
    BSP_LED_On();
#endif

    const uint32_t NOT_USED = 0;
    Reset_DoResetWithReasonWithStr(RESET_REASON_Q_ASSERT, module, loc, NOT_USED);
}

/**
 ***************************************************************************************************
 * @brief   Perform a reset of the microcontroller
 **************************************************************************************************/
__attribute__((noreturn)) void BSP_SystemReset(void)
{
    HALT_IF_DEBUGGING();
    NVIC_SystemReset();
}

/**
 ***************************************************************************************************
 * @brief   Read the microcontroller's RCC CSR Register.
 **************************************************************************************************/
uint32_t BSP_RCC_CSR_Read(void)
{
    return RCC->CSR;
}

/**
 ***************************************************************************************************
 * @brief   Clear reset flags indicated by the RCC CSR Register.
 **************************************************************************************************/
void BSP_RCC_CSR_ClearResetFlags(void)
{
    // From Ref Manual:
    //   RMVF: Remove reset flag -- This bit is set by software to clear the reset flags.
    RCC->CSR |= RCC_CSR_RMVF;
}

//............................................................................
void assert_failed(char const *const module, int_t const id); // prototype
void assert_failed(char const *const module, int_t const id)
{
    Q_onError(module, id);
}

//............................................................................
void SysTick_Handler(void); // prototype
void SysTick_Handler(void)
{
    QK_ISR_ENTRY();
    HAL_IncTick();
    QTIMEEVT_TICK(0U); // process time events for primary clock rate
    QK_ISR_EXIT();
}

//============================================================================
// BSP functions...

/**
 ***************************************************************************************************
 *
 * @brief   Millisecond Tick
 *
 **************************************************************************************************/
uint32_t BSP_Get_Milliseconds_Tick(void)
{
    return HAL_GetTick();
}

//............................................................................
void BSP_Init(void)
{
    HAL_StatusTypeDef retval;

    UART_Config_T lpuart1_config;
    Configure_lpuart1(&lpuart1_config);
    UART_Init(&s_lpuart1, &lpuart1_config);

    // Initialize SPI buses
    SPI_Init();
    SPI_Bus_Init(&s_spi_bus1, SPI_BUS_ID_1);

    // init temp sensor ADC
    HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);

    //////////////////////////////////////////
    // init ADC control timers (TIM1, TIM2)
    //////////////////////////////////////////
    // set TIM2's CNT to some high value so that the timers DO NOT START until we later change this
    // back to zero
    TIM2->CNT = 0xFFFF;

    // TIM2 counts the pulses generated by TIM1
    retval = HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_1);
    Q_ASSERT(retval == HAL_OK);

    // TIM1 is gated by TRGO of TIM2
    retval = HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    Q_ASSERT(retval == HAL_OK);

    //////////////////////////////////////////
    // init PWM timers (TIM8, TIM3)
    //////////////////////////////////////////

    HAL_Delay(1); // delay to prevent bug of TIM20 getting triggered immediately

    // TIM8 CH1/CH1n is half bridge 1
    retval = HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
    Q_ASSERT(retval == HAL_OK);
    retval = HAL_TIMEx_PWMN_Start(&htim8, TIM_CHANNEL_1);
    Q_ASSERT(retval == HAL_OK);

    // TIM8 CH2 triggers TIM15 such that it is a half period out of phase
    retval = HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_2);
    Q_ASSERT(retval == HAL_OK);

    // TIM15 CH1/CH1n is half bridge 2
    retval = HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_1);
    Q_ASSERT(retval == HAL_OK);
    retval = HAL_TIMEx_PWMN_Start(&htim15, TIM_CHANNEL_1);
    Q_ASSERT(retval == HAL_OK);
}
//............................................................................
static void SPI_Init()
{
    HAL_StatusTypeDef retval;
    // SPI Bus 5 Peripheral
    SPI_HandleTypeDef *p_hspi1 = STM32_GetSPIHandle(SPI_BUS_ID_1);

    p_hspi1->Instance               = SPI1;
    p_hspi1->Init.Mode              = SPI_MODE_MASTER;
    p_hspi1->Init.Direction         = SPI_DIRECTION_2LINES;
    p_hspi1->Init.DataSize          = SPI_DATASIZE_8BIT;
    p_hspi1->Init.CLKPolarity       = SPI_POLARITY_LOW;
    p_hspi1->Init.CLKPhase          = SPI_PHASE_1EDGE;
    p_hspi1->Init.NSS               = SPI_NSS_SOFT;
    p_hspi1->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8; // APB2 = 168MHz --> SPI5 = 21 MHz
    p_hspi1->Init.FirstBit          = SPI_FIRSTBIT_MSB;
    p_hspi1->Init.TIMode            = SPI_TIMODE_DISABLE;
    p_hspi1->Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
    p_hspi1->Init.NSSPMode          = SPI_NSS_PULSE_ENABLE;

    retval = HAL_SPI_Init(p_hspi1);
    Q_ASSERT(retval == HAL_OK);
}
//............................................................................
void BSP_LED_On()
{
    HAL_GPIO_WritePin(FW_LED_GPIO_Port, FW_LED_Pin, 1);
}
//............................................................................
void BSP_LED_Off()
{
    HAL_GPIO_WritePin(FW_LED_GPIO_Port, FW_LED_Pin, 0);
}
//............................................................................
void BSP_debug_gpio_on()
{
    debug_gpio_state = true;
    // HAL_GPIO_WritePin(DEBUG_GPIO_GPIO_Port, DEBUG_GPIO_Pin, debug_gpio_state);
}
//............................................................................
void BSP_debug_gpio_off()
{
    debug_gpio_state = false;
    // HAL_GPIO_WritePin(DEBUG_GPIO_GPIO_Port, DEBUG_GPIO_Pin, debug_gpio_state);
}
//............................................................................
void BSP_debug_gpio_toggle()
{
    debug_gpio_state = !debug_gpio_state;
    // HAL_GPIO_WritePin(DEBUG_GPIO_GPIO_Port, DEBUG_GPIO_Pin, debug_gpio_state);
}

/**
 ***************************************************************************************************
 * @brief   Functions for HV DPOT
 **************************************************************************************************/

static SPI_Return_T BSP_SPI_Write_HV_DPOT(
    uint8_t *tx_buffer,
    const uint16_t data_len,
    SPI_Xfer_Complete_Callback complete_cb,
    SPI_Xfer_Error_Callback error_cb,
    void *cb_data)
{
    SPI_Device_T *p_device = &(spi_devices[SPI_DEVICE_HV_DPOT]);
    return SPI_Bus_Write(
        p_device->bus_id,
        p_device->chip_select,
        tx_buffer,
        data_len,
        p_device->params,
        complete_cb,
        error_cb,
        cb_data);
}

SPI_Write BSP_Get_SPI_Write_HV_DPOT()
{
    return BSP_SPI_Write_HV_DPOT;
}

/**
 ***************************************************************************************************
 * @brief   Functions for temp sensor
 **************************************************************************************************/

void BSP_Temp_Pwr_ADC_Begin_Conversion(uint16_t *dma_buffer)
{
    HAL_StatusTypeDef retval;

    retval = HAL_ADC_Stop_DMA(&hadc2);
    Q_ASSERT(retval == HAL_OK);

    // Restart the DMA since it is in normal mode, not circular
    retval = HAL_ADC_Start_DMA(&hadc2, (uint32_t *) dma_buffer, 2);
    // not sure why this is necessary, I didn't need it when I did the same thing on Purafy!
    __HAL_ADC_ENABLE_IT(&hadc2, ADC_IT_EOS);
    Q_ASSERT(retval == HAL_OK);
}

/**
 ***************************************************************************************************
 * @brief   Functions for sonar transmitter
 **************************************************************************************************/

void BSP_Begin_Sonar_Transceive()
{
    TIM2->CNT = 0x00;
}

void BSP_HV_Enable()
{
    HAL_GPIO_WritePin(nHV_DISCHARGE_GPIO_Port, nHV_DISCHARGE_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(HV_EN_GPIO_Port, HV_EN_Pin, GPIO_PIN_SET);
}
void BSP_HV_Discharge()
{
    HAL_GPIO_WritePin(nHV_DISCHARGE_GPIO_Port, nHV_DISCHARGE_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HV_EN_GPIO_Port, HV_EN_Pin, GPIO_PIN_RESET);
}

//............................................................................
void BSP_terminate(int16_t result)
{
    Q_UNUSED_PAR(result);
}

//============================================================================
// QF callbacks...
void QF_onStartup(void)
{
    // set up the SysTick timer to fire at BSP_TICKS_PER_SEC rate
    SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);

    // assign all priority bits for preemption-prio. and none to sub-prio.
    NVIC_SetPriorityGrouping(0U);

    // set priorities of ALL ISRs used in the system, see NOTE1
    // NVIC_SetPriority(EXTI0_IRQn, QF_AWARE_ISR_CMSIS_PRI + 0U);
    // NVIC_SetPriority(TIM4_IRQn, QF_AWARE_ISR_CMSIS_PRI + 0U);
    NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, QF_AWARE_ISR_CMSIS_PRI + 0U); // tach input capture
    NVIC_SetPriority(I2C2_EV_IRQn, QF_AWARE_ISR_CMSIS_PRI + 1U);        // I2C for pressure and OLED
    NVIC_SetPriority(I2C2_ER_IRQn, QF_AWARE_ISR_CMSIS_PRI + 1U);        // I2C for pressure and OLED
    NVIC_SetPriority(USART2_IRQn, QF_AWARE_ISR_CMSIS_PRI + 2U);
    NVIC_SetPriority(SysTick_IRQn, QF_AWARE_ISR_CMSIS_PRI + 12U);
    // ...

    // enable IRQs...
    // NVIC_EnableIRQ(EXTI0_IRQn);
    // HAL_NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // enaled by AO

#ifdef Q_SPY
    NVIC_EnableIRQ(USART2_IRQn); // UART2 interrupt used for QS-RX
#endif
}
//............................................................................
void QF_onCleanup(void)
{
}
//............................................................................
void QK_onIdle(void)
{ // called with interrupts DISABLED, see NOTE01
}

/*****************************************************************************
 * NOTE1:
 * The QF_AWARE_ISR_CMSIS_PRI constant from the QF port specifies the highest
 * ISR priority that is disabled by the QF framework. The value is suitable
 * for the NVIC_SetPriority() CMSIS function.
 *
 * Only ISRs prioritized at or below the QF_AWARE_ISR_CMSIS_PRI level (i.e.,
 * with the numerical values of priorities equal or higher than
 * QF_AWARE_ISR_CMSIS_PRI) are allowed to call the QK_ISR_ENTRY/QK_ISR_ENTRY
 * macros or any other QF services. These ISRs are "QF-aware".
 *
 * Conversely, any ISRs prioritized above the QF_AWARE_ISR_CMSIS_PRI priority
 * level (i.e., with the numerical values of priorities less than
 * QF_AWARE_ISR_CMSIS_PRI) are never disabled and are not aware of the kernel.
 * Such "QF-unaware" ISRs cannot call any QF services. In particular they
 * can NOT call the macros QK_ISR_ENTRY/QK_ISR_ENTRY. The only mechanism
 * by which a "QF-unaware" ISR can communicate with the QF framework is by
 * triggering a "QF-aware" ISR, which can post/publish events.
 *
 */

/**
 ***************************************************************************************************
 * @brief   Functions for CLI via UART
 **************************************************************************************************/

const Serial_IO_T *BSP_Get_Serial_IO_Interface_UART()
{
    return &s_bsp_serial_io_uart;
}

/**************************************************************************************************\
* Private functions
\**************************************************************************************************/

/**
 ***************************************************************************************************
 *  @brief   Functions for LPUART
 **************************************************************************************************/

static void Configure_lpuart1(UART_Config_T *p_uart_config)
{
    p_uart_config->uart_id            = LPUART_ID_1;
    p_uart_config->baud_rate_bps      = 500000;
    p_uart_config->n_data_bits        = 8;
    p_uart_config->n_stop_bits        = 1;
    p_uart_config->parity             = UART_PARITY_VAL_NONE;
    p_uart_config->hwctrl             = UART_HWCTRL_NONE;
    p_uart_config->tx_data_buffer     = s_tx_data_buffer;
    p_uart_config->tx_data_buffer_len = UART1_TX_BUFFER_LEN;
    p_uart_config->rx_data_buffer     = s_rx_data_buffer;
    p_uart_config->rx_data_buffer_len = UART1_RX_BUFFER_LEN;
    p_uart_config->callback           = NULL;
    p_uart_config->cb_data            = NULL;
}

static uint16_t lpuart1_TransmitData(const uint8_t *data_ptr, const uint16_t data_len)
{
    UART_Return_T retval = UART_TransmitData(&s_lpuart1, data_ptr, data_len);
    return (retval == UART_RTN_SUCCESS) ? data_len : 0;
}

static uint16_t lpuart1_ReceiveData(uint8_t *data_ptr, const uint16_t max_data_len)
{
    if (max_data_len == 0)
    {
        return 0;
    }

    UART_Return_T retval = UART_ReceiveByte(&s_lpuart1, data_ptr);
    return (retval == UART_RTN_SUCCESS) ? 1 : 0;
}

static void lpuart1_RegisterDataReadyCB(Serial_IO_Data_Ready_Callback cb, void *cb_data)
{
    UART_RegisterDataReadyCB(&s_lpuart1, cb, cb_data);
}