/*
 * Spi_types.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Anthony
 */

#ifndef _SPI_TYPES_H_
#define _SPI_TYPES_H_
#include "Std_Types.h"

typedef enum
{
	Master,
	Slave
}types_SPI;


typedef struct
{
	types_SPI state;
}spi_initoption;


typedef struct
{

	u8 SPR0:2;
	u8 CPHA :1;
	u8 CPOL :1;
	u8 MSTR :1;
	u8 DORD :1;
	u8 SPE :1;
	u8 SPIE :1;
}Spi_Spcrbits;

typedef union
{
	Spi_Spcrbits bits;
	u8 ALLREG;

}Spi_Spcrtypes;


typedef struct
{
	u8 SPI2X:1;
	u8 reserved :5;
	u8 WCOL :1;
	u8 SPIF :1;
}Spi_Spsrbits;


typedef union
{
	u8 ALLREG;
	Spi_Spsrbits bits;

}Spi_Spsrtypes ;




typedef struct
{
	Spi_Spcrtypes myspcr;
	Spi_Spsrtypes myspsr;
	u8  myspdr;

}SPI_REG;



#endif /* MCAL_SPI_INC_SPI_TYPES_H_ */
