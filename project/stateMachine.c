/* State Machine: based on what swtich is pressed, will allow the msp430
   to produce sounds and lights.

   This function is called in the switch interrupt handler.
*/
#include <math.h>
//#include "visuals.h"

static int redraw = 0;

void state_machine(int s){
    
    switch(s){
        case 1:
            state_1();
            
            break;
        case 2:
            state_2();
            enable_green();
            
            break;
        case 3:
            state_3();
            
            break;
        case 4:
            state_4();
            
            break;
        default:
            break;
    }
}
/**
 * States
 **/

//State 1: turns green on and plays buzzer for 125 cycles, then turns everything off
void state_1(){
   int timer = 0;
    
    while(timer++ != 125){
        enable_green();
        led_update();
        buzzer_set_period(2200);
        redraw = 1;
    }
    disable_green();
    buzzer_off();
    led_update();
}

//State 1: turns red on and plays buzzer with a different tone for 500 cycles, then turns everything off
void state_2(){
    int timer = 0;

    while(timer++ != 500){
        enable_red();
        led_update();
        buzzer_set_period(1400);
    }
    disable_red();
    buzzer_off();
    led_update();
}

//State 3: turns green on and buzzer for 125 cycles, turns everything off, then turns on red and buzzard for 500 cycles, then turns everything off
void state_3(){
    state_1();
    state_2();
}

//State 4: turns red on and buzzer for 500 cycles, turns everything off, then does the same things as in State 3
void state_4(){
    state_2();
    state_3();
}
