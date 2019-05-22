#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stdint.h"

/*
 * If you are done with wiring the circuit, start flashing your LED-s at once with 1 Hz,
 * using bit manipulations in the GPIO registers. (don't use the HAL provided functions)
 */


void init_pins()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;     /* GPIOI clock enable */

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

}

int main(void)
{
	HAL_Init();
	init_pins();


	uint32_t red_led_7 = (1 << 7);
	uint32_t red_led_8 = (1 << 8);
	uint32_t red_led_9 = (1 << 9);
	uint32_t red_led_10 = (1 << 10);

	while (1) {
	    GPIOF->BSRR = red_led_7;
	    GPIOF->BSRR = red_led_8;
		GPIOF->BSRR = red_led_9;
		GPIOF->BSRR = red_led_10;
	    HAL_Delay(500);
	    GPIOF->BSRR = red_led_7 << 16;
	    GPIOF->BSRR = red_led_8 << 16;
	    GPIOF->BSRR = red_led_9 << 16;
	    GPIOF->BSRR = red_led_10 << 16;
	    HAL_Delay(500);
	    }
}

