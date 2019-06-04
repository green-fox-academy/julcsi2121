#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

TIM_HandleTypeDef timer_handle_counter;
TIM_HandleTypeDef timer_handle;
TIM_OC_InitTypeDef pwm_config;
GPIO_InitTypeDef pin15a;
GPIO_InitTypeDef pin_adc;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_handle;
UART_HandleTypeDef uart_handle;

volatile uint32_t min_duty_cycle = 10;
volatile uint32_t max_duty_cycle = 100;
volatile uint32_t duty_cycle = 10;
volatile int frequency = 10000;
volatile int on = 0;
int adc_val;

#define UART_PUTCHAR int __io_putchar(int ch)


void SystemClock_Config(void);
void set_duty_cycle(void);

void init_led()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	pin15a.Pin = GPIO_PIN_15;
	pin15a.Mode = GPIO_MODE_AF_PP;
	pin15a.Pull = GPIO_NOPULL;
	pin15a.Speed = GPIO_SPEED_HIGH;
	pin15a.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &pin15a);
}


void init_timer()
{
	__HAL_RCC_TIM3_CLK_ENABLE();

	timer_handle_counter.Instance = TIM3;
	timer_handle_counter.Init.Prescaler = 10800 - 1; // 0.1 ms
	timer_handle_counter.Init.Period = frequency - 1; // between 20000 and 1000

	HAL_TIM_Base_Init(&timer_handle_counter);
	HAL_NVIC_SetPriority(TIM3_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void init_pwm_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 108 - 1; // 0.001ms
	timer_handle.Init.Period = 100 - 1;  // 0.1ms
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer_handle);
}

void init_pwm()
{
	pwm_config.Pulse = 50;
	pwm_config.OCMode = TIM_OCMODE_PWM1;
	pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer_handle, &pwm_config, TIM_CHANNEL_1);
}

void init_adc()
{
	pin_adc.Mode = GPIO_MODE_ANALOG;
	pin_adc.Pin = GPIO_PIN_0;
	pin_adc.Pull = GPIO_NOPULL;
	pin_adc.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOA, &pin_adc);

	__HAL_RCC_ADC3_CLK_ENABLE();
	adc_handle.Instance = ADC3;
	adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	adc_handle.Init.Resolution = ADC_RESOLUTION12b;

    adc_handle.Init.ScanConvMode = DISABLE;
    adc_handle.Init.ContinuousConvMode = DISABLE;
    adc_handle.Init.DiscontinuousConvMode = DISABLE;
    adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
    adc_handle.Init.NbrOfDiscConversion = 1;

    HAL_ADC_Init(&adc_handle);

    adc_channel_handle.Channel = ADC_CHANNEL_0;
    adc_channel_handle.SamplingTime = ADC_SAMPLETIME_56CYCLES;

    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_handle);

}

void init_uart()
{
    /* enable the clock of the used peripherial instance */
        __HAL_RCC_USART1_CLK_ENABLE();

        /* defining the UART configuration structure */
        uart_handle.Instance = USART1;
        uart_handle.Init.BaudRate = 115200;
        uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
        uart_handle.Init.StopBits = UART_STOPBITS_1;
        uart_handle.Init.Parity = UART_PARITY_NONE;
        uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
        uart_handle.Init.Mode = UART_MODE_TX_RX;

        BSP_COM_Init(COM1, &uart_handle);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_timer();
	init_pwm_timer();
	init_pwm();
	init_led();
	init_adc();
	init_uart();


	HAL_TIM_Base_Start_IT(&timer_handle_counter);
	HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);

	while (1) {
	}
}


void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_handle_counter);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *timer_handle_counter)
{
	if (timer_handle_counter->Instance == TIM3) {

		//MODE2
		HAL_ADC_Start(&adc_handle);
		if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
            frequency = HAL_ADC_GetValue(&adc_handle) * 5 + 1000;
            printf("ADC value: %d.\n", frequency);
		}
		set_duty_cycle();
        __HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, duty_cycle);
		timer_handle_counter->Init.Period = frequency - 1;

		// MODE1
		//HAL_ADC_Start(&adc_handle);
		//if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
            //min_duty_cycle = HAL_ADC_GetValue(&adc_handle) / 40;
            //printf("ADC value: %d.\n", min_duty_cycle);
		//}
		//set_duty_cycle();
        //__HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, duty_cycle);
	}
}

// MODE1
void set_duty_cycle(void)
{
	if (on == 0) {
		duty_cycle = max_duty_cycle;
		on = 1;
	} else if (on == 1) {
		duty_cycle = min_duty_cycle;
		on = 0;
	}
}

UART_PUTCHAR
{
    HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}

void Error_Handler(void)
{}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /**Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 216;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 2;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    /**Activate the Over-Drive mode */
    if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
        Error_Handler();
    }

    /**Initializes the CPU, AHB and APB busses clocks */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}
