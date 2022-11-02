/*
 * Uart_Reg.h
 *
 *  Created on: Jul 31, 2022
 *      Author: Anthony
 */


#ifndef UART_REG_H_
#define UART_REG_H_
// UDR
#define UDR_REG  (*(volatile u8*)(0x2C))
//UCSRA
#define UCSRA_REG  (*(volatile u8*)(0x2B))
//UCSRB
#define UCSRB_REG  (*(volatile u8*)(0x2A))
//UCSRC
#define UCSRC_REG  (*(volatile u8*)(0x40))
//UBRRH
#define UBRRH_REG  (*(volatile u8*)(0x40))
//UBRRL
#define UBRRL_REG  (*(volatile u8*)(0x29))


#endif /* UART_REG_H_ */


