/*
 * interrupt.h
 *
 * Created: 4/3/2019 2:10:40 AM
 *  Author: Khaled's Lap
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "helper.h"



uint8_t doorOpencounter;
uint8_t doorclosecounter;

extern int status;
extern int pulse;




/*
*Function: set_int0_init
*
*used to init the interrupt 0 which is connected with the echo pin
*
*return void
*/
void set_int0_init(void);




/*
*Function: reset_int0_init
*
*used to reset the init of the int0
*
*return void
*/
void reset_int0_init(void);


#endif /* INTERRUPT_H_ */