#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stdint.h"

/*
 * Your program should start in a waiting state. After the user presses
 * (and releases) the button 5 times, turn on the user LED and put your program
 * into a state in which it is not reacting to any further button presses.
 */

volatile int button_presses = 0;

void init_pins()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();
	GPIO_InitTypeDef led;

	led.Pin = GPIO_PIN_1;
    led.Mode = GPIO_MODE_OUTPUT_PP;
    led.Speed = GPIO_SPEED_FAST;
    led.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOI, &led);
}

void init_button()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();
	GPIO_InitTypeDef button;

	button.Pin = GPIO_PIN_11;
    button.Mode = GPIO_MODE_IT_RISING;;
    button.Speed = GPIO_SPEED_FAST;
    button.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOI, &button);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

int main(void)
{
	HAL_Init();
	init_pins();
	init_button();


	while (1) {
	}
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	button_presses++;
	if (button_presses == 5) {
		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);
	}
}


