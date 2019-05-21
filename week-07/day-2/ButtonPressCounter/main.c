#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/*
 * Your program should start in a waiting state. After the user presses (and releases)
 * the button 5 times, turn on the user LED and put your program into a state
 * in which it is not reacting to any further button presses.
 */


int main(void)
{
    HAL_Init();
    BSP_LED_Init(LED1);
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
    int button_down = 0;
    int number_of_button_presses = 0;
    
    while(1){
        if(BSP_PB_GetState(BUTTON_KEY) == 1) {
            button_down = 1;
        }
        
        if(BSP_PB_GetState(BUTTON_KEY) == 0 && button_down == 1) {
            button_down = 0;
            number_of_button_presses++;
            if (number_of_button_presses == 5) {
                BSP_LED_On(LED1);
            }
        }
    }
}
