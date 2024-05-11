/*
 * TWI_Slave1_main.c
 *
 *  Created on: May 11, 2024
 *      Author: moali
 */


/*
 * TWI_Master_main.c
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

u8 Data=0;

void main()
{
	PORT_voidInIt();
	GIE_voidEnable();
	TWI_voidInitSlave(100);
	while(1)
	{
		TWI_SlaveReadDataByte(&Data);
		if(Data)
		{
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
	}

}
