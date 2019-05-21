#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/*
 * Make the green user LED flash with a frequency of 4 Hz while the blue user pushbutton
 * is pressed. If the button is not pressed the LED should not be lit.
 */


int main(void)
{
    HAL_Init();
    BSP_LED_Init(LED1);
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
    
    while(1){
        if(BSP_PB_GetState(BUTTON_KEY) == 1) {
            BSP_LED_On(LED1);
            HAL_Delay(125);
            BSP_LED_Off(LED1);
            HAL_Delay(125);
        }
    }
}
