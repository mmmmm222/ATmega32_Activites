/*
 * TIMER0main.c
 *
 *  Created on: Mar 18, 2024
 *      Author: moali
 */

#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include "BIT_MATH.h"

void Toggle(void);

void main(void)
{
	PORT_voidInIt();
	TIMER0_voidInit();
	Timer0_u8SetCallBack(&Toggle);
	GIE_voidEnable();

	while(1)
	{

	}
}


void Toggle(void)
{
	static u8 Counter=0;
	Counter++;
	if(Counter == 5){
		// make the pin Low
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
	}
	else if(Counter == 20){
		//make pin high
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		//make counter = 0
		Counter = 0;
	}

}
