#include <msp430.h>
#include "libTimer.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <sr.h>
#include "hardware.h"
#include "stateMachine.h"

int state;

int main(void){
    configureClocks();
    led_init();
    buzzer_init();
    p2sw_init(1);
    lcd_init();
    enableWDTInterrupts();
    
    state = 0;

   for(;;) { 
    while (!redraw) { /**< Pause CPU if screen doesn't need updating */
      P1OUT &= ~LED_GREEN;    /**< Green led off witHo CPU */
      or_sr(0x10);	      /**< CPU OFF */
    }
    P1OUT |= LED_GREEN;       /**< Green led on when CPU on */

  }
}

/** Watchdog timer interrupt handler. 15 interrupts/sec */
void wdt_c_handler()
{
  static short count = 0;
  P1OUT |= LED_GREEN;		      /**< Green LED on when cpu on */
  count ++;
  if (count == 15) {
    if (p2sw_read()))
      state_machine((state++ % 4)+1);//advance state
    count = 0;
  } 
  P1OUT &= ~LED_GREEN;		    /**< Green LED off when cpu off */
}