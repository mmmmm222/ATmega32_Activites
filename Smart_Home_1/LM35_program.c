/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LM35_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 22/3/2024
 *  Version : V_1.00
 *  Layer   : HAL
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define Step 5

void LM35_voidTempratureReading(u16 Copy_u16DigitalRead, u16 *Copy_pu16Temprature)
{
    // analog = digital * step(mv)

    *Copy_pu16Temprature = ((Copy_u16DigitalRead * Step) / 10);
//    *Copy_pu16Temprature = (((u32)Copy_u16DigitalRead * 5ul) / 1024ul);
}
