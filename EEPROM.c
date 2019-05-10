/*
 * EEPROM.c
 *
 * Created: 4/1/2019 11:29:46 PM
 *  Author: Khaled's Lap
 */
#define F_CPU 8000000UL

#include "EEPROM.h"

void EEPROM_write(unsigned int uiAddress, uint8_t ucData)
{
	/* Wait for completion of previous write */
	while (EECR & (1 << EEWE))
		;
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1 << EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1 << EEWE);
}

uint8_t EEPROM_read(unsigned int uiAddress)
{
	/* Wait for completion of previous write */
	while (EECR & (1 << EEWE))
		;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1 << EERE);
	/* Return data from data register */
	return EEDR;
}
