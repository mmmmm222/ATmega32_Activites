/*
 * TWI_Slave2_main.c
 *
 *  Created on: May 11, 2024
 *      Author: moali
 */


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
long long cnt=0;

void main()
{
	PORT_voidInIt();
	GIE_voidEnable();
	TWI_voidInitSlave(200);
	while(1)
	{
		TWI_SlaveReadDataByte(&Data);
		if(cnt%2==0){
			DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
		else{
			DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_LOW);
		}
		cnt++;
	}

}
