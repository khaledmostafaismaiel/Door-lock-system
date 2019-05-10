/*
 * timer.c
 *
 * Created: 4/3/2019 3:21:14 AM
 *  Author: Khaled's Lap
 */
#define F_CPU 8000000UL

#include "timer.h"

void timer0_init(void)
{

	// 20 msec limit switches
	// 50 msec potentiometer
	// 100 msec keypad
	// 200 msec ultrasensor

	TCCR0 |= (1 << WGM01) | (1 << CS00) | (1 << CS02);
	OCR0 = 79; // 0.010112 sec = 10.1 msec
	TIMSK |= (1 << OCIE0);
	sei();
	timer1_wait_for = 0;
}

ISR(TIMER0_COMP_vect)
{
	timer0extra_time++;
	if (timer0extra_time % 2 == 0)
	{
		limit_switch_flag = 1;
	}
	if (timer0extra_time % 5 == 0)
	{
		potentiometer_flag = 1;
	}
	if (timer0extra_time % 10 == 0)
	{
		keypad_flag = 1;
		++timer1_wait_for;
	}
	if (timer0extra_time % 20 == 0)
	{
		timer0extra_time = 0;
		ultra_flag = 1;
	}
}

void set_pwm_timer2_init(void)
{

	//this timer used for making PWM

	TCCR2 = (1 << WGM20) | (1 << WGM21) | (1 << COM21) | (1 << CS20);
	DDRD |= (1 << FIRST_MOTOR_PIN);
}

void reset_pwm_timer2_init(void)
{

	TCCR2 = 0;
}

void set_ultra_timer1(void)
{

	TCCR1B = (1 << CS00);
}

void reset_ultra_timer1(void)
{

	TCCR1B = 0;
	TIMSK &= ~(1 << OCIE1A);
}

void reset_counter_timer1A_init(void)
{

	//50 msec

	TCCR1B = 0;
	sei();
	TIMSK &= ~(1 << OCIE1A);
	timer1Aextra_time = 0;
}

void set_counter_timer1A_init(void)
{

	//50 msec

	TCCR1B = (1 << WGM12) | (1 << CS10) | (1 << CS12);
	sei();
	OCR1A = 391; //Set number of clocks   .05 sec
	TIMSK |= (1 << OCIE1A);
	timer1Aextra_time = 0;
}

ISR(TIMER1_COMPA_vect)
{

	++timer1Aextra_time;
}
