#include <msp430.h>
#include <libTimer.h>
#include "hardware.h"
#include "stateMachine.h"
//#include "visuals.h"

void __interrupt_vec(WDT_VECTOR) WDT()
{
  if(switch_state_changed == 1){
    redraw = 0;
    and_sr(~0x18);
    P1OUT |= LED_GREEN;		      /**< Green LED on when cpu on */
    state_machine( s_pressed );
  }
  s_pressed = 0;
  or_sr(0x18);
  P1OUT &= ~LED_GREEN;		    /**< Green LED off when cpu off */
}
