################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/stm32f429xx_gpio.c 

OBJS += \
./Drivers/Src/stm32f429xx_gpio.o 

C_DEPS += \
./Drivers/Src/stm32f429xx_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F427ZITx -c -I../Inc -I"C:/Users/natanael.matias/STM32CubeIDE/workspace_1.13.1/STM32-Course/GPIO_TEST/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/stm32f429xx_gpio.cyclo ./Drivers/Src/stm32f429xx_gpio.d ./Drivers/Src/stm32f429xx_gpio.o ./Drivers/Src/stm32f429xx_gpio.su

.PHONY: clean-Drivers-2f-Src

