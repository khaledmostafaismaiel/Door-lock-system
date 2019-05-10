/*
 * ports_init.c
 *
 * Created: 3/31/2019 2:32:58 AM
 *  Author: Khaled's Lap
 */

#define F_CPU 8000000UL

#include "init.h"

#include "timer.h"
#include "EEPROM.h"
#include "interrupt.h"

void ports_init(void)
{
	DDRA = 0x00;
	DDRB = 0x00;
	DDRC = 0x00;
	DDRD = 0x00;
}
void all_init(void)
{

	ports_init();
	timer0_init();
	GPIO_Init();
	LCD_INIT();
	adc_init();
}

