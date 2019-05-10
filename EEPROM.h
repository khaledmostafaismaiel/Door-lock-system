/*
 * EEPROM.h
 *
 * Created: 4/1/2019 11:30:04 PM
 *  Author: Khaled's Lap
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include "helper.h"

uint8_t firstKey;
uint8_t secondKey;
uint8_t thirdKey;
uint8_t fourthKey;
uint8_t fifthKey;
uint8_t sixthKey;

/*
*Function: EEPROM_write
*
*used to write value in the eeprom
*
*unsigned int uiAddress -->this is the address in the eeprom
*
*uint8_t ucData -->this is the data which will write in a spacific address
*
*
*return void
*/
void EEPROM_write(unsigned int uiAddress, uint8_t ucData);

/*
*Function: EEPROM_read
*
*used to read vaue from the eeprom
*
*return the value from the eeprom
*/
uint8_t EEPROM_read(unsigned int uiAddress);

#endif /* EEPROM_H_ */