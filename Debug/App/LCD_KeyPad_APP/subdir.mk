################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/LCD_KeyPad_APP/LCD_KeyPad_Program.c 

OBJS += \
./App/LCD_KeyPad_APP/LCD_KeyPad_Program.o 

C_DEPS += \
./App/LCD_KeyPad_APP/LCD_KeyPad_Program.d 


# Each subdirectory must supply rules for building sources it contributes
App/LCD_KeyPad_APP/%.o: ../App/LCD_KeyPad_APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


