#include <math.h>
#include <msp430.h>
#include "hardware.h"
//#include "visuals.h"
/**
 * States
 **/

//State 1: turns green on and plays buzzer for 125 cycles, then turns everything off
void state_1(){
   int timer = 0;
    finished = 0;
    while(timer++ != 50000){
        enable_green();
        led_update();
        buzzer_set_period(2200);
        //redraw = 1;
    }
    disable_green();
    buzzer_off();
    led_update();
    finished = 1;
}

//State 1: turns red on and plays buzzer with a different tone for 500 cycles, then turns everything off
void state_2(){
    int timer = 0;
    finished = 0;
    while(timer++ != 50000){
        enable_red();
        led_update();
        buzzer_set_period(1400);
    }
    disable_red();
    buzzer_off();
    led_update();
    finished = 1;
}

//State 3: turns green on and buzzer for 125 cycles, turns everything off, then turns on red and buzzard for 500 cycles, then turns everything off
void state_3(){
    int timer = 0;
    finished = 0;
    while(timer++ != 100000){
        enable_red();
        led_update();
        buzzer_set_period(1400);
    }
    disable_red();
    led_update();
    while(timer++ != 200000){
        enable_green();
        led_update();
        buzzer_set_period(2000);
    }
    disable_green();
    buzzer_off();
    led_update();
    finished = 1;
}

//State 4: turns red on and buzzer for 500 cycles, turns everything off, then does the same things as in State 3
void state_4(){
    int timer = 0;
    finished = 0;
    while(timer++ != 100000){
        enable_red();
        enable_green();
        led_update();
        buzzer_set_period(200);
    }
    while(timer++ != 200000){
        buzzer_set_period(1800);
    }
    disable_red();
    disable_green();
    buzzer_off();
    led_update();
    finished = 1;
}
