################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/stm32f429xx_gpio.c \
../Drivers/Src/stm32f42xxx_exti.c \
../Drivers/Src/stm32f42xxx_nvic.c 

OBJS += \
./Drivers/Src/stm32f429xx_gpio.o \
./Drivers/Src/stm32f42xxx_exti.o \
./Drivers/Src/stm32f42xxx_nvic.o 

C_DEPS += \
./Drivers/Src/stm32f429xx_gpio.d \
./Drivers/Src/stm32f42xxx_exti.d \
./Drivers/Src/stm32f42xxx_nvic.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F427ZITx -c -I../Inc -I"C:/Users/natan/Desktop/Cursos/STM32-Course/GPIO_TEST/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/stm32f429xx_gpio.cyclo ./Drivers/Src/stm32f429xx_gpio.d ./Drivers/Src/stm32f429xx_gpio.o ./Drivers/Src/stm32f429xx_gpio.su ./Drivers/Src/stm32f42xxx_exti.cyclo ./Drivers/Src/stm32f42xxx_exti.d ./Drivers/Src/stm32f42xxx_exti.o ./Drivers/Src/stm32f42xxx_exti.su ./Drivers/Src/stm32f42xxx_nvic.cyclo ./Drivers/Src/stm32f42xxx_nvic.d ./Drivers/Src/stm32f42xxx_nvic.o ./Drivers/Src/stm32f42xxx_nvic.su

.PHONY: clean-Drivers-2f-Src

