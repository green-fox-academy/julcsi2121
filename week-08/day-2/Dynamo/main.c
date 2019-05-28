#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

TIM_HandleTypeDef timer_handle;
TIM_HandleTypeDef timer_handle_pwm;
TIM_OC_InitTypeDef pwm_config;
GPIO_InitTypeDef leds;
GPIO_InitTypeDef user_button;

volatile int duty_cycle = 0;

/*
 * lemérni a periódusidő alatti gombnyomások számát
 * pulse-ot ennek megfeleltetni (vagy arányosítani)
 * extra - ne azonnal aludjon ki
 */

void SystemClock_Config(void);

void init_led()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	leds.Pin = GPIO_PIN_15;
	leds.Mode = GPIO_MODE_AF_PP;
	leds.Pull = GPIO_NOPULL;
	leds.Speed = GPIO_SPEED_HIGH;
	leds.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &leds);
}

void init_timer()
{
	__HAL_RCC_TIM3_CLK_ENABLE();

	timer_handle.Instance = TIM3;
	timer_handle.Init.Prescaler = 10800 * 5 - 1; // 0.5 ms
	timer_handle.Init.Period = 100 - 1; // 0.1 s

	HAL_TIM_Base_Init(&timer_handle);
	HAL_NVIC_SetPriority(TIM3_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void init_pwm_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	timer_handle_pwm.Instance = TIM2;
	timer_handle_pwm.Init.Prescaler = 108 - 1;
	timer_handle_pwm.Init.Period = 100 - 1;

	HAL_TIM_PWM_Init(&timer_handle_pwm);
}

void init_pwm()
{
	pwm_config.Pulse = 0;
	pwm_config.OCMode = TIM_OCMODE_PWM1;
	pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer_handle_pwm, &pwm_config, TIM_CHANNEL_1);
}

void init_user_button()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	user_button.Pin = GPIO_PIN_11;
	user_button.Mode = GPIO_MODE_IT_RISING;
	user_button.Pull = GPIO_NOPULL;
	user_button.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOI, &user_button);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_timer();
	init_pwm_timer();
	init_pwm();
	init_led();
	init_user_button();
	BSP_LED_Init(LED1);


	HAL_TIM_PWM_Start(&timer_handle_pwm, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(&timer_handle);

	while (1) {
		__HAL_TIM_SET_COMPARE(&timer_handle_pwm, TIM_CHANNEL_1, duty_cycle);
	}
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    /* this is the place for the user code */
	if (duty_cycle < 90) {
		duty_cycle += 10;
	}
}

void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *timer_handle)
{
	if (duty_cycle > 0) {
		duty_cycle--;
	}
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
