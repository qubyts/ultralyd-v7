################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/application/BuzzerTask.c \
../Core/application/DefTask.c \
../Core/application/Myapp.c \
../Core/application/print_server.c 

OBJS += \
./Core/application/BuzzerTask.o \
./Core/application/DefTask.o \
./Core/application/Myapp.o \
./Core/application/print_server.o 

C_DEPS += \
./Core/application/BuzzerTask.d \
./Core/application/DefTask.d \
./Core/application/Myapp.d \
./Core/application/print_server.d 


# Each subdirectory must supply rules for building sources it contributes
Core/application/%.o Core/application/%.su: ../Core/application/%.c Core/application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/Users/metap/git/repository4/ultralydv4/Core/application" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-application

clean-Core-2f-application:
	-$(RM) ./Core/application/BuzzerTask.d ./Core/application/BuzzerTask.o ./Core/application/BuzzerTask.su ./Core/application/DefTask.d ./Core/application/DefTask.o ./Core/application/DefTask.su ./Core/application/Myapp.d ./Core/application/Myapp.o ./Core/application/Myapp.su ./Core/application/print_server.d ./Core/application/print_server.o ./Core/application/print_server.su

.PHONY: clean-Core-2f-application

