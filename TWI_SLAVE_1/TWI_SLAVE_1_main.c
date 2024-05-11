/*
 * TWI_SLAVE_1_main.c
 *
 *  Created on: May 11, 2024
 *      Author: moali
 */




#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TWI_interface.h"
#include "CLCD_interface.h"

u8 Data=55;

void main()
{
	PORT_voidInIt();
	CLCD_voidInit();
	GIE_voidEnable();
	TWI_voidInitSlave(50);
	CLCD_voidSendString("wwwwwwwwwww");
	u8 x;
	while(1)
	{
		x = TWI_SlaveReadDataByte(&Data);
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("SLAVE_1 Err= ");
		CLCD_voidDisplayNumber(x);
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("SLAVE_1 = ");
		CLCD_voidDisplayNumber(Data);
	}
}
