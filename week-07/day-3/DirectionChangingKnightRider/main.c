#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stdint.h"

//Modify the Knight Rider project, to work in a circular mode.


void init_pins()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;     /* GPIOI clock enable */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    // Init (F 7)
    GPIOF->MODER |= (GPIO_MODER_MODER7_0);   /* configure PI1 in output mode */
    GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_7);    /* ensure push pull mode selected default */
    GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR7); /* ensure maximum speed setting (even though it is unnecessary) */
    GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR7);   /* ensure all pull up pull down resistors are disabled */

    // Init (F 8)
    GPIOF->MODER |= (GPIO_MODER_MODER8_0);   /* configure PI1 in output mode */
    GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_8);    /* ensure push pull mode selected default */
    GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8); /* ensure maximum speed setting (even though it is unnecessary) */
    GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR8);   /* ensure all pull up pull down resistors are disabled */

    // Init (F 9)
    GPIOF->MODER |= (GPIO_MODER_MODER9_0);   /* configure PI1 in output mode */
    GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9);    /* ensure push pull mode selected default */
    GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9); /* ensure maximum speed setting (even though it is unnecessary) */
    GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR9);   /* ensure all pull up pull down resistors are disabled */

    // Init (F 10)
    GPIOF->MODER |= (GPIO_MODER_MODER10_0);   /* configure PI1 in output mode */
    GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);    /* ensure push pull mode selected default */
    GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10); /* ensure maximum speed setting (even though it is unnecessary) */
    GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10);   /* ensure all pull up pull down resistors are disabled */

    //GPIOB->MODER |= (GPIO_MODER_MODER4);

}

int main(void)
{
	HAL_Init();
	init_pins();

	uint32_t red_led = (1 << 6);
	uint32_t user_button = (1 << 4);
	int button_down = 0;
	int direction = 0;

	while (1) {
		if ((GPIOB->IDR & user_button) && button_down == 0) {
			button_down = 1;
			HAL_Delay(100);
		} else if (!(GPIOB->IDR & user_button)) {
			button_down = 0;
		}

		if (button_down){
			direction++;
		}

		if (direction % 2 == 0) {
			red_led <<= 1;
			GPIOF->BSRR = red_led;
			HAL_Delay(250);
			GPIOF->BSRR = red_led << 16;
			HAL_Delay(250);

			if (red_led == 1024) {
				red_led = (1 << 6);
			}
		} else {
			red_led >>= 1;
			GPIOF->BSRR = red_led;
			HAL_Delay(250);
			GPIOF->BSRR = red_led << 16;
			HAL_Delay(250);

			if (red_led == 128) {
				red_led = (1 << 11);
			}
		}
	}
}

