#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include <util/delay.h>

void INT0_ISR(void);

void main (void)
{

	PORT_voidInIt();
	EXTI_voidInt0Init();
	EXTI_u8SetCallBack(INT0_ISR);
	GIE_voidEnable();
	while(1)
	{

	}
}


void INT0_ISR(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	_delay_ms(250);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
}
