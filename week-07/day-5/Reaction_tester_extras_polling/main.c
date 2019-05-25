#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stdint.h"
#include "stdio.h"
#include "math.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "stm32f7xx_hal_rng.h"

RNG_HandleTypeDef rng_config;

int is_in_circle(TS_StateTypeDef touch, int radius, uint32_t circle_x, uint32_t circle_y);
void generate_circle_x(uint16_t radius, RNG_HandleTypeDef *rng_config, uint32_t *result);
void generate_circle_y(uint16_t radius, RNG_HandleTypeDef *rng_config, uint32_t *result);

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_lcd()
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_SetBackColor(0xFF80FFFF);
	BSP_LCD_SetTextColor(0xFF008080);
	BSP_LCD_SetFont(&Font20);

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
	//initialization
	HAL_Init();
	SystemClock_Config();
	init_rng();
	init_lcd();
	init_ts();

	//to monitor game phase & touches
	TS_StateTypeDef ts_state;
	int game_state = 1;
	int round = 0;

	//to handle circles
	uint16_t radius = 50;
	uint32_t circle_x = 0;
	uint32_t circle_y = 0;

	//to handle the last 10 round's average
	float average = 0;
	float result_data[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	//to measure time
	uint32_t random = 0;
	uint32_t start = 0;
	uint32_t stop = 0;

	//for printing out to the screen
	char num_to_array[50];

	//welcome message
	BSP_LCD_Clear(0xFF80FFFF);
	BSP_LCD_DisplayStringAt(0, 0, "Touch the screen to start the game", CENTER_MODE);


	while (1) {
		BSP_TS_GetState(&ts_state);

		if (ts_state.touchDetected && game_state == 1) {
			HAL_Delay(1000);

			//display some intermediate text
			BSP_LCD_Clear(0xFF80FFFF);
			BSP_LCD_DisplayStringAt(0, 0, "Next round coming", CENTER_MODE);
			HAL_Delay(2000);

			//waiting for 1-10 seconds
			BSP_LCD_Clear(0xFF80FFFF);
			BSP_LCD_DisplayStringAt(0, 0, "Wait...", CENTER_MODE);
			HAL_RNG_GenerateRandomNumber(&rng_config, &random);
			random = random % 10000 + 1;
			HAL_Delay(random);

			//drawing a randomly positioned circle & giving instructions to the user
			BSP_LCD_Clear(0xFF80FFFF);
			BSP_LCD_DisplayStringAt(0, 0, "Touch the circle NOW!", CENTER_MODE);
			generate_circle_x(radius, &rng_config, &circle_x);
			generate_circle_y(radius, &rng_config, &circle_y);
			BSP_LCD_FillCircle(circle_x, circle_y, radius);

			//start counting, reset touch detection, toggle the other phase of the game
			start = HAL_GetTick();
			ts_state.touchDetected = 0;
			game_state = 0;
		}

		else if (ts_state.touchDetected && game_state == 0 && is_in_circle(ts_state, radius, circle_x, circle_y) == 1) {
			HAL_Delay(1000);

			//getting the reaction time in seconds
			stop = HAL_GetTick();
			uint32_t time = stop - start;
			float total_time = time / 1000.0f;

			//counting last 10 round's average
			result_data[round % 10] = total_time;
			for (int i = 0; i < 10; ++i) {
				average += result_data[i];
			}
			average = average / (round + 1);   // TODO - DIVIDE BY ROUNDS OR TEN

			//printing the result
			BSP_LCD_Clear(0xFF80FFFF);
			sprintf(num_to_array, "Elapsed: %.2f, Average: %.2f", total_time, average);
			BSP_LCD_DisplayStringAt(0, 0, num_to_array, LEFT_MODE);

			//reset touch detection, game state, measure rounds elapsed
			ts_state.touchDetected = 0;
			game_state = 1;
			round++;
		}
	}
}

int is_in_circle(TS_StateTypeDef touch, int radius, uint32_t circle_x, uint32_t circle_y) {
	uint32_t x_pos = touch.touchX[0];
	uint32_t y_pos = touch.touchY[0];

	uint32_t x_diff = abs(x_pos - circle_x);
	uint32_t y_diff = abs(y_pos - circle_y);

	uint32_t result = pow(x_diff, 2) + pow(y_diff, 2);

	if (pow(radius, 2) > result) {
		return 1;
	}
	return 0;
}

void generate_circle_x(uint16_t radius, RNG_HandleTypeDef *rng_config, uint32_t *result)
{
	HAL_RNG_GenerateRandomNumber(rng_config, result);
	uint32_t available_pixels = BSP_LCD_GetXSize() - (2 * radius);
	*result = (*result % available_pixels) + radius;
}

void generate_circle_y(uint16_t radius, RNG_HandleTypeDef *rng_config, uint32_t *result)
{
	HAL_RNG_GenerateRandomNumber(rng_config, result);
	uint32_t available_pixels = BSP_LCD_GetYSize() - (2 * radius);
	*result = (*result % available_pixels) + radius;
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
