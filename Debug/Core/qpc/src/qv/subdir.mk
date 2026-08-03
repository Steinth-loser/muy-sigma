################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/qpc/src/qv/qv.c 

OBJS += \
./Core/qpc/src/qv/qv.o 

C_DEPS += \
./Core/qpc/src/qv/qv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/qpc/src/qv/%.o Core/qpc/src/qv/%.su Core/qpc/src/qv/%.cyclo: ../Core/qpc/src/qv/%.c Core/qpc/src/qv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/ports/arm-cm/qv/gnu" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/include" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/src/qf" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/src/qv" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-qpc-2f-src-2f-qv

clean-Core-2f-qpc-2f-src-2f-qv:
	-$(RM) ./Core/qpc/src/qv/qv.cyclo ./Core/qpc/src/qv/qv.d ./Core/qpc/src/qv/qv.o ./Core/qpc/src/qv/qv.su

.PHONY: clean-Core-2f-qpc-2f-src-2f-qv

