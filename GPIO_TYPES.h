#ifndef GPIO_TYPES_H_INCLUDED
#define GPIO_TYPES_H_INCLUDED
#include "helper.h"

typedef volatile uint8_t *const Gpio_DataType;

typedef struct
{
    uint8_t Port_ID;
    uint8_t Dir;
    uint8_t Mask;
    uint8_t PullUP;
} GPIO_Type;

#endif // GPIO_TYPES_H_INCLUDED
