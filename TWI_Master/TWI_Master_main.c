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

void main()
{
	PORT_voidInIt();
	GIE_voidEnable();
	TWI_voidInitMaster(0);
	long long cnt=0;

	while(1)
	{
		TWI_SendStartCondition();
		TWI_SendSlaveAddressWithWrite(50);
		TWI_MasterWriteDataByte(255);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		TWI_SendStopCondition();
		if(cnt%2==0){
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_HIGH);
		}
		else{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_LOW);
		}
		TWI_SendRepeatedStart();
		cnt++;
	}
}
