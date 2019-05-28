#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

TIM_HandleTypeDef timer_handle;
TIM_OC_InitTypeDef pwm_config;
GPIO_InitTypeDef pin15a;

void SystemClock_Config(void);

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
	__HAL_RCC_TIM2_CLK_ENABLE();

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 108 - 1; // 0.001ms
	timer_handle.Init.Period = 100 - 1;  // 0.1ms

	HAL_TIM_PWM_Init(&timer_handle);
}

void init_pwm()
{
	pwm_config.Pulse = 0;
	pwm_config.OCMode = TIM_OCMODE_PWM1;
	pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer_handle, &pwm_config, TIM_CHANNEL_1);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_timer();
	init_pwm();
	init_led();
	HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);


	while (1) {
		for (int i = 0; i < 100; ++i) {
			__HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, i);
			HAL_Delay(50);
		}

		for (int i = 100; i > 0; --i) {
			__HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, i);
			HAL_Delay(50);
		}
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
