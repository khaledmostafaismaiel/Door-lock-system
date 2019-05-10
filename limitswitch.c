/*
 * limitswitch.c
 *
 * Created: 4/22/2019 3:41:23 AM
 *  Author: Khaled's Lap
 */

#define F_CPU 8000000UL
#include "limitswitch.h"

void open_limit_switch_checker(void)
{

	PORTB |=  (1 << OPEN_LIMIT_SWITCH_PIN);

	if ((PINB &  (1 << OPEN_LIMIT_SWITCH_PIN)) == 0)
	{
		++doorOpencounter;
	}
	else
	{
		doorOpencounter = 0;
	}

	if (doorOpencounter >= NUM_OF_LIMIT_SWITCH_SAMPLING)
	{
		stop_opening();
	}
}

void close_limit_switch_checker(void)
{

	PORTB |=  (1 << CLOSE_LIMIT_SWITCH_PIN);

	if ((PINB &  (1 << CLOSE_LIMIT_SWITCH_PIN)) == 0)
	{
		++doorclosecounter;
	}
	else
	{
		doorclosecounter = 0;
	}

	if (doorclosecounter >= NUM_OF_LIMIT_SWITCH_SAMPLING)
	{
		stop_closing();
	}
}