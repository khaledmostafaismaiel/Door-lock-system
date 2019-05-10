/*
 * motor.h
 *
 * Created: 4/6/2019 5:46:04 PM
 *  Author: Khaled's Lap
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "ultrasonic.h"
#include "EEPROM.h"
#include "LCD.h"
#include "helper.h"

#define FIRST_MOTOR_PIN 7 //the pwm pin
#define SECOND_MOTOR_PIN 7

uint8_t door_is_close;
uint8_t door_is_open;

extern uint8_t correct_passkey[6];




/*
*Function: close_door
*
*used to close the door
*
*return void
*/
void close_door(void);





/*
*Function: open_door
*
*used to open the door
*
*return void
*/
void open_door(void);



/*
*Function: stop_opening
*
*used to stop the door opening
*
*return void
*/
void stop_opening(void);



/*
*Function: stop_closing
*
*used to stop the door closing
*
*return void
*/
void stop_closing(void);


#endif /* MOTOR_H_ */