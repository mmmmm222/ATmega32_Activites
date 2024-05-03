#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>

void main(void)
{
	PORT_voidInIt();
	while(1)
	{
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
		_delay_ms(1000);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
		_delay_ms(1000);

	}
}
