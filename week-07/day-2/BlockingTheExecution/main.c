#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/*
 * Make the green user LED flash with a frequency of 2 Hz but do not start until the blue user
 * button is pushed. Once it is pushed the LED should be blinking forever.
 */

int main(void)
{
    HAL_Init();
    BSP_LED_Init(LED1);
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
    int activated_once = 0;
    
    while(1){
        if(BSP_PB_GetState(BUTTON_KEY) == 1) {
            activated_once = 1;
        }
        if(activated_once == 1) {
            BSP_LED_Toggle(LED1);
            HAL_Delay(250);
        }
    }
}
