/*
 * Spi.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Anthony
 */

#include "Spi_interface.h"
#include "DIO_INTERFACE.h"


void Spi_init(spi_initoption option)
{
	switch (option.state)
	{
	case Master:
		DIO_cnfg_channel(Spi_port,Spi_SS_pin, DIO_HIGH);
		DIO_cnfg_channel(Spi_port, Spi_SCK_pin, DIO_HIGH);
		DIO_cnfg_channel(Spi_port, Spi_MOSI_pin, DIO_HIGH);
		DIO_cnfg_channel(Spi_port, Spi_MISO_pin, DIO_LOW);
		SPI->myspcr.ALLREG=0X50;
		break;

	case Slave:
		DIO_cnfg_channel(Spi_port,Spi_SS_pin, DIO_LOW);
		DIO_cnfg_channel(Spi_port, Spi_SCK_pin, DIO_LOW);
		DIO_cnfg_channel(Spi_port, Spi_MOSI_pin, DIO_LOW);
		DIO_cnfg_channel(Spi_port, Spi_MISO_pin, DIO_HIGH);
        SPI->myspcr.bits.SPE=1;
		break;
	}
}


u8 Spi_TxRx (u8 data)
{
   SPI->myspdr=data;
    while(SPI->myspsr.bits.SPIF==FALSE);
    return SPI->myspdr;
}


void Spi_Slave_Enable(void)
{
 DIO_cnfg_channel(Spi_port, Spi_SS_pin, DIO_LOW);
}


void Spi_Slave_Disable(void)
{
 DIO_cnfg_channel(Spi_port, Spi_SS_pin, DIO_HIGH);
}

