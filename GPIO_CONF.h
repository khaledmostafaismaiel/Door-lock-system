
#ifndef GPIO_CONF_H_INCLUDED
#define GPIO_CONF_H_INCLUDED

#include "GPIO.h"
#include "helper.h"

/*Define groups*/
//#define Keypad				0
#define LCDCONTROL_RS0 0
#define LCDCONTROL_RW0 1
#define LCDCONTROL_E0 2
#define LCDPOWER0 3
#define LCDDATA0 4

/*#define ULTRASONICTRIGGER	5
#define LIMITSWITCH1		6
#define LIMITSWITCH2		7
#define  test				8
#define	MDIRECTION1			9
#define MDIRECTION2			10
#define tez					11*/

/*Define #of groups*/
#define NUM_OF_GROUPS 5

extern const GPIO_Type groups[NUM_OF_GROUPS];

#endif
