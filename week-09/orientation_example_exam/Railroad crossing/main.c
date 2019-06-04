#include "stm32f7xx.h"
#include "stm32746g_discovery.h"


typedef enum {
	OPEN, SECURING, SECURED, OPENING
}state_t;

TIM_HandleTypeDef tim2_handle;

void init_tim2(void);
void init_user_button(void);
void SystemClock_Config(void);
void Error_Handler(void);

state_t state = OPEN;
volatile int counter = 0;


int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_tim2();
	init_user_button();
	BSP_LED_Init(LED1);

	HAL_TIM_Base_Start_IT(&tim2_handle);

	while(1)  {
		switch (state) {
		case OPEN: {
			__HAL_TIM_SET_COMPARE(&tim2_handle, 1, 0);
			__HAL_TIM_SET_AUTORELOAD(&tim2_handle, 5000);


			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
			break;
		}
		case SECURING: {
			__HAL_TIM_SET_COMPARE(&tim2_handle, 1, 0);
			__HAL_TIM_SET_AUTORELOAD(&tim2_handle, 2500);


			HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
			break;
		}
		case SECURED: {
			__HAL_TIM_SET_COMPARE(&tim2_handle, 1, 0);
			__HAL_TIM_SET_AUTORELOAD(&tim2_handle, 5000);


			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
			break;
		} case OPENING: {
			__HAL_TIM_SET_COMPARE(&tim2_handle, 1, 0);
			__HAL_TIM_SET_AUTORELOAD(&tim2_handle, 2500);


			HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
			break;
		}
		}
	}
}

void init_user_button(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE();
	GPIO_InitTypeDef button;

	button.Pin = GPIO_PIN_11;
	button.Mode = GPIO_MODE_IT_RISING;
	button.Speed = GPIO_SPEED_FAST;
	button.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOI, &button);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (state == OPEN) {
		state = SECURING;
	} else if (state == SECURED) {
		state = OPENING;
	}

}

void init_tim2(void)
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	tim2_handle.Instance = TIM2;
	tim2_handle.Init.Prescaler = 10800 - 1; // 0.1ms
	tim2_handle.Init.Period = 5000 - 1;  // 0,5s
	tim2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim2_handle);
	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&tim2_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *timer_handle_counter)
{
	if (timer_handle_counter->Instance == TIM2) {
		//toggle led
		if (state == SECURED) {
			BSP_LED_Off(LED1);
		} else {
			BSP_LED_Toggle(LED1);
		}
		//state-change if needed
		if (state == SECURING || state == OPENING) {
			counter++;

			if (state == SECURING && counter == 10) {
				counter = 0;
				state = SECURED;
			} else if (state == OPENING && counter == 20) {
				counter = 0;
				state = OPEN;
			}
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
