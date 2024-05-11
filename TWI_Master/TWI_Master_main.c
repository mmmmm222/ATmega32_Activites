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
#include <util/delay.h>

void main()
{
	PORT_voidInIt();
	GIE_voidEnable();
	TWI_voidInitMaster(0);
	TWI_SendStartCondition();
	long long cnt=0;
	while(1)
	{
		TWI_SendSlaveAddressWithWrite(200);
		TWI_MasterWriteDataByte(2);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		TWI_SendRepeatedStart();
		TWI_SendSlaveAddressWithWrite(200);
		TWI_MasterWriteDataByte(4);
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
