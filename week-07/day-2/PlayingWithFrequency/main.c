/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
			

int main(void)
{
	HAL_Init();
	BSP_LED_Init(LED1);
	int counter = 0;
	int set_frequency = 0;

	while(1){
		if (set_frequency % 6 == 0){
				BSP_LED_On(LED1);
				HAL_Delay(250);
				BSP_LED_Off(LED1);
				HAL_Delay(250);
				counter++;
				if(counter == 3) {
					counter = 0;
					set_frequency++;
				}
		}
		if (set_frequency % 6 == 1) {
				BSP_LED_On(LED1);
				HAL_Delay(500);
				BSP_LED_Off(LED1);
				HAL_Delay(500);
				counter++;
				if(counter == 3) {
					counter = 0;
					set_frequency++;
				}

		}
		if (set_frequency % 6 == 2) {
				BSP_LED_On(LED1);
				HAL_Delay(1000);
				BSP_LED_Off(LED1);
				HAL_Delay(1000);
				counter++;
				if(counter == 3) {
					counter = 0;
					set_frequency++;
				}

		}
		if (set_frequency % 6 == 3) {
				BSP_LED_On(LED1);
				HAL_Delay(2000);
				BSP_LED_Off(LED1);
				HAL_Delay(2000);
				counter++;
				if(counter == 3) {
					counter = 0;
					set_frequency++;
				}
		}
		if (set_frequency % 6 == 4) {
				BSP_LED_On(LED1);
				HAL_Delay(1000);
				BSP_LED_Off(LED1);
				HAL_Delay(1000);
				counter++;
				if(counter == 3) {
					counter = 0;
					set_frequency++;
				}
		}
		if (set_frequency % 6 == 5) {
				BSP_LED_On(LED1);
				HAL_Delay(500);
				BSP_LED_Off(LED1);
				HAL_Delay(500);
				counter++;
				if(counter == 3) {
					counter = 0;
					set_frequency++;
				}
		}
	}
}
