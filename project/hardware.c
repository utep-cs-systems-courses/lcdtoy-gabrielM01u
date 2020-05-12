#include <msp430.h>
#include "libTimer.h"
#include "hardware.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


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

