#ifndef LCD_TYPE_H_
#define LCD_TYPE_H_
#include "helper.h"

/*Configuration							Address							Execution Time(max) (when fcp or fOSC is 270 kHz)*/

/*Clear display*/
#define CLEAR_DISPLAY 0X01

/*Return home*/
#define RETURN_HOME 0X02 /*1.52 ms*/

/*Entry mode set*/
#define MODE_SET_DECREMENT_NOSHIFT 0X04 /*37 �s */
#define MODE_SET_DECREMENT_SHIFT 0X05   /*37 �s */
#define MODE_SET_INCREMENT_NOSHIFT 0X06 /*37 �s */
#define MODE_SET_INCREMENT_SHIFT 0X07   /*37 �s */

/*Display on/off control*/
#define DISPLAY_ON 0X0C  /*37 �s */
#define DISPLAY_OFF 0X08 /*37 �s */

/*Cursor or Display Shift*/
#define MODE_Cursor_SHIFTLEFT 0X10   /*37 �s */
#define MODE_Cursor_SHIFTRIGHT 0X14  /*37 �s */
#define MODE_DISPLAY_SHIFTLEFT 0X18  /*37 �s */
#define MODE_DISPLAY_SHIFTRIGHT 0X1C /*37 �s */

/*Function set*/
/*4 OR 8 bits*/
#define FOUR_BIT 0X20  /*37 �s */
#define EIGHT_BIT 0X30 /*37 �s */
/*NUMBER OF LINES*/
#define ONE_LINE 0X20 /*37 �s */
#define TWO_LINE 0X28 /*37 �s */
/*character font*/
#define FONT_EIGHT 0X20 /*37 �s */
#define FONT_TEN 0X24   /*37 �s */

typedef struct
{
	//u8 Entry_mode;
	uint8_t Display;
	//uint8_t Cursor_or_Display;
	uint8_t Function_set;
	uint8_t LCD_control_RS;
	uint8_t LCD_control_RW;
	uint8_t LCD_control_E;
	uint8_t LCD_DATA;
	uint8_t LCD_Power;
} LCD_Type;

#endif /* LCD_TYPE_H_ */