################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/states/subdir.mk
-include Core/Src/custom_peripherals/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
AssistantWristband.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
AssistantWristband.list \

OBJCOPY_BIN += \
AssistantWristband.bin \


# All Target
all: AssistantWristband.elf secondary-outputs

# Tool invocations
AssistantWristband.elf: $(OBJS) $(USER_OBJS) C:\Users\DELL\Desktop\AssistantWristband\STM32F411RETX_FLASH.ld
	arm-none-eabi-gcc -o "AssistantWristband.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\DELL\Desktop\AssistantWristband\STM32F411RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="AssistantWristband.map" -Wl,--gc-sections -static -u _printf_float --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

AssistantWristband.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "AssistantWristband.list"
	@echo 'Finished building: $@'
	@echo ' '

AssistantWristband.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "AssistantWristband.bin"
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
