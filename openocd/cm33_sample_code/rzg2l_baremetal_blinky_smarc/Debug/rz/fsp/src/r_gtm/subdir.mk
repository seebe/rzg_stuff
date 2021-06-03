################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rz/fsp/src/r_gtm/r_gtm.c 

OBJS += \
./rz/fsp/src/r_gtm/r_gtm.o 

C_DEPS += \
./rz/fsp/src/r_gtm/r_gtm.d 


# Each subdirectory must supply rules for building sources it contributes
rz/fsp/src/r_gtm/%.o: ../rz/fsp/src/r_gtm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -D_RENESAS_RZ_ -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz_gen" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/src" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/fsp/inc" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/board/rzg2l_ek" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz_cfg/fsp_cfg/bsp" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/fsp/inc/instances" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/fsp/src/bsp/mcu/rzg2l" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz/fsp/inc/api" -I"/home/micbis/rzg_stuff/openocd/cm33_sample_code/rzg2l_baremetal_blinky_smarc/rz_cfg/fsp_cfg" -O0 -g3 -Wall -c -fmessage-length=0 -mthumb -mfloat-abi=soft -mcpu=cortex-m33+nodsp+nofp -mcmse -fdiagnostics-parseable-fixits -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -Wnull-dereference -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


