#include <math.h>
#include <msp430.h>
#include "hardware.h"


int redraw;

/**
 * States
 **/

//State 1: turns green on and plays buzzer for 125 cycles, then turns everything off
void state_1(){
   int timer = 0;
   s_pressed = 0;
 //   finished = 0;
    
    enable_green();
    led_update();
    buzzer_set_period(2200);
    clearScreen(COLOR_BLACK);
    drawRect(20,20);
//        drawSpecial(20,20);
    redraw = 0;
    while(timer++ != 350);
    disable_green();
    buzzer_off();
    led_update();
//    finished = 1;
}

//State 1: turns red on and plays buzzer with a different tone for 500 cycles, then turns everything off
void state_2(){
    int timer = 0;

//    finished = 0;
    
    enable_red();
    led_update();
    buzzer_set_period(1400);
    clearScreen(COLOR_BLACK);
    drawDaimond(10,10);
    while(timer++ != 3500);
    disable_red();
    buzzer_off();
    led_update();
//    finished = 1;
}

//State 3: turns green on and buzzer for 125 cycles, turns everything off, then turns on red and buzzard for 500 cycles, then turns everything off
void state_3(){
    int timer = 0;

//    finished = 0;
    while(timer++ != 30000){
        enable_red();
        led_update();
        buzzer_set_period(1400);

        clearScreen(COLOR_WHITE);
        drawSpecial(10,10);
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
//    finished = 1;
}

//State 4: turns red on and buzzer for 500 cycles, turns everything off, then does the same things as in State 3
void state_4(){
    int timer = 0;
//    finished = 0;
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
//    finished = 1;
}

void drawRect(int x_origin, int y_origin){
    int x,y;
 
    for(y=0; y<=50; y++){
        for(x=0;x<=50; x++)
        drawPixel(x+x_origin,y+y_origin, COLOR_CYAN);
    }
}

void drawDaimond(int x_origin, int y_origin){
    int x,y;
    
    for(y=0;y<=10;y++){
        for(x=0;x<=20;x++){
            drawPixel(x+x_origin,y+y_origin+40,COLOR_WHITE);
            drawPixel(-x+x_origin,y+y_origin+20,COLOR_WHITE);
            drawPixel(x+x_origin,-y+y_origin+40,COLOR_WHITE);
            drawPixel(-x+x_origin,-y+y_origin+20,COLOR_WHITE);
        }
    }
}

void drawPerson(int x_origin, int y_origin){
    int x,y;
    for(y=0; y<8; y++) {
        drawPixel(3+x_origin,y+y_origin,COLOR_FIREBRICK);
        drawPixel(2+x_origin,y+y_origin,COLOR_FIREBRICK);
    }//torso
    for(x=0; x<5; x++) drawPixel(x+x_origin, 0+y_origin, COLOR_FIREBRICK);//shoulder
    for(y=0; y<3;y++) {
        drawPixel(0+x_origin, y+y_origin, COLOR_FIREBRICK);//left arm
        drawPixel(1+x_origin, y+y_origin, COLOR_FIREBRICK);
        drawPixel(5+x_origin, y+y_origin, COLOR_FIREBRICK);//right arm
        drawPixel(4+x_origin, y+y_origin, COLOR_FIREBRICK);
    }
    for(x=0; x<3; x++) drawPixel(x+x_origin+1, 8+y_origin, COLOR_FIREBRICK);//waist
    for(y=0; y<3;y++) {
        drawPixel(1+x_origin, y+y_origin+8, COLOR_FIREBRICK);//left leg
        drawPixel(3+x_origin, y+y_origin+8, COLOR_FIREBRICK);//right leg
    }

}

void drawSpecial(int x_origin, int y_origin){
    int x,y;
    for(x=0; x<20; x++){
        for(y=0; y<5; y++) drawPixel(x+x_origin,y+y_origin+6,COLOR_FIREBRICK);
    }
    for(y=0; y<20; y++){
        for(x=0; x<5; x++) drawPixel(x+x_origin+6,y+y_origin+6,COLOR_FIREBRICK);
    }

}
