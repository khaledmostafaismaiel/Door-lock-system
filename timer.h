/*
 * timer.h
 *
 * Created: 4/3/2019 3:21:26 AM
 *  Author: Khaled's Lap
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupt.h"
#include "motor.h"
#include "limitswitch.h"
#include "helper.h"

#define TIMER0_HALF_SECOND 25
#define TEST_LED_PIN 6

int timer0extra_time;

uint8_t timer1Aextra_time;
uint8_t timer0_done;

float wait_in_half_second;

extern uint8_t doorOpencounter;
extern uint8_t doorclosecounter;
extern uint8_t ultra_flag;
extern uint8_t potentiometer_flag;
extern uint8_t keypad_flag;
extern uint8_t limit_switch_flag;
extern uint8_t duty_cycle;
extern uint8_t timer1_wait_for;


/*
*Function: timer0_init
*
*used to initiat timer0 and i used this timer to set the periodiity flages
*
*return void
*/
void timer0_init(void);




/*
*Function: set_pwm_timer2_init
*
*used to set the pwm duty cycle
*
*return void
*/
void set_pwm_timer2_init(void);



/*
*Function: reset_pwm_timer2_init
*
*used to reset the timer which is used for the pwm
*
*return void
*/
void reset_pwm_timer2_init(void);





/*
*Function: reset_ultra_timer1
*
*used to reset the timer which is used for calculate the time of hight level pulse 
*
*return void
*/
void reset_ultra_timer1(void);




/*
*Function: set_ultra_timer1
*
*used to init the timer 1 for ultrasonic sensor using
*
*return void
*/
void set_ultra_timer1(void);




/*
*Function: set_counter_timer1A_init
*
*used to count seconds
*
*return void
*/
void set_counter_timer1A_init(void);



/*
*Function: reset_counter_timer1A_init
*
*used to reset the init of timer 1 as acounter
*
*return void
*/
void reset_counter_timer1A_init(void);

#endif /* TIMER_H_ */

