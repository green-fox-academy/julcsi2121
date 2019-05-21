#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/*
 * Toggle the green user LED with the blue user button.
 * A push should turn on the LED if it is turned off and
 * it should turn the LED off if it is turned on.
 */


int main(void)
{
    HAL_Init();
    BSP_LED_Init(LED1);
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
    int button_down = 0;
    
    while(1){
        if (BSP_PB_GetState(BUTTON_KEY) == 1 && button_down == 0) {
            button_down = 1;
            BSP_LED_Toggle(LED1);
        }
        if (BSP_PB_GetState(BUTTON_KEY) == 0) {
            button_down = 0;
        }
    }
}
