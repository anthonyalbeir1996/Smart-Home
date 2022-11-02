################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 03-App/subdir.mk
-include 02-HAL/Dimmer/src/subdir.mk
-include 02-HAL/16-led_Dimmer/src/subdir.mk
-include 02-HAL/15-Ulrasonic/Src/subdir.mk
-include 02-HAL/14-Stepper_Motor/Src/subdir.mk
-include 02-HAL/13-Bluetooth/Src/subdir.mk
-include 02-HAL/12-DC_Motor/Src/subdir.mk
-include 02-HAL/11-Servo_Motor/Src/subdir.mk
-include 02-HAL/10-EEPROM_ext/Src/subdir.mk
-include 02-HAL/09-Buzzer/Src/subdir.mk
-include 02-HAL/08-LM35/Src/subdir.mk
-include 02-HAL/07-Keypad/Src/subdir.mk
-include 02-HAL/06-SSD/Src/subdir.mk
-include 02-HAL/05-LCD/Src/subdir.mk
-include 02-HAL/02-BUTTON/Src/subdir.mk
-include 02-HAL/01-LED/Src/subdir.mk
-include 01-MCAL/UART/source/subdir.mk
-include 01-MCAL/Timer/WDT/src/subdir.mk
-include 01-MCAL/Timer/Timer2/src/subdir.mk
-include 01-MCAL/Timer/Timer1/src/subdir.mk
-include 01-MCAL/Timer/Timer0/src/subdir.mk
-include 01-MCAL/TWI/Source/subdir.mk
-include 01-MCAL/SPI/Source/subdir.mk
-include 01-MCAL/GINT/source/subdir.mk
-include 01-MCAL/EXT_INT/source/subdir.mk
-include 01-MCAL/EEPROM_int/Src/subdir.mk
-include 01-MCAL/DIO/Src/subdir.mk
-include 01-MCAL/ADC/source/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := smart-home
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
smart-home.lss \

FLASH_IMAGE += \
smart-home.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: smart-home.elf secondary-outputs

# Tool invocations
smart-home.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,smart-home.map -mmcu=atmega16 -o "smart-home.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

smart-home.lss: smart-home.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S smart-home.elf  >"smart-home.lss"
	@echo 'Finished building: $@'
	@echo ' '

smart-home.hex: smart-home.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex smart-home.elf  "smart-home.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: smart-home.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 smart-home.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) smart-home.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
