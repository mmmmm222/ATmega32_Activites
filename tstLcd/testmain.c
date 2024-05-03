#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"

void main(void)
{
	PORT_voidInIt();
	CLCD_voidInit();
//	f64 x = 456789112345;
	CLCD_voidDisplayNumber(12345678);
//	CLCD_voidSendString("12345678910111213141516");

	while(1)
	{
	}
}
