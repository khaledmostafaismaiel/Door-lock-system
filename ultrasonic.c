/*
 * ultrasonic.c
 *
 * Created: 4/4/2019 2:24:08 AM
 *  Author: Khaled's Lap
 */

#define F_CPU 8000000UL

#include "ultrasonic.h"


void ultra_scan(void)
{

  DDRD |=  (1 << TRIGER_PIN);
  PORTD |=  (1 << TRIGER_PIN);
  _delay_ms(15);
  PORTD &= ~ (1 << TRIGER_PIN);
  distance_from_object = ((pulse / F_CPU_RATIO) / ULTRASONIC_DISANCE_CONST);
  return;
}
