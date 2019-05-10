/*
 * interrupt.c
 *
 * Created: 4/3/2019 2:10:13 AM
 *  Author: Khaled's Lap
 */

#define F_CPU 8000000UL

#include "interrupt.h"

void set_int0_init(void)
{
	GICR |= (1 << INT0);

	MCUCR |= (1 << ISC00);

	sei();
}

void reset_int0_init(void)
{
	GICR &= ~(1 << INT0);
}

ISR(INT0_vect)
{

	if (status == 1)
	{
		reset_ultra_timer1();
		pulse = TCNT1;
		TCNT1 = 0;
		status = 0;
	}
	if (status == 0)
	{
		set_ultra_timer1();
		status = 1;
	}
}
