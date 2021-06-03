arm-none-eabi-objcopy -O binary -R .secure %1.elf %1_nonsecure.bin
arm-none-eabi-objcopy -O binary -R .text -R .ARM.extab -R .ARM.exidx -R .data %1.elf %1_secure.bin 
