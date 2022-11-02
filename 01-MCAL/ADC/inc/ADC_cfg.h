/*
 * ADC_cfg.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Anthony
 */

#ifndef _ADC_CFG_H_
#define _ADC_CFG_H_

          //ADC Voltage//
#define REF                 ((u8)1<<6)
#define VCC_REF             ((u8)1)
#define Internal_REF        ((u8)3)
#define ADC_Left_Adjust     ((u8)1<<5)

#define ADC_ENABLE                    ((u8)1<<7)
#define ADC_Start_Conversion_bit_no   ((u8)6)
#define ADC_Interrupt_Enable          ((u8)1<<3)

         //ADC Prescaler//
#define ADC_ADPS_2      (0)
#define ADC_ADPS_4      (2)
#define ADC_ADPS_8      (3)
#define ADC_ADPS_16     (4)
#define ADC_ADPS_32     (5)
#define ADC_ADPS_64     (6)
#define ADC_ADPS_128    (7)

#define ADC_ADIF_bit_no (4)

#endif /* MCAL_ADC_INC_ADC_CFG_H_ */
