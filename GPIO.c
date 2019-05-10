#define F_CPU 8000000UL

#include "GPIO.h"

const uint8_t Base_GPIO[PORT_NUMBER] = {0x39, 0x36, 0x33, 0x30};

void GPIO_Init(void)
{
    uint8_t i;
    for (i = 0; i < NUM_OF_GROUPS; i++)
    {
        DDR(groups[i].Port_ID) &= ~(groups[i].Mask);
        DDR(groups[i].Port_ID) |= (groups[i].Dir) & (groups[i].Mask);

        PORT(groups[i].Port_ID) &= ~(groups[i].Mask);
        PORT(groups[i].Port_ID) |= ~(groups[i].Dir) & (groups[i].Mask) & (groups[i].PullUP);
    }
}
void GPIO_Write(uint8_t GroupID, uint8_t Data)
{
    uint8_t portcopy = PORT(groups[GroupID].Port_ID);
    portcopy &= ~(groups[GroupID].Mask);
    portcopy |= Data & groups[GroupID].Mask & groups[GroupID].Dir;
    PORT(groups[GroupID].Port_ID) = portcopy;
}
uint8_t GPIO_Read(uint8_t GroupID)
{
    return PIN(groups[GroupID].Port_ID) & groups[GroupID].Mask;
}
