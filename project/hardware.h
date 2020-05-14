#ifndef hardware_included
#define hardware_included

//LEDs
#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

extern unsigned char red_on, green_on;
extern unsigned char led_changed;

void led_init();
void led_update();

void enable_green();
void disable_green();
void enable_red();
void disable_red();

//Buzzer
void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_off();

//Switches
void switch_init();
void switch_interrupt_handler();
static char switch_update_interrupt_sense();

extern char s1_down;
extern char s2_down;
extern char s3_down;
extern char s4_down;

extern char switch_state_changed;
extern int s_pressed;



#endif