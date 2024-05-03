/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 16/3/2024
 *  Version : V_1.00
 *  Layer   : MCAL
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "Timer_register.h"

static void (*GlobalpvCallbackFunc)(void) = NULL;

void TIMER0_voidInit(void)
{

}

//-----------------------------------------------------------------

u8 Timer0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		GlobalpvCallbackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

//------------------------------------------------------------------------------

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{

	if( GlobalpvCallbackFunc != NULL)
	{
		GlobalpvCallbackFunc();
	}

}

