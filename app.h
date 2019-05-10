/*
 * app.h
 *
 * Created: 4/13/2019 4:04:23 AM
 *  Author: Khaled's Lap
 */

#ifndef APP_H_
#define APP_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "helper.h"
#include "Keypad.h"
#include "ADC.h"
#include "EEPROM.h"
#include "GPIO.h"
#include "GPIO_CONF.h"
#include "GPIO_TYPES.h"
#include "init.h"
#include "interrupt.h"
#include "LCD.h"
#include "LCD_CONF.h"
#include "LCD_TYPE.h"
#include "motor.h"
#include "pwm.h"
#include "ultrasonic.h"

#define PASSKEY_LENGTH 6
#define wait_for_10sec_timer0 100
#define MINWAIT 5000
#define MAXNUMBEROFTRIELS 3
#define NUMBEROFTRILESADDRESS 0xA
#define SAMPLING_NUMBER 7
#define DETECTION_DISTANCE 4
#define TEST_LED_PIN 6
#define FIRST_ENTERY_VALIDATION_ADDRESS 0xAA
#define FIRST_ENTERY_VALIDATION_LETTER 'K'
#define MIN_WAIT 5

int subtract;
int punish;
int divided;

unsigned int passkey_address_array[6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
uint8_t correct_passkey[6];
uint8_t ultra_flag;
uint8_t potentiometer_flag;
uint8_t keypad_flag;
uint8_t timer1_wait_for;
uint8_t mission_done;
uint8_t payload[6];
uint8_t current;
uint8_t coreect_pass_key;
uint8_t enter;
uint8_t new_pressed;
uint8_t is_long_pressed;
uint8_t counter;
uint8_t set_new_passkey;
uint8_t number_of_triels;
uint8_t buffer[20];

extern float wait_in_half_second;
extern uint8_t is_hash;

/*
*Function: MainMassage
*used to display "welcome" message after ultrasonic sensor sensing any motion at distance less than or equal 4 cm
*
*return void
*/
void MainMassage(void);

/*
*Function: run
*used to run all program
*
*return void
*/
void run(void);

/*
*Function: passkey_loading
*used to load the passkey from the eeprom
*
*return void
*/
void passkey_loading(void);

/*
*Function: lcd_format_display
*used to display all key as '*' to the user
*
*return void
*/
void lcd_format_display(char);

/*
*Function: first_entry_validation
*used to check if this is the first time of using this code or not 
*
*return void
*/
void first_entry_validation(void);

/*
*Function: load_number_of_triles
*used to load number of triles from the eeprom
*
*return void
*/
void load_number_of_triles(void);

/*
*Function: set_number_of_triles
*used toupdate the value of the number of triles
*
*return void
*/
void set_number_of_triles(void);

/*
*Function: reset_number_of_triles
*used to reset the number of triles
*
*return void
*/
void reset_number_of_triles(void);

/*
*Function: update_passkey
*used to update passkey in the eeprom
*
*char * --> is pointer to the string which hold the vlaue of the passkey
*return void
*/
void update_passkey(char *);

/*
*Function: do_punish
*used to punish the user if it enter the passkey 3,6,9,and so on times with invalid passkey
*
*return void
*/
void do_punish(void);

/*
*Function: reset_payload
*used to reset the payload which is used often for hold passkey value
*
*return void
*/
void reset_payload(void);

/*
*Function: old_passkey_scanning
*used to scan the old passkey from the user
*
*return void
*/
void old_passkey_scanning(void);

/*
*Function: new_passkey_scanning
*used to scan the new passkey from the user
*
*return void
*/
void new_passkey_scanning(void);

/*
*Function: passkey_scanning
*used to scan the passkey 
*
*return void
*/
void passkey_scanning(void);

/*
*Function: pass_comparing
*used to compare the string with the passkey in the eeprom
*
*char * --> is pointer to the string with need to compare with the correct passkey
*return 1 : string math with the corrct passkey
*return 0 : string not matches with the correct passkey
*/
int pass_comparing(char *);

/*
*Function: power
*used to caculate the 2 power x
*
*int --> to calculate the 2 of  power x
*return the value of 2 power x
*/
int power(int);

#endif /* APP_H_ */