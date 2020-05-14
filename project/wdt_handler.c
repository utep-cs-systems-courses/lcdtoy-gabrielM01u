#include <msp430.h>
#include <libTimer.h>
#include "hardware.h"
#include "stateMachine.h"
#include "p2switches.hgit"
//#include "visuals.h"

void wdt_handler()
{
  if(swtich_pressed){
    and_sr(~0x18);
    static short count = 0;
    P1OUT |= GREEN_LED;		      /**< Green LED on when cpu on */
    //count ++;
    
      state_machine( p2sw_read()+1 );
    
  }
  swtich_pressed = 0;
  or_sr(0x18);
  P1OUT &= ~GREEN_LED;		    /**< Green LED off when cpu off */
}