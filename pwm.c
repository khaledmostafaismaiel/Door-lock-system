/*
 * pwm.c
 *
 * Created: 4/10/2019 2:16:28 AM
 *  Author: Khaled's Lap
 */
#define F_CPU 8000000UL

#include "pwm.h"

void pwm_duty(unsigned int duty)
{

  OCR2 = duty;
}
