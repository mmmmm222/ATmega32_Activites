/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 16/3/2024
 *  Version : V_1.00
 *  Layer   : MCAL
 *
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*
 	options :
 	- NORMAL
 	- PWM_PHASE_CORRECT
 	- CTC
 	- FAST_PWM
*/
#define TIMER0_MODE			FAST_PWM

//--------------------------------------------------------------------

/*
 	options :
 	- DISCONNECTED
 	- TOGGLE
 	- CLR
 	- SET
*/
#define  CTC_OUTPUT_MODE	DISCONNECTED

//--------------------------------------------------------------------

/*
 	options :
 	- NO_CLOCK_SOURCE
 	- NO_PRESCALER_FACTOR
 	- DIVISION_FACTOR_8
 	- DIVISION_FACTOR_64
 	- DIVISION_FACTOR_256
 	- DIVISION_FACTOR_1024
 	- EXTERNAL_CLOCK_SOURCE_FALLING
 	- EXTERNAL_CLOCK_SOURCE_RISING
*/

#define TIMER0_PRESCALLER	DIVISION_FACTOR_64

//--------------------------------------------------------------------

#define TIMER0_PRELOAD_VALUE		0
#define CTC_COMPARE_VALUE			125
#define CTC_NOTIFICATIONS_NUMBER	1

//--------------------------------------------------------------------

/*
 	options :
 	- ENABLE
 	- DISABLE
*/

#define TIMER0_OVERFLOW_INTERRUPT_STATE		ENABLE

//--------------------------------------------------------------------

/*
 	options :
 	- ENABLE
 	- DISABLE
*/

#define CTC_INTERRUPT_STATE		ENABLE

//--------------------------------------------------------------------

/*
 	options :
 	- DISCONNECTED
 	- CLR_ON_COMPARE
 	- SET_ON_COMPARE
*/

#define FAST_PWM_MODE	CLR_ON_COMPARE

//--------------------------------------------------------------------

#define DUTY_CYCLE

#endif
