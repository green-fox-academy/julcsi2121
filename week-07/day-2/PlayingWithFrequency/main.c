#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/*
 * Flash the user LED with a changing frequency.
 * The frequency should change every 3 periods (on and off) and the steps should be the following:
 * 0.5 Hz ➡ 1 Hz ➡ 2 Hz ➡ 4 Hz ➡ 2 Hz ➡ 1 Hz ➡ 0.5 Hz ➡ ...
 */


int main(void)
{
    HAL_Init();
    BSP_LED_Init(LED1);
    int state = 0;
    int set_frequency = 2000;
    
    while(1){
        for (int i = 0; i < 6; i++) {
            BSP_LED_Toggle(LED1);
            HAL_Delay(set_frequency);
        }
        if (state == 0) {
            set_frequency /= 2;
            if (set_frequency == 250) {
                state = 1;
            }
        } else {
            set_frequency *= 2;
            if (set_frequency == 2000) {
                state = 0;
            }
        }
    }
}
