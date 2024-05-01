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
#include <util/delay.h>


void main(void)
{
	u8 i = 0;
	PORT_voidInIt();
	TIMER0_voidInit();
	GIE_voidEnable();


	while(1)
	{
		for(i=0; i<255; i++){
			SetCompareMatchValue(i);
			_delay_ms(100);
		}

	}
}

