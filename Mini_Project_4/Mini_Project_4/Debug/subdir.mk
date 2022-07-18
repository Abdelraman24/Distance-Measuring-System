################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MY_GPIO_Driver.c \
../MY_ICU_Driver.c \
../MY_LCD_Driver.c \
../Mini_Project_4.c \
../Ultra_Sonic_Driver.c 

OBJS += \
./MY_GPIO_Driver.o \
./MY_ICU_Driver.o \
./MY_LCD_Driver.o \
./Mini_Project_4.o \
./Ultra_Sonic_Driver.o 

C_DEPS += \
./MY_GPIO_Driver.d \
./MY_ICU_Driver.d \
./MY_LCD_Driver.d \
./Mini_Project_4.d \
./Ultra_Sonic_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


