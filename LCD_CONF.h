/*
 * LCD_CONF.h
 *
 * Created: 3/28/2019 8:11:56 PM
 *  Author: Kemo
 */

#ifndef LCD_CONF_H_
#define LCD_CONF_H_
#include <avr/io.h>
#include "LCD_TYPE.h"
#include "GPIO_CONF.h"
#include "helper.h"

/*Define groups*/
#define LCD0 0

/*Define #of groups*/
#define NUM_OF_LCD_GROUPS 1

extern const LCD_Type LCDgroups[NUM_OF_LCD_GROUPS];

/*declaration array of registers addresses*/
extern const uint8_t Base_GPIO[PORT_NUMBER];

#endif /* LCD_CONF_H_ */