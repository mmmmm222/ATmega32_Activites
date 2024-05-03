#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "util/delay.h"

void main(void)
{
	while(1)
	{
		for(u8 i=0; i<255; i++)
		{
			DIO_u8SetPortValue(DIO_u8PORTA,i);
			_delay_ms(10);
		}
		for(u8 i=0; i<255; i++)
		{
			DIO_u8SetPortValue(DIO_u8PORTA,255-i);
			_delay_ms(10);
		}
	}
}

