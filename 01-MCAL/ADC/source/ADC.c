/*
 * ADC.C
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */

#include "ADC_interface.h"
#include "Bit_Math.h"

void ADC_init(void)
{
	           /* REF=VCC */
	ADC_ADMUX_reg|=(VCC_REF<<6);

               /*Enable ADC, prescaler=/128 */
	ADC_ADCSRA_reg |= (ADC_ENABLE)|(ADC_ADPS_128);
}

u16 ADC_read(adc_channel_t channel)
{

	u16 result;
     /*  select channel */
	ADC_ADMUX_reg=(ADC_ADMUX_reg & 0xF8)|(channel);


	/*ADC Start Conversion */
SET_BIT(ADC_ADCSRA_reg,ADC_Start_Conversion_bit_no);

    /* wait until ADC conversion finish */
while(CHECK_BIT(ADC_ADCSRA_reg,ADC_ADIF_bit_no)!=1)
{
	/* do nothing */
}

    /* clear interrupt flag to start another conversion */
 SET_BIT(ADC_ADCSRA_reg,ADC_ADIF_bit_no);

 /* read ADC Result */
 result = (ADC_ADCL_reg|(ADC_ADCH_reg<<8));

 return result;

}
