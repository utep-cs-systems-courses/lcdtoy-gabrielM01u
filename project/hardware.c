#include <msp430.h>
#include "libTimer.h"
#include "hardware.h"


unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

int s_pressed;

void led_init()
{
  P1DIR |= LEDS;
  led_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  }
}

/**
 * turns on and off green and red lights
 **/
void enable_green()
{
  green_on = 1;
  led_changed = 1;
}

void disable_green()
{
  green_on = 0;
  led_changed = 1;
}

void enable_red()
{
  red_on = 1;
  led_changed = 1;
}

void disable_red()
{
  red_on = 0;
  led_changed = 1;
}

//initializes buzzer
void buzzer_init()
{
    timerAUpmode();
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		
}

//sets tone/sound of buzzer and activates it
void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;
}

void buzzer_off(){
  CCR0 = 0;
  CCR1 = 0;
}

/**
 char sx_down:
   boolean (0 or 1) indicating if a switch is pressed
**/
char s1_down;
char s2_down;
char s3_down;
char s4_down;

//initializes the switches
void
switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
}

static char
switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val & ~SWITCHES);
  return p2val;
}

/*  interrupt handler for second board  */
void
switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  s1_down = (p2val & S1) ? 0:1;
  s2_down = (p2val & S2) ? 0:1;
  s3_down = (p2val & S3) ? 0:1;
  s4_down = (p2val & S4) ? 0:1;
  switch_state_changed = 1;

  if(s1_down) s_pressed = 1;
  else if(s2_down) s_pressed = 2;
  else if(s3_down) s_pressed = 3;
  else if(s4_down) s_pressed = 4;
}

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
} 

