/*
 * EXT_INT.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */

#ifndef _EXT_INT_H_
#define _EXT_INT_H_

#include "EXT_INT_reg.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "EXT_INT_types.h"

void Ext_INTERRUPT_ENABE(ext_int_t ID);
void EXT_INTERRUPT_DISABLE(ext_int_t ID);
void EXT_INTERUPPT_SENCONTROL (ext_int_t ID,ext_int_modes_t mode);



#endif /* MCAL_EXT_INT_INC_EXT_INT_H_ */
