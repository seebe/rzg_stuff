## Program Bootloaders using internal ROM and Flashwriter

### Description
The RZ/G2 has a built-in ROM for downloading a binary to internal RAM and then executing it.

That downloaded binary is call "Flash Writer" and is supplied with the VLP64 BSP.

This script helps automate the process of programming a SPI flash but download image over a serial port to the board.

If using a Renesas evaluation board, you can use the 'switches' command to print out how you need to modify the on-board switches to get into the correct modes.

### Commands
    ./scif_loader flashwriter       # Must be run first
    ./scif_loader  sa0              # programs SA0
    ./scif_loader  bl2              # programs BL2
    ./scif_loader  sa6              # programs SA6
    ./scif_loader  bl31             # programs BL31
    ./scif_loader  uboot            # programs u-boot
    ./scif_loader  all              # programs sa0,bl2,sa6,bl31,uboot all at once
    ./scif_loader  switches         # Show the switch settings for Renesas boards (in case you forgot)


### Instructions
1. Modify the config.ini file and set "VLP64_BASE" and "BOARD" accordingly.

2. Power off the board

3. In a terminal window, run the follow command to determine the correct switch settings to put the device into SCIF download mode.
`$ ./scif_loader  switches`

4. Power the board

5. Open a 2nd terminal window and type "cat /dev/ttyUSB0" in order to monitor the output from the board. If you press the RESET button the board, you should see a text message "SCIF Download mode .......  please send !"

6. Execute the follow command to download the flash writer binary
`./scif_loader flashwriter`

7. Execute the following commands:
`$ ./scif_loader  sa0`
`$ ./scif_loader  bl2`
`$ ./scif_loader  sa6`
`$ ./scif_loader  bl31`
`$ ./scif_loader  uboot`

Or, just use this command to program everything at once:
`$ ./scif_loader  all              # programs sa0,bl2,sa6,bl31,uboot all at once`


