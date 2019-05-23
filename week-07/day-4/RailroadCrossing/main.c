#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stdint.h"

//flash the leds like a railroad crossing light


void init_pins()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();
	GPIO_InitTypeDef led;

	led.Pin = GPIO_PIN_10 | GPIO_PIN_9;
    led.Mode = GPIO_MODE_OUTPUT_PP;
    led.Speed = GPIO_SPEED_FAST;
    led.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOF, &led);
}

int main(void)
{
	HAL_Init();
	init_pins();


	while (1) {
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
		HAL_Delay(500);
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	}
}


