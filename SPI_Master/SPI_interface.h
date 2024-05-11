/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SPI_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : SPI
 *
 */
 
/*File Gard*/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/* to change the configuration at run time*/
typedef struct
{
	u8 SPI_u8InterruptEnable ;
	u8 SPI_u8SPIEnable ;
	u8 SPI_u8DataOrder ;
	u8 SPI_u8MasterSlaveSelect ;
	u8 SPI_u8ClockPolarity ;
	u8 SPI_u8ClockPhase ;
	u8 SPI_u8ClockRate ;
}SPI_CONFIG;

typedef struct
{
	u8 * Copy_u8TData ;
	u8 * Copy_u8RData ;
	u8 Copy_u8BufferSize ;
	void(* NotificationFuncn)(void) ;
}SPI_BUFFER;



void SPI_VoidInit(void) ;
u8 SPI_u8InitConfig (SPI_CONFIG * spi) ;
u8 SPI_u8Tranceive (u8 Copy_u8TData , u8 * Copy_u8RData) ;
u8 SPI_u8BufferTranceiverSynch (u8 * Copy_u8TData , u8 * Copy_u8RData , u8 Copy_u8BufferSize) ;
u8 SPI_u8BufferTranceiverAsynch (SPI_BUFFER * spi_buffer) ;


#endif
