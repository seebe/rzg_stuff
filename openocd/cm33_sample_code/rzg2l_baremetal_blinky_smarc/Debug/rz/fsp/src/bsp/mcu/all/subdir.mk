################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rz/fsp/src/bsp/mcu/all/bsp_clocks.c \
../rz/fsp/src/bsp/mcu/all/bsp_common.c \
../rz/fsp/src/bsp/mcu/all/bsp_delay.c \
../rz/fsp/src/bsp/mcu/all/bsp_group_irq.c \
../rz/fsp/src/bsp/mcu/all/bsp_guard.c \
../rz/fsp/src/bsp/mcu/all/bsp_io.c \
../rz/fsp/src/bsp/mcu/all/bsp_irq.c \
../rz/fsp/src/bsp/mcu/all/bsp_irqs.c \
../rz/fsp/src/bsp/mcu/all/bsp_sbrk.c \
../rz/fsp/src/bsp/mcu/all/bsp_security.c 

OBJS += \
./rz/fsp/src/bsp/mcu/all/bsp_clocks.o \
./rz/fsp/src/bsp/mcu/all/bsp_common.o \
./rz/fsp/src/bsp/mcu/all/bsp_delay.o \
./rz/fsp/src/bsp/mcu/all/bsp_group_irq.o \
./rz/fsp/src/bsp/mcu/all/bsp_guard.o \
./rz/fsp/src/bsp/mcu/all/bsp_io.o \
./rz/fsp/src/bsp/mcu/all/bsp_irq.o \
./rz/fsp/src/bsp/mcu/all/bsp_irqs.o \
./rz/fsp/src/bsp/mcu/all/bsp_sbrk.o \
./rz/fsp/src/bsp/mcu/all/bsp_security.o 

C_DEPS += \
./rz/fsp/src/bsp/mcu/all/bsp_clocks.d \
./rz/fsp/src/bsp/mcu/all/bsp_common.d \
./rz/fsp/src/bsp/mcu/all/bsp_delay.d \
./rz/fsp/src/bsp/mcu/all/bsp_group_irq.d \
./rz/fsp/src/bsp/mcu/all/bsp_guard.d \
./rz/fsp/src/bsp/mcu/all/bsp_io.d \
./rz/fsp/src/bsp/mcu/all/bsp_irq.d \
./rz/fsp/src/bsp/mcu/all/bsp_irqs.d \
./rz/fsp/src/bsp/mcu/all/bsp_sbrk.d \
./rz/fsp/src/bsp/mcu/all/bsp_security.d 


# Each subdirectory must supply rules for building sources it contributes
rz/fsp/src/bsp/mcu/all/%.o: ../rz/fsp/src/bsp/mcu/all/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -D_RENESAS_RZ_ -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz_gen" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/src" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/fsp/inc" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/board/rzg2l_ek" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz_cfg/fsp_cfg/bsp" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/fsp/inc/instances" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/fsp/src/bsp/mcu/rzg2l" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/fsp/inc/api" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz_cfg/fsp_cfg" -O0 -g3 -Wall -c -fmessage-length=0 -mthumb -mfloat-abi=soft -mcpu=cortex-m33+nodsp+nofp -mcmse -fdiagnostics-parseable-fixits -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -Wnull-dereference -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


