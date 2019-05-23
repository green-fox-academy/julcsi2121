#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stdint.h"

/*
 * Make the green user LED flash with a frequency of 2 Hz but do not start
 * until the blue user button is pushed. Once it is pushed the LED should be
 * blinking forever.
 */


void init_pins()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();
	GPIO_InitTypeDef led;

	led.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7;
    led.Mode = GPIO_MODE_OUTPUT_PP;
    led.Speed = GPIO_SPEED_FAST;
    led.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOF, &led);
}

int main(void)
{
	HAL_Init();
	init_pins();

	uint16_t number = 0;

	while (1) {
		number = (number + 1);
		GPIOF->BSRR = number << 7;
		HAL_Delay(500);
		GPIOF->BSRR = number << 23;
		HAL_Delay(500);
	}

}


