/*
 * UART.c
 *
 *  Created on: Jul 29, 2022
 *      Author: lione
 */


#include "Uart_interface.h"
static void (*USART_RXC)(u8)=NULL;
u8 data;
u8 *name;
void UART_Int(void)
{
	//GLB_ON();
//RX Complete Interrupt Enable
	//SIT_BIT(UCSRB_REG,7);

	// TX Complete Interrupt Enable
	//SIT_BIT(UCSRB_REG,6);


	//USART Data Register Empty Interrupt Enable
	//SIT_BIT(UCSRB_REG,5);


	//Receiver Enable
	SET_BIT(UCSRB_REG,4);



	// TXEN: Transmitter Enable
	SET_BIT(UCSRB_REG,3);


	// Character Size to be 8 bit
	//CLEAR_BIT(UCSRB_REG,2);       U DONT NEED TO WRITE ON IT
	UCSRC_REG=134; //A_SYN NO_PRIOTY 1BIT_DATA 1BIT STOP NO_CLOCK_POLARITY


	// Rule for UBRRH and UBRRL
	u16 UBRR_loc=(((16000000)/(BAUD*16UL))-1);
	UBRRH_REG=UBRR_loc>>8;
	UBRRL_REG=(u8)UBRR_loc;
}

void UART_Transmit_chr(u8 data)
{
// USART Data Register Empty
while(CHECK_BIT(UCSRA_REG,5)==0);

UDR_REG=data;

}


u8 UART_Receive(void)
{
	// wait  USART Receive Complete

while(CHECK_BIT(UCSRA_REG,7)==0);
data=UDR_REG;
return data;
}


void UART_TransmitString(u8 * string){
	u8 i = 0;
	while(string[i] != '\0'){
		UART_Transmit_chr(string[i]);
		i++;
	}
}




u8  *UART1_Rx_Str()
{
	u8 send[15]={0};
data=0;
u8 i=0;
	while(UART_Receive()!=' ')
	{
		send[i]=data;
i++;
	}

	send[i]='\0';
GINT_ENABLE_INTERRUPT();
return send;
}




void EXT_INT_UASRT_Callout(void(*ptr)(u8))
{

	USART_RXC=ptr;

}

/*
ISR(USART_RXC_vect)
{
	data=UDR_REG;
if(USART_RXC!=NULL)
{
	USART_RXC(data);
	//USART_RXC=NULL;
}
else
{
	// do nothing
}


}
*/
