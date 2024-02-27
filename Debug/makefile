################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/EEPROM_INTERNAL/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/Led/subdir.mk
-include HAL/Lcd/subdir.mk
-include HAL/KeyPad/subdir.mk
-include HAL/Buzzer/subdir.mk
-include App/LCD_KeyPad_APP/subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Applications.lss \

FLASH_IMAGE += \
Applications.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Applications.elf secondary-outputs

# Tool invocations
Applications.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Applications.map -mmcu=atmega32 -o "Applications.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Applications.lss: Applications.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Applications.elf  >"Applications.lss"
	@echo 'Finished building: $@'
	@echo ' '

Applications.hex: Applications.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Applications.elf  "Applications.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Applications.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Applications.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Applications.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
