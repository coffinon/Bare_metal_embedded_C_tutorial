################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Interrupts_with_priorities.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Interrupts_with_priorities.list \

OBJCOPY_BIN += \
Interrupts_with_priorities.bin \


# All Target
all: Interrupts_with_priorities.elf secondary-outputs

# Tool invocations
Interrupts_with_priorities.elf: $(OBJS) $(USER_OBJS) C:\Users\skorp\Desktop\projects\Bare_metal_embedded_C_tutorial\Interrupts_with_priorities\STM32F103RBTX_FLASH.ld
	arm-none-eabi-gcc -o "Interrupts_with_priorities.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\skorp\Desktop\projects\Bare_metal_embedded_C_tutorial\Interrupts_with_priorities\STM32F103RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Interrupts_with_priorities.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Interrupts_with_priorities.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Interrupts_with_priorities.list"
	@echo 'Finished building: $@'
	@echo ' '

Interrupts_with_priorities.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Interrupts_with_priorities.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
