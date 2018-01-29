################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TWI_Driver/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
TWI_Slave.lss \

FLASH_IMAGE += \
TWI_Slave.hex \

EEPROM_IMAGE += \
TWI_Slave.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: TWI_Slave.elf secondary-outputs

# Tool invocations
TWI_Slave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TWI_Slave.map -mmcu=atmega32 -o "TWI_Slave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TWI_Slave.lss: TWI_Slave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TWI_Slave.elf  >"TWI_Slave.lss"
	@echo 'Finished building: $@'
	@echo ' '

TWI_Slave.hex: TWI_Slave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TWI_Slave.elf  "TWI_Slave.hex"
	@echo 'Finished building: $@'
	@echo ' '

TWI_Slave.eep: TWI_Slave.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex TWI_Slave.elf  "TWI_Slave.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TWI_Slave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TWI_Slave.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TWI_Slave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
