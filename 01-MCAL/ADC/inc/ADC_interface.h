/*
 * ADC_interface.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */

#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#include <Bit_Math.h>
#include "ADC_reg.h"
#include "ADC_types.h"
#include "ADC_cfg.h"
#include "Std_Types.h"


void ADC_init(void);
u16 ADC_read(adc_channel_t channel);


#endif /* MCAL_ADC_INC_ADC_INTERFACE_H_ */
