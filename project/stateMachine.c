/* State Machine: based on what swtich is pressed, will allow the msp430
   to produce sounds and lights.

   This function is called in the switch interrupt handler.
*/
#include <math.h>
#include <msp430.h>
#include "hardware.h"

#include "states.h"

int redraw = 0;
int finished = 0;

void state_machine(int s){
    
    switch(s){
        case 1:
            state_1();
            //switch_state_changed = 0;
            break;
        case 2:
            state_2();
            enable_green();
            //switch_state_changed = 0;
            break;
        case 3:
            state_3();
            //switch_state_changed = 0;
            break;
        case 4:
            state_4();
            //switch_state_changed = 0;
            break;
        default:
            break;
    }
}
