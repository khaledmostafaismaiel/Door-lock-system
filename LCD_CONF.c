#define F_CPU 8000000UL

#include "LCD_CONF.h"

/*  Display - Function_set - LCD_control_RS - LCD_control_RW - LCD_control_E */
const LCD_Type LCDgroups[NUM_OF_LCD_GROUPS] =
	{
		{DISPLAY_ON, FOUR_BIT | TWO_LINE | FONT_EIGHT, LCDCONTROL_RS0, LCDCONTROL_RW0, LCDCONTROL_E0, LCDDATA0, LCDPOWER0} //LCD0
};
