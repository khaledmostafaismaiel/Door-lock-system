/*
 * ADC.c
 *
 * Created: 4/6/2019 1:46:16 AM
 *  Author: Khaled's Lap
 */

#define F_CPU 8000000UL

#include "ADC.h"

void adc_init(void)
{

	ADMUX = (1 << REFS0);
	ADCSRA |= (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
	sei();
}

void start_conversion()
{

	ADCSRA |= (1 << ADSC);
}

unsigned short adc_read(void)
{

	start_conversion();
	while ((ADCSRA & (1 << ADIF)) == 0)
		;
	ADCSRA |= (1 << ADIF);

	return ADC;
}
