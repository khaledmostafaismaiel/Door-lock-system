/*
 * ADC.h
 *
 * Created: 4/6/2019 1:46:31 AM
 *  Author: Khaled's Lap
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "pwm.h"
#include "helper.h"



/*
*Function: adc_init
*
*used init the adc in portA pin0
*
*return void
*/
void adc_init(void);


/*
*Function: start_conversion
*
*used to start the convertion
*
*return void
*/
void start_conversion(void);


/*
*Function: adc_read
*
*used to start conversion and read the value of the adc
*
*return unsigned short adc value
*/
unsigned short adc_read(void);

#endif /* ADC_H_ */