/*
 * ultrasonic.h
 *
 * Created: 4/4/2019 2:24:24 AM
 *  Author: Khaled's Lap
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <avr/io.h>
#include "timer.h"
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

#define  F_CPU_RATIO 8
#define ULTRASONIC_DISANCE_CONST 58
#define  TRIGER_PIN 3


float distance_from_object;

int status;
int pulse;



/*
*Function: ultra_scan
*
*used to scan the object front of the ultrasonic
*
*return void
*/
void ultra_scan(void);

#endif /* ULTRASONIC_H_ */