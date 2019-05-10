/*
 * pwm.h
 *
 * Created: 4/10/2019 2:16:08 AM
 *  Author: Khaled's Lap
 */

#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include "helper.h"

uint8_t duty_cycle;



/*
*Function: pwm_duty
*used to set the duty cycle
*
*unsigned int duty --> this is an integer value which is placed as a duty cycle 
*
*return void
*/
void pwm_duty(unsigned int duty);


#endif /* PWM_H_ */