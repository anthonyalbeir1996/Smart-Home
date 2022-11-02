/*
 * UART_confg.h
 *
 *  Created on: Jul 31, 2022
 *      Author: Anthony
 */

#ifndef _UART_CONFG_H_
#define _UART_CONFG_H_

#define BaudRate   9600
#define F          16000000


#ifdef DoubleSpeed

#define UBRR ((F/(BaudRate*16))-1)

#else

#define UBRR ((F/(BaudRate*8))-1)

#endif

#define UART_TX_ENABLE         (1<<3)
#define UART_RX_ENABLE         (1<<4)
#define UART_UCSRC_SELECT     (1<<7)
#define UART_RXC_FLAG          (7)
#define UART_TXC_FLAG          (6)
#define UART_UDRE_FLAG         (5)

#define UART_CHAR_BITSIZE_5    (0<<1)
#define UART_CHAR_BITSIZE_6    (1<<1)
#define UART_CHAR_BITSIZE_7    (2<<1)
#define UART_CHAR_BITSIZE_8    (3<<1)






#endif /* MCAL_UART_INC_UART_CONFG_H_ */
