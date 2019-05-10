/*
 * limitswitch.h
 *
 * Created: 4/22/2019 3:41:55 AM
 *  Author: Khaled's Lap
 */

#ifndef LIMITSWITCH_H_
#define LIMITSWITCH_H_

#include <avr/io.h>
#include <avr/delay.h>
#include "motor.h"
#include "helper.h"

#define CLOSE_LIMIT_SWITCH_PIN 5
#define OPEN_LIMIT_SWITCH_PIN 4
#define NUM_OF_LIMIT_SWITCH_SAMPLING 5

uint8_t limit_switch_flag;

extern uint8_t doorOpencounter;
extern uint8_t doorclosecounter;

/*
*Function: close_limit_switch_checker
*
*used to check the close limit swith if it hited or no
*
*return void
*/
void close_limit_switch_checker(void);

/*
*Function: open_limit_switch_checker
*
*used to check the open limit swith if it hited or no
*
*return void
*/
void open_limit_switch_checker(void);

#endif /* LIMITSWITCH_H_ */