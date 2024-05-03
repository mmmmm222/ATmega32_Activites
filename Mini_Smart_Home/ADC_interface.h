/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 22/3/2024
 *  Version : V_1.00
 *  Layer   : MCAL
 *
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);
void ADC_voidEnable(void);
void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);
u8 ADC_u8SetPrescaller(u8 Copy_u8Prescaller);
u8 ADC_u8GetResultSync (u8 Copy_u8Channel , u16 * Copy_pu16Result);
u8 ADC_u8StartConversionAsynch (u8 Copy_u8Channel , u16 * Copy_pu16Result , void (*Copy_pvNotificationFunc)(void));




#endif
