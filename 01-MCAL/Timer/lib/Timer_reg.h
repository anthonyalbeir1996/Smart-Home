/*
 * Timer_reg.h
 *
 *  Created on: Oct 20, 2022
 *      Author: Anthony
 */

#ifndef LIB_TIMER_REG_H_
#define LIB_TIMER_REG_H_

/* for timer0  */
/*TCCR0 to choose mode and prescaler */
#define TCCR0_REG  (*(volatile u8*)(0x53))
/*TCNT0 save the preload */
#define TCNT0_REG  (*(volatile u8*)(0x52))
/*TIMSK Timer/Counter0 Overflow Interrupt Enable */
#define TIMSK_REG  (*(volatile u8*)(0x59))
/*TIFR Timer/Counter0 Overflow Flag */
#define TIFR_REG  (*(volatile u8*)(0x58))
#define OCR0_REG  (*(volatile u8*)(0x5C))

/* for timer1  */

#define TCCR1A_REG  (*(volatile u8*)(0x4F))
#define TCCR1B_REG  (*(volatile u8*)(0x4E))
#define OCR1BH_REG  (*(volatile u8*)(0x49))
#define OCR1BL_REG  (*(volatile u8*)(0x48))
#define TCNT1L_REG  (*(volatile u8*)(0x4C))
#define TCNT1_REG  (*(volatile u16*)(0x4C))
#define TCNT1H_REG  (*(volatile u8*)(0x4D))
#define OCR1AH_REG  (*(volatile u8*)(0x4B))
#define OCR1AL_REG  (*(volatile u8*)(0x4A))
#define OCR1A_REG  (*(volatile u16*)(0x4A))
#define OCR1B_REG  (*(volatile u16*)(0x48))
#define ICR1H_REG  (*(volatile u8*)(0x47))
#define ICR1L_REG  (*(volatile u8*)(0x46))
#define ICR1_REG  (*(volatile u16*)(0x46))


/* for timer2  */
/*TCCR0 to choose mode and prescaler */
#define TCCR2_REG  (*(volatile u8*)(0x45))
/*TCNT0 save the preload */
#define TCNT2_REG  (*(volatile u8*)(0x44))

#define OCR2_REG  (*(volatile u8*)(0x43))

#endif /* 01_MCAL_TIMER_LIB_TIMER_REG_H_ */
