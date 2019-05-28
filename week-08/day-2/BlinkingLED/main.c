#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

TIM_HandleTypeDef timer_handle;

void SystemClock_Config(void);

void init_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 10800 * 5 - 1; // 0.1ms * 5 = 0.5ms
	timer_handle.Init.Period = 2000 - 1;  // 0.5ms * 2000 = 1s

	HAL_TIM_Base_Init(&timer_handle);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_timer();
	BSP_LED_Init(LED1);
	HAL_TIM_Base_Start(&timer_handle);
	uint16_t timer_value = 0;
	while (1) {
		timer_value = __HAL_TIM_GET_COUNTER(&timer_handle);

		if (timer_value == 0) {
			BSP_LED_On(LED1);
		} else if (timer_value == 1000) {
			BSP_LED_Off(LED1);
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
