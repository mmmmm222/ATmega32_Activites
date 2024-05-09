/*
 * SPI_main.c
 *
 *  Created on: May 9, 2024
 *      Author: moali
 */

#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include <util/delay.h>

void main(void)
{
	PORT_voidInIt();
	SPI_VoidInit();

	u8 data = 0;
	while(1)
	{
		_delay_ms(1000);
		SPI_u8Tranceive(100,&data);
		if(data == 1)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
		else if(data == 2)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		}
	}
}
