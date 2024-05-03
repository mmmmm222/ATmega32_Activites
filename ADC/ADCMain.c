#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include "GIE_interface.h"
#include "util/delay.h"

void Display_chain(void);

u8 channels[3] = {0,1,2};
u8 res[3];
Chain_t ch;



void main(void)
{
	PORT_voidInIt();
	ADC_voidInit();
//	GIE_voidEnable();
//	ADC_voidEnable();
	CLCD_voidInit();
	u16 res ;
	while(1)
	{
		ADC_u8GetResultSync(0,&res);
		CLCD_voidDisplayNumber(res);
		_delay_ms(50);
		CLCD_voidClearScreen();
		CLCD_voidGoToXY(0,0);
	}
}

void Display_chain(void){

}
