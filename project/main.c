#include <msp430.h>
#include "libTimer.h"
#include "visuals.h"
#include "hardware.h"
#include "p2switches.h"


int main(void){
    configureclockes();
    led_init();
    buzzer_init();
    p2sw_init(15);
    lcd_init();
    enableWDTInterrupts();
    
    or_sr(0x18);
}