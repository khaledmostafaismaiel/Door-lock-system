
#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

#include "GPIO_TYPES.h"
#include "GPIO_CONF.h"
#include "helper.h"

/*number of ports*/
#define PORT_NUMBER 4

/*Registers Address */
#define PORT(PortID) *((Gpio_DataType)(Base_GPIO[PortID] + (uint8_t)0X02))
#define DDR(PortID) *((Gpio_DataType)(Base_GPIO[PortID] + (uint8_t)0X01))
#define PIN(PortID) *((Gpio_DataType)(Base_GPIO[PortID] + (uint8_t)0X00))

/*Define PORTS*/
#define A 0
#define B 1
#define C 2
#define D 3

/*declaration array of registers addresses*/
extern const uint8_t Base_GPIO[PORT_NUMBER];

/*prototypes*/
void GPIO_Init(void);
void GPIO_Write(uint8_t, uint8_t);
uint8_t GPIO_Read(uint8_t);
#endif
