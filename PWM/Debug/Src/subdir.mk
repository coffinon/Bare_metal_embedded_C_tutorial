################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/timer.c 

OBJS += \
./Src/gpio.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/timer.o 

C_DEPS += \
./Src/gpio.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Src/gpio.o: ../Src/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DNUCLEO_F103RB -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DNUCLEO_F103RB -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DNUCLEO_F103RB -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DNUCLEO_F103RB -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/timer.o: ../Src/timer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DNUCLEO_F103RB -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/timer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

