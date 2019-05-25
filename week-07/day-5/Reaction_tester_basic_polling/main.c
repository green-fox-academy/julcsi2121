#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stdint.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "stm32f7xx_hal_rng.h"

volatile RNG_HandleTypeDef rng_config;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_lcd()
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_SetBackColor(0xFF80FFFF);
	BSP_LCD_SetTextColor(0xFF008080);
	BSP_LCD_SetFont(&Font24);

}

void init_ts()
{
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
}

void init_rng()
{
	 __HAL_RCC_RNG_CLK_ENABLE();
	rng_config.Instance = RNG;
	HAL_RNG_Init(&rng_config);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_rng();
	init_lcd();
	init_ts();

	int game_state = 1;
	uint32_t start = 0;
	uint32_t elapsed = 0;
	uint32_t number = 2;
	char num_to_array[50];
	TS_StateTypeDef ts_state;
	BSP_LCD_DisplayStringAt(0, 0, "Touch the screen to start the game", CENTER_MODE);


	while (1) {
		BSP_TS_GetState(&ts_state);

		if (ts_state.touchDetected && game_state == 1) {
			HAL_Delay(1000);

			BSP_LCD_Clear(0xFF80FFFF);
			BSP_LCD_DisplayStringAt(0, 0, "Wait...", CENTER_MODE);
			HAL_RNG_GenerateRandomNumber(&rng_config, &number);
			number = number % 10000 + 1;
			HAL_Delay(number);

			start = HAL_GetTick();
			BSP_LCD_Clear(0xFF80FFFF);
			BSP_LCD_DisplayStringAt(0, 0, "Touch the screen NOW!", CENTER_MODE);
			ts_state.touchDetected = 0;

			game_state = 0;
		}

		else if (ts_state.touchDetected && game_state == 0) {
			HAL_Delay(1000);
			elapsed = HAL_GetTick();
			BSP_LCD_Clear(0xFF80FFFF);
			sprintf(num_to_array, "Elapsed: %lu", (elapsed - start) / 1000);
			BSP_LCD_DisplayStringAt(0, 0, num_to_array, LEFT_MODE);

			ts_state.touchDetected = 0;
			game_state = 1;
		}
	}
}


static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
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
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
