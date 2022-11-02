################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../01-MCAL/Timer/Timer2/src/Timer2.c 

OBJS += \
./01-MCAL/Timer/Timer2/src/Timer2.o 

C_DEPS += \
./01-MCAL/Timer/Timer2/src/Timer2.d 


# Each subdirectory must supply rules for building sources it contributes
01-MCAL/Timer/Timer2/src/%.o: ../01-MCAL/Timer/Timer2/src/%.c 01-MCAL/Timer/Timer2/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\ADC\inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\Dimmer\inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\16-led_Dimmer\inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\03-App" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\DIO\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\EEPROM_int\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\EXT_INT\inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\GINT\inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\SPI\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\Timer\lib" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\Timer\Timer0\inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\Timer\Timer1\inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\Timer\Timer2\inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\Timer\WDT\inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\TWI\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\01-MCAL\UART\inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\01-LED\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\02-BUTTON\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\05-LCD\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\06-SSD\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\07-Keypad\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\08-LM35\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\09-Buzzer\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\10-EEPROM_ext\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\11-Servo_Motor\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\12-DC_Motor\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\13-Bluetooth\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\14-Stepper_Motor\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\02-HAL\15-Ulrasonic\Inc" -I"C:\Users\Anthony\OneDrive\Desktop\eclipse amit\smart-home\00-library" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


