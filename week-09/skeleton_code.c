#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* user-led
 * user button - polling and interrupt
 * gpio output led
 * external push button - polling and interrupt
 * rng
 * base timer - polling and interrupt
 * pwm timer
 * uart
 * rgb led - total
 */

void user_led_handle()    //LED1 - csak a led neve, I1
{
	//BSP-s very basic függvények
	BSP_LED_Init(LED1);   //led inicializálása
	BSP_LED_Off(LED1);   //led off
	BSP_LED_On(LED1);     //led on
	BSP_LED_Toggle(LED1);    //átkapcsolás az ellenkezõ állapotra

	//HAL inicializálás
	__HAL_RCC_GPIOI_CLK_ENABLE();
	GPIO_InitTypeDef led;

	led.Pin = GPIO_PIN_1;
	led.Mode = GPIO_MODE_OUTPUT_PP;
	led.Speed = GPIO_SPEED_FAST;
	led.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOI, &led);

	//egyéb komment, hogy a hal_gpio write, read stb. függvények itt is mûködnek, csak rá kell konfigurálni erre a pinre
}

void user_button_handle()   //I11
{
	//BPS-s very basic függvények
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	BSP_PB_GetState(BUTTON_KEY);

	//HAL inicializálás
	__HAL_RCC_GPIOI_CLK_ENABLE();
	GPIO_InitTypeDef button;

	button.Pin = GPIO_PIN_11;
    button.Mode = GPIO_MODE_IT_RISING;     //IT nélkül asszem input mode, de így úgyse kell majd soha használni
    button.Speed = GPIO_SPEED_FAST;
    button.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOI, &button);

    //Interrupt
    //Init függvénybe:
    button.Mode = GPIO_MODE_IT_RISING; //!!!!!!!!!!!!!!!!!!
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

    //IRQ handler:
    void EXTI15_10_IRQHandler()
    {
    	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
    }

    //Callback függvény:
    void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
    {
    	//user kód helye
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
