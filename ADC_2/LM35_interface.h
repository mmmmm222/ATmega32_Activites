/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LM35_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 22/3/2024
 *  Version : V_1.00
 *  Layer   : HAL
 *
 */

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#include "STD_TYPES.h"

void LM35_voidTempratureReading(u16 Copy_u16DigitalRead, u16 *Copy_pu16Temprature);

#endif