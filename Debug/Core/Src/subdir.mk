################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/PID.c \
../Core/Src/bsp.c \
../Core/Src/crc.c \
../Core/Src/dma.c \
../Core/Src/esc.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/rtc.c \
../Core/Src/sdio.c \
../Core/Src/servo.c \
../Core/Src/sigma.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/tim.c \
../Core/Src/time_date.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/PID.o \
./Core/Src/bsp.o \
./Core/Src/crc.o \
./Core/Src/dma.o \
./Core/Src/esc.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/rtc.o \
./Core/Src/sdio.o \
./Core/Src/servo.o \
./Core/Src/sigma.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/tim.o \
./Core/Src/time_date.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/PID.d \
./Core/Src/bsp.d \
./Core/Src/crc.d \
./Core/Src/dma.d \
./Core/Src/esc.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/rtc.d \
./Core/Src/sdio.d \
./Core/Src/servo.d \
./Core/Src/sigma.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/tim.d \
./Core/Src/time_date.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/ports/arm-cm/qv/gnu" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/include" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/src/qf" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/src/qv" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/PID.cyclo ./Core/Src/PID.d ./Core/Src/PID.o ./Core/Src/PID.su ./Core/Src/bsp.cyclo ./Core/Src/bsp.d ./Core/Src/bsp.o ./Core/Src/bsp.su ./Core/Src/crc.cyclo ./Core/Src/crc.d ./Core/Src/crc.o ./Core/Src/crc.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/esc.cyclo ./Core/Src/esc.d ./Core/Src/esc.o ./Core/Src/esc.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/rtc.cyclo ./Core/Src/rtc.d ./Core/Src/rtc.o ./Core/Src/rtc.su ./Core/Src/sdio.cyclo ./Core/Src/sdio.d ./Core/Src/sdio.o ./Core/Src/sdio.su ./Core/Src/servo.cyclo ./Core/Src/servo.d ./Core/Src/servo.o ./Core/Src/servo.su ./Core/Src/sigma.cyclo ./Core/Src/sigma.d ./Core/Src/sigma.o ./Core/Src/sigma.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/tim.cyclo ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/time_date.cyclo ./Core/Src/time_date.d ./Core/Src/time_date.o ./Core/Src/time_date.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

