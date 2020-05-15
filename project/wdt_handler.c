#include <msp430.h>
#include <libTimer.h>
#include "hardware.h"
#include "stateMachine.h"
//#include "visuals.h"

void wdt_handler()
{
  if(switch_state_changed){
    //    and_sr(~0x18);
    // static short count = 0;
    P1OUT |= LED_GREEN;		      /**< Green LED on when cpu on */
    //count ++;
    
    state_machine( s_pressed );
    
  }
  //s_pressed = 0;
  or_sr(0x18);
  P1OUT &= ~LED_GREEN;		    /**< Green LED off when cpu off */
}
