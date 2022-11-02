/*
 * Spi_interface.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Anthony
 */

#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_
#include "Spi_REG.H"
#include "Spi_types.h"
#include "Std_Types.h"


#define Spi_SS_pin    4
#define Spi_MOSI_pin  5
#define Spi_MISO_pin  6
#define Spi_SCK_pin   7

#define Spi_port      DIO_PORTB

void Spi_init(spi_initoption option);
u8 Spi_TxRx (u8 data);
void Spi_Slave_Enable(void);
void Spi_Slave_Disable(void);





#endif /* MCAL_SPI_INC_SPI_INTERFACE_H_ */
