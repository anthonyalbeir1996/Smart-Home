/*
 * LM35.c
 *
 *  Created on: Jul 1, 2022
 *      Author: lione
 */
#include "LM35_Interface.h"

void LM35_Int(void)
{
	ADC_init();
}
u16 LM35_Read(void)
{
	u16 result=0;
	f32 volt=0;
	u16 temp;
	result=ADC_read(LM35_CHANNEL);
	volt=result*4.8;
	temp=volt/10;
	return temp;
}
