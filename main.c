//THIS PROGRAM IS A DOOR LOCK SYSTEM
//Created: 3/30/2019 5:22:23 PM
//AUTHOR : KHALED MOSTAFA

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "helper.h"
#include "Keypad.h"
#include "init.h"
#include "timer.h"
#include "interrupt.h"
#include "ADC.h"
#include "pwm.h"
#include "GPIO.h"
#include "LCD.h"
#include "LCD_CONF.h"
#include "LCD_TYPE.h"
#include "GPIO_CONF.h"
#include "GPIO_TYPES.h"
#include "ultrasonic.h"
#include "EEPROM.h"
#include "motor.h"
#include "limitswitch.h"


int main(void)
{
	

all_init();

	while (1)
	{

		run();
 
 
 
 
	}

return 0;
}
