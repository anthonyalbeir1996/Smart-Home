/*
 * EXT_INT_reg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */

#ifndef _EXT_INT_REG_H_
#define _EXT_INT_REG_H_

#define EXT_INT_MCUCR_REG    (*(volatile u8*)(0x55))
#define EXT_INT_MCUCSR_REG   (*(volatile u8*)(0x54))
#define EXT_INT_GICR_REG     (*(volatile u8*)(0x5B))
#define EXT_INT_GIFR_REG     (*(volatile u8*)(0x5A))


#endif /* MCAL_EXT_INT_INC_EXT_INT_REG_H_ */
