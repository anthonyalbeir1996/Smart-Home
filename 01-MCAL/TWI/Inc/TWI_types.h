/*
 * TWI_types.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Anthony
 */

#ifndef _TWI_TYPES_H_
#define _TWI_TYPES_H_
# include "Std_Types.h"

typedef struct
{
	u8 TWIE:1;
	u8 reserved:1;
	u8 TWEN:1;
	u8 TWWC:1;
	u8 TWSTO:1;
	u8 TWSTA:1;
	u8 TWEA:1;
	u8 TWINT:1;
}TWI_TWCRBits ;

typedef union
{
	u8 ALLreg;
	TWI_TWCRBits Bits;

}TWI_TWCRtypes;

typedef struct
{
	u8 TWI_TWBR;
	u8 TWI_TWSR;
	u8 TWI_TWAR;
	u8 TWI_TWDR;
	u8 reserved [51];
	TWI_TWCRtypes TWI_TWCR;
}TWI_reg;



#endif /* MCAL_TWI_INC_TWI_TYPES_H_ */
