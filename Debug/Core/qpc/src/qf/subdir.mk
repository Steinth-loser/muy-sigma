################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/qpc/src/qf/qep_hsm.c \
../Core/qpc/src/qf/qep_msm.c \
../Core/qpc/src/qf/qf_act.c \
../Core/qpc/src/qf/qf_actq.c \
../Core/qpc/src/qf/qf_defer.c \
../Core/qpc/src/qf/qf_dyn.c \
../Core/qpc/src/qf/qf_mem.c \
../Core/qpc/src/qf/qf_ps.c \
../Core/qpc/src/qf/qf_qact.c \
../Core/qpc/src/qf/qf_qeq.c \
../Core/qpc/src/qf/qf_qmact.c \
../Core/qpc/src/qf/qf_time.c 

OBJS += \
./Core/qpc/src/qf/qep_hsm.o \
./Core/qpc/src/qf/qep_msm.o \
./Core/qpc/src/qf/qf_act.o \
./Core/qpc/src/qf/qf_actq.o \
./Core/qpc/src/qf/qf_defer.o \
./Core/qpc/src/qf/qf_dyn.o \
./Core/qpc/src/qf/qf_mem.o \
./Core/qpc/src/qf/qf_ps.o \
./Core/qpc/src/qf/qf_qact.o \
./Core/qpc/src/qf/qf_qeq.o \
./Core/qpc/src/qf/qf_qmact.o \
./Core/qpc/src/qf/qf_time.o 

C_DEPS += \
./Core/qpc/src/qf/qep_hsm.d \
./Core/qpc/src/qf/qep_msm.d \
./Core/qpc/src/qf/qf_act.d \
./Core/qpc/src/qf/qf_actq.d \
./Core/qpc/src/qf/qf_defer.d \
./Core/qpc/src/qf/qf_dyn.d \
./Core/qpc/src/qf/qf_mem.d \
./Core/qpc/src/qf/qf_ps.d \
./Core/qpc/src/qf/qf_qact.d \
./Core/qpc/src/qf/qf_qeq.d \
./Core/qpc/src/qf/qf_qmact.d \
./Core/qpc/src/qf/qf_time.d 


# Each subdirectory must supply rules for building sources it contributes
Core/qpc/src/qf/%.o Core/qpc/src/qf/%.su Core/qpc/src/qf/%.cyclo: ../Core/qpc/src/qf/%.c Core/qpc/src/qf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/ports/arm-cm/qv/gnu" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/include" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/src/qf" -I"C:/Users/th3ka/OneDrive/Masaüstü/muy_2.2.0/sigma/Core/qpc/src/qv" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-qpc-2f-src-2f-qf

clean-Core-2f-qpc-2f-src-2f-qf:
	-$(RM) ./Core/qpc/src/qf/qep_hsm.cyclo ./Core/qpc/src/qf/qep_hsm.d ./Core/qpc/src/qf/qep_hsm.o ./Core/qpc/src/qf/qep_hsm.su ./Core/qpc/src/qf/qep_msm.cyclo ./Core/qpc/src/qf/qep_msm.d ./Core/qpc/src/qf/qep_msm.o ./Core/qpc/src/qf/qep_msm.su ./Core/qpc/src/qf/qf_act.cyclo ./Core/qpc/src/qf/qf_act.d ./Core/qpc/src/qf/qf_act.o ./Core/qpc/src/qf/qf_act.su ./Core/qpc/src/qf/qf_actq.cyclo ./Core/qpc/src/qf/qf_actq.d ./Core/qpc/src/qf/qf_actq.o ./Core/qpc/src/qf/qf_actq.su ./Core/qpc/src/qf/qf_defer.cyclo ./Core/qpc/src/qf/qf_defer.d ./Core/qpc/src/qf/qf_defer.o ./Core/qpc/src/qf/qf_defer.su ./Core/qpc/src/qf/qf_dyn.cyclo ./Core/qpc/src/qf/qf_dyn.d ./Core/qpc/src/qf/qf_dyn.o ./Core/qpc/src/qf/qf_dyn.su ./Core/qpc/src/qf/qf_mem.cyclo ./Core/qpc/src/qf/qf_mem.d ./Core/qpc/src/qf/qf_mem.o ./Core/qpc/src/qf/qf_mem.su ./Core/qpc/src/qf/qf_ps.cyclo ./Core/qpc/src/qf/qf_ps.d ./Core/qpc/src/qf/qf_ps.o ./Core/qpc/src/qf/qf_ps.su ./Core/qpc/src/qf/qf_qact.cyclo ./Core/qpc/src/qf/qf_qact.d ./Core/qpc/src/qf/qf_qact.o ./Core/qpc/src/qf/qf_qact.su ./Core/qpc/src/qf/qf_qeq.cyclo ./Core/qpc/src/qf/qf_qeq.d ./Core/qpc/src/qf/qf_qeq.o ./Core/qpc/src/qf/qf_qeq.su ./Core/qpc/src/qf/qf_qmact.cyclo ./Core/qpc/src/qf/qf_qmact.d ./Core/qpc/src/qf/qf_qmact.o ./Core/qpc/src/qf/qf_qmact.su ./Core/qpc/src/qf/qf_time.cyclo ./Core/qpc/src/qf/qf_time.d ./Core/qpc/src/qf/qf_time.o ./Core/qpc/src/qf/qf_time.su

.PHONY: clean-Core-2f-qpc-2f-src-2f-qf

