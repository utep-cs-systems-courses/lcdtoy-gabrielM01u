#include <msp430.h>
#include "libTimer.h"
#include "visuals.h"
#include "hardware.h"


int main(void){
    configureClocks();
    led_init();
    buzzer_init();
    switch_init();
    lcd_init();
    enableWDTInterrupts();
    
    or_sr(0x18);
}