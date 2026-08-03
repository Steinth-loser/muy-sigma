################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/qpc/ports/arm-cm/qv/gnu/qv_port.c 

OBJS += \
./Core/qpc/ports/arm-cm/qv/gnu/qv_port.o 

C_DEPS += \
./Core/qpc/ports/arm-cm/qv/gnu/qv_port.d 


# Each subdirectory must supply rules for building sources it contributes
Core/qpc/ports/arm-cm/qv/gnu/%.o Core/qpc/ports/arm-cm/qv/gnu/%.su Core/qpc/ports/arm-cm/qv/gnu/%.cyclo: ../Core/qpc/ports/arm-cm/qv/gnu/%.c Core/qpc/ports/arm-cm/qv/gnu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/ports/arm-cm/qv/gnu" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/include" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/src/qf" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/src/qv" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-qpc-2f-ports-2f-arm-2d-cm-2f-qv-2f-gnu

clean-Core-2f-qpc-2f-ports-2f-arm-2d-cm-2f-qv-2f-gnu:
	-$(RM) ./Core/qpc/ports/arm-cm/qv/gnu/qv_port.cyclo ./Core/qpc/ports/arm-cm/qv/gnu/qv_port.d ./Core/qpc/ports/arm-cm/qv/gnu/qv_port.o ./Core/qpc/ports/arm-cm/qv/gnu/qv_port.su

.PHONY: clean-Core-2f-qpc-2f-ports-2f-arm-2d-cm-2f-qv-2f-gnu

