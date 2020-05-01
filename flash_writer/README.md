## Program Bootloaders using internal ROM and Flashwriter

### Description
The RZ/G2 has a built-in ROM for downloading a binary to internal RAM and then executing it.

That downloaded binary is call "Flash Writer" and is supplied with the VLP64 BSP.

This script helps automate the process of programming a SPI flash or eMMC by download image over a serial port to the board.

If using a Renesas evaluation board, you can use the 'sw' command to print out how you need to modify the on-board switches to get into the correct modes.

### Commands
    ./flash_writer.sh  fw               # Downloads the flash writer program after RESET (must be run first)
    ./flash_writer.sh  sa0              # programs SA0 (Boot Parameters)
    ./flash_writer.sh  bl2              # programs BL2 (Trusted Boot Firmware)
    ./flash_writer.sh  sa6              # programs SA6 (Cert Header)
    ./flash_writer.sh  bl31             # programs BL31 (EL3 Runtime Software)
    ./flash_writer.sh  uboot            # programs u-boot (BL33, Non-trusted Firmware)
    ./flash_writer.sh  all              # programs sa0,bl2,sa6,bl31,uboot all at once
    ./flash_writer.sh  sw               # Show the switch settings for Renesas boards (in case you forgot)
    ./flash_writer.sh  emmc_config      # Configure an eMMC for booting (only needed once)

     Note: You can also pass a filename on the command line.
           Example: $ ./flash_writer.sh sa0 ../../arm-trusted-firmware/tools/dummy_create/bootparam_sa0.srec


### Instructions
1. Modify the config.ini file and set "VLP64_BASE" and "BOARD" accordingly.

2. Power off the board

3. In a terminal window, run the follow command to determine the correct switch settings to put the device into SCIF download mode.
`$ ./flash_writer.sh  sw`

4. Power the board

5. Open a 2nd terminal window and type "cat /dev/ttyUSB0" in order to monitor the output from the board. If you press the RESET button the board, you should see a text message "SCIF Download mode .......  please send !"

6. Execute the follow command to download the flash writer binary. The must be done first after RESET.
`./flash_writer.sh fw`

7. Execute the following commands:
`$ ./flash_writer.sh  sa0`
`$ ./flash_writer.sh  bl2`
`$ ./flash_writer.sh  sa6`
`$ ./flash_writer.sh  bl31`
`$ ./flash_writer.sh  uboot`

Or, just use this command to program everything at once:
`$ ./flash_writer.sh  all              # programs sa0,bl2,sa6,bl31,uboot all at once`

