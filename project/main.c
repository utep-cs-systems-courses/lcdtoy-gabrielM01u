#include <msp430.h>
#include "libTimer.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <sr.h>
#include "hardware.h"
#include "stateMachine.h"

int state;
int redraw = 1;

int main(void){
    configureClocks();
    led_init();
    buzzer_init();
    p2sw_init(15);
    lcd_init();
    enableWDTInterrupts();
    
    state = 0;
    clearScreen(COLOR_BLACK);
    
   for(;;) { 
    while (!redraw) { /**< Pause CPU if screen doesn't need updating */
      P1OUT &= ~LED_GREEN;    /**< Green led off witHo CPU */
      or_sr(0x10);	      /**< CPU OFF */
    }
    state_machine(state);
    P1OUT |= LED_GREEN;       /**< Green led on when CPU on */
    redraw = 0;
  }
}

/** Watchdog timer interrupt handler. 15 interrupts/sec */
void wdt_c_handler()
{
  static short counter = 0;
  P1OUT |= LED_GREEN;		      /**< Green LED on when cpu on */
  counter ++;
  if (counter == 15) {
    u_int switches = p2sw_read();

    if(switches & 1) state = 1;
    else if(switches & 2) state = 2;
    else if(sitches & 3) state = 3;
    else if(switches & 4) state = 4;
    else state = 0;
    
    }
    counter = 0;
    counter ++;
  } 
  P1OUT &= ~LED_GREEN;		    /**< Green LED off when cpu off */
}
