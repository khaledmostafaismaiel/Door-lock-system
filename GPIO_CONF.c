

#define F_CPU 8000000UL

#include "GPIO_CONF.h"
#include "GPIO.h"

/* PORT_ID - Dir - Mask - PullUP */
const GPIO_Type groups[NUM_OF_GROUPS] =
	{
		//{ C , 0x00 , 0xFF , 0x00 },			//keypad
		{B, 1 << 1, 1 << 1, 0x00}, //LCD control RS
		{B, 1 << 2, 1 << 2, 0x00}, //LCD control RW
		{B, 1 << 3, 1 << 3, 0x00}, //LCD control E
		{B, 1 << 4, 1 << 4, 0x00}, //LCD power
		{A, 0XF0, 0XF0, 0x00}	  //LCD Data
								   /*	{ D , 1<<2 , 1<<2 , 0x00 },			//ultrasonic trigger
	{ D , 0Xff , 1<<6 , 0x00 },			//LimitSwitch1
	{ D , 0Xff , 1<<7 , 0x00 },			//LimitSwitch2
	{ D , 1<<7 , 1<<7 , 0x00 },			//test
	{ D , 1<<4 , 1<<4 , 0x00 },			//motor1
	{ D , 1<<5 , 1<<5 , 0x00 },			//motor2
	{ D , 0xff , 0xff , 0x00 }			//tez*/

};
