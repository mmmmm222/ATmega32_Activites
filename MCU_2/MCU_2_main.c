#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "USART_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>

void isr(void);

void main(void)
{
	PORT_voidInIt();
	USART_voidInit();
	u8 data = 0;
	while(1)
	{
		USART_u8RecevieData(&data);
		if(data == '1')
			DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_HIGH);
		else if(data == '2')
			DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_LOW);
	}
}
void isr(void)
{

}

