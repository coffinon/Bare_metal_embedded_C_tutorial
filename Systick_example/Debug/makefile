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
Systick_example.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Systick_example.list \

OBJCOPY_BIN += \
Systick_example.bin \


# All Target
all: Systick_example.elf secondary-outputs

# Tool invocations
Systick_example.elf: $(OBJS) $(USER_OBJS) C:\Users\skorp\Desktop\projects\Bare_metal_embedded_C_tutorial\Systick_example\STM32F103RBTX_FLASH.ld
	arm-none-eabi-gcc -o "Systick_example.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\skorp\Desktop\projects\Bare_metal_embedded_C_tutorial\Systick_example\STM32F103RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Systick_example.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Systick_example.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Systick_example.list"
	@echo 'Finished building: $@'
	@echo ' '

Systick_example.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Systick_example.bin"
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
