#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED
#include <util/delay.h>
#include "LCD_CONF.h"
#include "helper.h"

#define NEXT_LINE 0XC0
#define FIRST_LINE 0X80

#define Enable 0xFF
#define Disable 0x00

void LCD_INIT(void);
void LCD_Commands(uint8_t group, uint8_t Command);
void LCD_Write_Char(uint8_t group, uint8_t Data);
void LCD_Write_String(uint8_t group, uint8_t *Data);
void LCD_Clear(uint8_t group);
void LCD_Cursor_GOTO(uint8_t group, uint8_t x, uint8_t y);
void Check_Line(uint8_t group);
void Shift_Right(uint8_t group);
void Shift_Left(uint8_t group);
void DeleteChar(uint8_t group);
void LCD_Constrast_ON(uint8_t group);
void LCD_Constrast_OFF(uint8_t group);

#endif
