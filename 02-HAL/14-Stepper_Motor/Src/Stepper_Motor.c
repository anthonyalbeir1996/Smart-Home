/*
 * Stepper_Motor.c
 *
 *  Created on: Oct 6, 2022
 *      Author: lione
 */


#include "Stepper_Motor_Interface.h"

dio_port_t mport;
nipple_port mnipple;
void Stepper_Int(dio_port_t port,nipple_port nipple)
{
	mport= port;
	mnipple=nipple;

	switch(nipple)
{
	case RAND_NIPPLE:
		DIO_cnfg_channel(port, DIO_PIN1, DIO_OUTPUT);
		DIO_cnfg_channel(port, DIO_PIN3, DIO_OUTPUT);
		DIO_cnfg_channel(port, DIO_PIN4, DIO_OUTPUT);
		DIO_cnfg_channel(port, DIO_PIN5, DIO_OUTPUT);
		break;

case HIGH_NIPPLE:
	DIO_cnfg_channel(port, DIO_PIN4, DIO_OUTPUT);
	DIO_cnfg_channel(port, DIO_PIN5, DIO_OUTPUT);
	DIO_cnfg_channel(port, DIO_PIN6, DIO_OUTPUT);
	DIO_cnfg_channel(port, DIO_PIN7, DIO_OUTPUT);
	break;
case LOW_NIPPLE:
	DIO_cnfg_channel(port, DIO_PIN0, DIO_OUTPUT);
	DIO_cnfg_channel(port, DIO_PIN1, DIO_OUTPUT);
	DIO_cnfg_channel(port, DIO_PIN2, DIO_OUTPUT);
	DIO_cnfg_channel(port, DIO_PIN3, DIO_OUTPUT);
	break;

}
}

void Stepper_Cfg(u8 speed,clk_wise clk,nipple_port nipple)
{
switch(clk)
{
case CLOCK_WISE_STEPPER:


	switch(nipple)
{
	case RAND_NIPPLE:
		DIO_write(mport,DIO_PIN1 , DIO_HIGH);
		DIO_write(mport,DIO_PIN3 , DIO_LOW);
		DIO_write(mport,DIO_PIN4 , DIO_LOW);
		DIO_write(mport,DIO_PIN5 , DIO_LOW);

			_delay_ms(speed);
			DIO_write(mport,DIO_PIN1 , DIO_LOW);
			DIO_write(mport,DIO_PIN3 , DIO_HIGH);
			DIO_write(mport,DIO_PIN4 , DIO_LOW);
			DIO_write(mport,DIO_PIN5 , DIO_LOW);
			_delay_ms(speed);
			DIO_write(mport,DIO_PIN1 , DIO_LOW);
			DIO_write(mport,DIO_PIN3 , DIO_LOW);
			DIO_write(mport,DIO_PIN4 , DIO_HIGH);
			DIO_write(mport,DIO_PIN5 , DIO_LOW);
			_delay_ms(speed);
			DIO_write(mport,DIO_PIN1 , DIO_LOW);
			DIO_write(mport,DIO_PIN3 , DIO_LOW);
			DIO_write(mport,DIO_PIN4 , DIO_LOW);
			DIO_write(mport,DIO_PIN5 , DIO_HIGH);

			_delay_ms(speed);
		break;

case HIGH_NIPPLE:
	DIO_write(mport,DIO_PIN4 , DIO_HIGH);
	DIO_write(mport,DIO_PIN5 , DIO_LOW);
	DIO_write(mport,DIO_PIN6 , DIO_LOW);
	DIO_write(mport,DIO_PIN7 , DIO_LOW);

	_delay_ms(speed);
	DIO_write(mport,DIO_PIN4 , DIO_LOW);
	DIO_write(mport,DIO_PIN5 , DIO_HIGH);
	DIO_write(mport,DIO_PIN6 , DIO_LOW);
	DIO_write(mport,DIO_PIN7 , DIO_LOW);
	_delay_ms(speed);
	DIO_write(mport,DIO_PIN4 , DIO_LOW);
	DIO_write(mport,DIO_PIN5 , DIO_LOW);
	DIO_write(mport,DIO_PIN6 , DIO_HIGH);
	DIO_write(mport,DIO_PIN7 , DIO_LOW);
	_delay_ms(speed);
	DIO_write(mport,DIO_PIN4 , DIO_LOW);
	DIO_write(mport,DIO_PIN5 , DIO_LOW);
	DIO_write(mport,DIO_PIN6 , DIO_LOW);
	DIO_write(mport,DIO_PIN7 , DIO_HIGH);

	_delay_ms(speed);

	break;
case LOW_NIPPLE:
	DIO_write(mport,DIO_PIN0 , DIO_HIGH);
	DIO_write(mport,DIO_PIN1 , DIO_LOW);
	DIO_write(mport,DIO_PIN2 , DIO_LOW);
	DIO_write(mport,DIO_PIN3 , DIO_LOW);

	_delay_ms(speed);
	DIO_write(mport,DIO_PIN0 , DIO_LOW);
	DIO_write(mport,DIO_PIN1 , DIO_HIGH);
	DIO_write(mport,DIO_PIN2 , DIO_LOW);
	DIO_write(mport,DIO_PIN3 , DIO_LOW);
	_delay_ms(speed);
	DIO_write(mport,DIO_PIN0 , DIO_LOW);
	DIO_write(mport,DIO_PIN1 , DIO_LOW);
	DIO_write(mport,DIO_PIN2 , DIO_HIGH);
	DIO_write(mport,DIO_PIN3 , DIO_LOW);
	_delay_ms(speed);
	DIO_write(mport,DIO_PIN0 , DIO_LOW);
	DIO_write(mport,DIO_PIN1 , DIO_LOW);
	DIO_write(mport,DIO_PIN2 , DIO_LOW);
	DIO_write(mport,DIO_PIN3 , DIO_HIGH);
	break;

}






	break;
case ANTI_CLOCK_WISE_STEPPER:


	switch(nipple)
{

	case RAND_NIPPLE:
		DIO_write(mport,DIO_PIN1 , DIO_LOW);
		DIO_write(mport,DIO_PIN3 , DIO_LOW);
		DIO_write(mport,DIO_PIN4 , DIO_LOW);
		DIO_write(mport,DIO_PIN5 , DIO_HIGH);


			_delay_ms(speed);
			DIO_write(mport,DIO_PIN1 , DIO_LOW);
			DIO_write(mport,DIO_PIN3 , DIO_LOW);
			DIO_write(mport,DIO_PIN4 , DIO_HIGH);
			DIO_write(mport,DIO_PIN5 , DIO_LOW);

			_delay_ms(speed);
			DIO_write(mport,DIO_PIN1 , DIO_LOW);
			DIO_write(mport,DIO_PIN3 , DIO_HIGH);
			DIO_write(mport,DIO_PIN4 , DIO_LOW);
			DIO_write(mport,DIO_PIN5 , DIO_LOW);
			_delay_ms(speed);

			DIO_write(mport,DIO_PIN1 , DIO_HIGH);
			DIO_write(mport,DIO_PIN3 , DIO_LOW);
			DIO_write(mport,DIO_PIN4 , DIO_LOW);
			DIO_write(mport,DIO_PIN5 , DIO_LOW);
			_delay_ms(speed);

			break;
		break;

case HIGH_NIPPLE:
	DIO_write(mport,DIO_PIN4 , DIO_LOW);
	DIO_write(mport,DIO_PIN5 , DIO_LOW);
	DIO_write(mport,DIO_PIN6 , DIO_LOW);
	DIO_write(mport,DIO_PIN7 , DIO_HIGH);


	_delay_ms(speed);
	DIO_write(mport,DIO_PIN4 , DIO_LOW);
	DIO_write(mport,DIO_PIN5 , DIO_LOW);
	DIO_write(mport,DIO_PIN6 , DIO_HIGH);
	DIO_write(mport,DIO_PIN7 , DIO_LOW);

	_delay_ms(speed);
	DIO_write(mport,DIO_PIN4 , DIO_LOW);
	DIO_write(mport,DIO_PIN5 , DIO_HIGH);
	DIO_write(mport,DIO_PIN6 , DIO_LOW);
	DIO_write(mport,DIO_PIN7 , DIO_LOW);
	_delay_ms(speed);

	DIO_write(mport,DIO_PIN4 , DIO_HIGH);
	DIO_write(mport,DIO_PIN5 , DIO_LOW);
	DIO_write(mport,DIO_PIN6 , DIO_LOW);
	DIO_write(mport,DIO_PIN7 , DIO_LOW);
	_delay_ms(speed);

	break;
case LOW_NIPPLE:
	DIO_write(mport,DIO_PIN0 , DIO_LOW);
	DIO_write(mport,DIO_PIN1 , DIO_LOW);
	DIO_write(mport,DIO_PIN2 , DIO_LOW);
	DIO_write(mport,DIO_PIN3 , DIO_HIGH);


		_delay_ms(speed);
		DIO_write(mport,DIO_PIN0 , DIO_LOW);
		DIO_write(mport,DIO_PIN1 , DIO_LOW);
		DIO_write(mport,DIO_PIN2 , DIO_HIGH);
		DIO_write(mport,DIO_PIN3 , DIO_LOW);

		_delay_ms(speed);
		DIO_write(mport,DIO_PIN0 , DIO_LOW);
		DIO_write(mport,DIO_PIN1 , DIO_HIGH);
		DIO_write(mport,DIO_PIN2 , DIO_LOW);
		DIO_write(mport,DIO_PIN3 , DIO_LOW);
		_delay_ms(speed);

		DIO_write(mport,DIO_PIN0 , DIO_HIGH);
		DIO_write(mport,DIO_PIN1 , DIO_LOW);
		DIO_write(mport,DIO_PIN2 , DIO_LOW);
		DIO_write(mport,DIO_PIN3 , DIO_LOW);
		_delay_ms(speed);
	break;

}


	break;
}
}

