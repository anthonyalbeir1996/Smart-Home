#include "Led_Interface.h"
#include "Bluetooth_Interface.h"
#include "EEPROM_Interface_int.h"
#include "Servo_Motor_Inteface.h"
#include "Lcd_Interface.h"
#include "Keypad_Interface.h"
#include "DC_Motor_Interface.h"
#include "LM35_Interface.h"
#include <string.h>
#include "Timer0_Interface.h"

//#include "Dimmer_Interface.h"
                                // variables
u8 error=5; // to enhance the reading from LM35
s8 * str; // for storing String
s8 mode=-1; // mode between guest and admin
u8 true=0; // to get into the loop of bluetooth
u8 admin=0; // to get into the loop of admin
u8 guest=0; // to get into the loop of guest
u8 allowing1=0; // to make admin give access to guest
u8 name[15]={0}; // to recive the string from bluetooth
u8 read=0; // for reading from LM35
u8 arr[4]; // to convert from u8 to string for LCD

                             // Functions

void Start_Fane(void);
void Stop_Fane(void);
void Check_Fane(void);
void Blutooth_Fn(u8 data,s8 m);

int main(void)
{
	// Initiating the project
	LM35_Int();
	Led_Init();
	Bluetooth_Init();
	Servo_Motor_Int();
	Servo_Motor_Rotat(5);
	Lcd_Int();
	Keypad_Int();
	DC_Motor_Int();
	//Dimmer_Int();
//Dimmer_duty(0);
	// Some commands for LCD
	Lcd_Cmd(_LCD_CLEAR);
	Lcd_Cmd(_LCD_CURSOR_OFF);

	// the password of admin
	EEPROM_internal_Write(0,"admin");

// interrupt for checking about the fane
Timer0_Delay(1000, Check_Fane);

	label:
	Lcd_Cmd(_LCD_CLEAR);
Lcd_Display_str("    Welcome    ");
str = (s8 *)"Write your password";
Bluetooth_TransmitString(str);
true=1;
GINT_DISABLE_INTERRUPT();

while(1)
{

// bluetooth loop
	while(true)
	{


		if(strcmp(UART1_Rx_Str(),"admin")==0)
		{

			Lcd_Cmd(_LCD_CLEAR);
		Lcd_Display_str("Welcome Admin");
			Bluetooth_TransmitString("Welcome Admin ");
admin=1;
Bluetooth_TransmitString("Write ur command");
			while(admin)
			{

			Blutooth_Fn(Bluetooth_Receive(),1);
			_delay_ms(500);
			}
		}

		else if(strcmp("guest",UART1_Rx_Str())==0)
			{
			Lcd_Cmd(_LCD_CLEAR);
		Lcd_Display_str("Welcome Guest");
			Bluetooth_TransmitString("Welcome Guest");

							guest=1;
							if(allowing1==1)
							{
								while(guest)
											{

												Blutooth_Fn(Bluetooth_Receive(),0);
											}
							}
							else
							{
								Lcd_Goto_Row_Column(1, 0);
								Lcd_Display_str("         ");
								Lcd_Goto_Row_Column(1, 0);
								Lcd_Display_str("No permission");
								Bluetooth_TransmitString("No permission");
							}

			}




		else if(strcmp(UART1_Rx_Str(),"exit")==0) {
			true=0;
			Lcd_Cmd(_LCD_CLEAR);
			Lcd_Display_str("Exiting from blutooth");
Bluetooth_TransmitString("Exiting from blutooth");

	}


			else if (strcmp(EEPROM_internal_Read(0),name)!=0 &&strcmp(UART1_Rx_Str(),"exit")!=0 &&
					strcmp(UART1_Rx_Str(),"guest")!=0)
		{
				Lcd_Cmd(_LCD_CLEAR);
				Lcd_Display_str("Wrong password");

			Bluetooth_TransmitString("Wrong password");
			for(u8 i=0;i<6;i++)
			{

				name[i]=0;
			}

		}






	}



// enter to the user mode
	if(Keypad_Read()=='S')
	{
		u8 user=1;

Lcd_Cmd(_LCD_CLEAR);
Lcd_Display_str("User mode");
Bluetooth_Transmit(Keypad_Read());
// keypad loop
while(user)
{

	if(Keypad_Read()=='0')
	{
		_delay_ms(300);
		Led_ON(LED0);
Lcd_Goto_Row_Column(1, 0);
Lcd_Display_str("         ");
Lcd_Goto_Row_Column(1, 0);
		Lcd_Display_str("Led0:ON");
		Bluetooth_Transmit(Keypad_Read());
	}
	else if(Keypad_Read()=='1')
	{
		_delay_ms(300);
		Led_OFF(LED0);
		Lcd_Goto_Row_Column(1, 0);
		Lcd_Display_str("         ");
		Lcd_Goto_Row_Column(1, 0);
		Lcd_Display_str("Led0:Off");
		Bluetooth_Transmit(Keypad_Read());
	}
	else if(Keypad_Read()=='2')
	{
		_delay_ms(300);
		Led_ON(LED1);
		Lcd_Goto_Row_Column(1, 0);
		Lcd_Display_str("         ");
		Lcd_Goto_Row_Column(1, 0);
		Lcd_Display_str("Led1:ON");
		Bluetooth_Transmit(Keypad_Read());
	}
	else if(Keypad_Read()=='3')
	{
		_delay_ms(300);
		Led_OFF(LED1);
		Lcd_Goto_Row_Column(1, 0);
		Lcd_Display_str("         ");
		Lcd_Goto_Row_Column(1, 0);
		Lcd_Display_str("Led1:Off");
		Bluetooth_Transmit(Keypad_Read());
	}
	else if(Keypad_Read()=='4')
		{
			_delay_ms(300);
			Led_ON(LED2);
			Lcd_Goto_Row_Column(1, 0);
			Lcd_Display_str("         ");
			Lcd_Goto_Row_Column(1, 0);
			Lcd_Display_str("Led2:ON");
			Bluetooth_Transmit(Keypad_Read());
		}
		else if(Keypad_Read()=='5')
		{
			_delay_ms(300);
			Led_OFF(LED2);
			Lcd_Goto_Row_Column(1, 0);
			Lcd_Display_str("         ");
			Lcd_Goto_Row_Column(1, 0);
			Lcd_Display_str("Led2:Off");
			Bluetooth_Transmit(Keypad_Read());
		}

	else if(Keypad_Read()=='P')
	{
		Bluetooth_Transmit(Keypad_Read());
// to go out from user keypad mode

while(Keypad_Read()=='P')
{
	Check_Fane();
	mode=0;
}

		Lcd_Cmd(_LCD_CLEAR);
		Lcd_Display_str("Going outside ");
	_delay_ms(300);
	goto label;
}

	else
	{

// do nothing

	}



}

 }

}

}

//Fane Fun
void Start_Fane(void)
{
DC_Motor_Set_Direction(CLOCKWISE);
DC_Motor_Speed(99);
DC_Motor_Start();
}
void Stop_Fane(void)
{
DC_Motor_Stop();
}
void Check_Fane(void)
{
	read=LM35_Read();

	sprintf(arr,"%d",read);
	Lcd_Goto_Row_Column(0, 14);
			 Lcd_Display_str(arr);
	if(read>=21+error)
			 {

		Start_Fane();

			 }
			 if(read<21+error)
			 {



				 Stop_Fane();

			 }
}

// Bluetooth Fun
void Blutooth_Fn(u8 data,s8 m)
{

	//mode for user

	 if (m==0)
	{

		switch(data)
			{
			case '0':
				Led_ON(LED0);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led0:ON");
				break;
			case '1':
				Led_OFF(LED0);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led0:Off");
				break;
			case '2':
				Led_ON(LED1);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led1:ON");
				break;
			case '3':
				Led_OFF(LED1);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led1:Off");

				break;

			case '4':
				Led_ON(LED2);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led2:ON");
				break;
			case '5':
				Led_OFF(LED2);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led2:Off");

				break;
			case 'E':
				guest=0;
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Exit done ");
				Bluetooth_TransmitString("Exit done > write the password");
				break;

			}
	}
	 // mode for admin
	else if(m==1)
	{
		switch(data)
			{
			case '0':
				Led_ON(LED0);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led0:ON");
				break;
			case '1':
				Led_OFF(LED0);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led0:Off");
				break;
			case '2':
				Led_ON(LED1);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led1:ON");
				break;
			case '3':
				Led_OFF(LED1);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led1:Off");

				break;

			case '4':
				Led_ON(LED2);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led2:ON");
				break;
			case '5':
				Led_OFF(LED2);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Led2:Off");

				break;

			case 'D':
			Servo_Motor_Rotat(10);
			Lcd_Goto_Row_Column(1, 0);
			Lcd_Display_str("         ");
			Lcd_Goto_Row_Column(1, 0);
					Lcd_Display_str("Door:open");

				break;
			case 'd':
				Servo_Motor_Rotat(5);
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
						Lcd_Display_str("Door:close");
			break;
			case 'G':
				allowing1=1;
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("user 1 allowed");
				Bluetooth_TransmitString("user 1 allowed");
				break;

			case 'g':
				allowing1=0;
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("user 1 not allowed");
				Bluetooth_TransmitString("user 1 not allowed");
				break;

			case 'E':
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("         ");
				Lcd_Goto_Row_Column(1, 0);
				Lcd_Display_str("Exit done");
				Bluetooth_TransmitString("Exit done > write the password");
				admin=0;
				break;
			}
	}

}

