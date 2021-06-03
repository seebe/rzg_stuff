################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include rz_gen/subdir.mk
-include rz/fsp/src/r_ioport/subdir.mk
-include rz/fsp/src/r_gtm/subdir.mk
-include rz/fsp/src/bsp/mcu/rzg2l/subdir.mk
-include rz/fsp/src/bsp/mcu/all/subdir.mk
-include rz/fsp/src/bsp/cmsis/Device/RENESAS/Source/subdir.mk
-include rz/board/rzg2l_ek/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: rzg2l_baremetal_blinky_smarc

# Tool invocations
rzg2l_baremetal_blinky_smarc: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	arm-none-eabi-gcc -L"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/script" -T fsp.ld --entry=Reset_Handler_S -march=armv8-m.main  -Wl,--start-group  -Wl,--end-group -nostartfiles -Xlinker --gc-sections -Wl,-Map,"rzg2l_baremetal_blinky_smarc.map" --specs=nano.specs -o "rzg2l_baremetal_blinky_smarc" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) rzg2l_baremetal_blinky_smarc
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
