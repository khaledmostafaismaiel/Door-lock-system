/*
 * init.h
 *
 * Created: 3/31/2019 2:33:25 AM
 *  Author: Khaled's Lap
 */

#ifndef INIT_H_
#define INIT_H_

#include <avr/io.h>
#include "helper.h"

/*
*Function: ports_init
*
*used to make all ports input in the first of the code , before the initialization
*
*return void
*/
void ports_init(void);

/*
*Function: all_init
*
*used to call all the important initializations
*
*return void
*/
void all_init(void);

#endif /* INIT_H_ */
