#ifndef KEYPAD_H_INCLUDED
#define KEYPAD_H_INCLUDED

#define DEBUGE 0

#include "GPIO.h"
#include <avr/io.h>
#include "LCD_CONF.h"
#include "avr/delay.h"
#include "timer.h"
#include "helper.h"

#define wait_for_3sec_timer1 60
#define NUM_OF_ROWS 4
#define NUM_OF_COLOMS 4
#define NOT_PRESSED_LETTER 'M'

uint8_t col, row;
uint8_t is_hash;
uint8_t hash_checker;

extern uint8_t is_long_pressed;

/*
*Function: get_pressed_key
*
*used to check if the keypad is pressed or not
*
*return 'M' in case of the keypad is not pressed
*return the key which is pressed
*/
uint8_t get_pressed_key(void);

/*
*Function: what_key
*
*used to return the key which is pressed
*
*return the key which is pressed
*/
uint8_t what_key(void);

#endif // KEYPAD_H_INCLUDED
