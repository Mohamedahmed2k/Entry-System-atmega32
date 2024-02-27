################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EEPROM_INTERNAL/EEPROM_Program.c 

OBJS += \
./MCAL/EEPROM_INTERNAL/EEPROM_Program.o 

C_DEPS += \
./MCAL/EEPROM_INTERNAL/EEPROM_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EEPROM_INTERNAL/%.o: ../MCAL/EEPROM_INTERNAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


