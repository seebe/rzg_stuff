#!/bin/bash

# Assumes FTDI USB Serial Device converter attached as ttyUSB0

# Read in our settings
source config.ini

if [ "$BOARD" == "" ] ; then
	echo "ERROR: Board not selected in config.ini"
	echo "Please edit config.ini in a text editor before continuing"
	exit
fi

if [ "$BOARD" == "ek874" ] ; then

	BOARD_NAME="Silicon Linux RZ/G2E evaluation kit (EK874)"

	SW_SETTINGS="
Switch settings for SW12 which is placed near the micro SD card slot.\n
Please TURN OFF board power when changing switch settings.\n
\n
\tSerial Flash ROM boot (default) \n
\t----------------------------------\n
\t1 = ON\n\t2 = ON\n\t3 = ON\n\t4 = OFF\n\t5 = ON\n\t6 = ON\n
\n
\tSCIF Download mode\n
\t----------------------------------\n
\t1 = OFF\n\t2 = OFF\n\t3 = OFF\n\t4 = OFF\n\t5 = ON\n\t6 = ON\n
"
fi

if [ "$BOARD" == "hihope-rzg2m" ] || [ "$BOARD" == "hihope-rzg2n" ] || \
   [ "$BOARD" == "hihope-rzg2h" ] ; then

	BOARD_NAME="Hoperun Technology HiHope"
	if [ "$BOARD" == "hihope-rzg2m" ] ; then BOARD_NAME="$BOARD_NAME RZ/G2M" ; fi
	if [ "$BOARD" == "hihope-rzg2n" ] ; then BOARD_NAME="$BOARD_NAME RZ/G2N" ; fi
	if [ "$BOARD" == "hihope-rzg2h" ] ; then BOARD_NAME="$BOARD_NAME RZ/G2H" ; fi

	SW_SETTINGS="
Switch settings for SW1002.\n
Please TURN OFF board power when changing switch settings.\n
\n
\tSerial Flash ROM boot (default) \n
\t----------------------------------\n
\t1 = ON\n\t2 = ON\n\t3 = ON\n\t4 = ON\n\t5 = ON\n\t6 = OFF\n\t7 = ON\n\t8 = ON\n
\n
\tSCIF Download mode\n
\t----------------------------------\n
\t1 = ON\n\t2 = ON\n\t3 = ON\n\t4 = ON\n\t5 = OFF\n\t6 = OFF\n\t7 = OFF\n\t8 = OFF\n
"
fi

# Common settings
if [ "$BOARD" == "ek874" ] || [ "$BOARD" == "hihope-rzg2m" ] || \
   [ "$BOARD" == "hihope-rzg2n" ] || [ "$BOARD" == "hihope-rzg2h" ] ; then
	VLP64_DEPLOY=$VLP64_BASE/build/tmp/deploy/images/${BOARD}
	FLASHWRITER=$VLP64_DEPLOY/AArch64_Flash_writer_SCIF_DUMMY_CERT_E6300400_${BOARD}.mot
	SA0_SREC=$VLP64_DEPLOY/bootparam_sa0.srec
	BL2_SREC=$VLP64_DEPLOY/bl2-${BOARD}.srec
	SA6_SREC=$VLP64_DEPLOY/cert_header_sa6.srec
	BL31_SREC=$VLP64_DEPLOY/bl31-${BOARD}.srec
	UBOOT_SREC=$VLP64_DEPLOY/u-boot-elf-${BOARD}.srec
fi

do_xls2() {
	#Note: Need to send a CR + NL (\r\n) at the end of each command
	echo "Writting $1"
	echo "Sending XLS2 command..."
	echo -en "XLS2\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "$2\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "$3\r\n" > /dev/ttyUSB0
	sleep 1
	echo "Sending file..."
	cat $4 > /dev/ttyUSB0
	sleep 1
	echo -en "y\r\n" > /dev/ttyUSB0
	sleep 1
	echo ""
}

# Usage is displayed when no arguments on comamnd line
if [ "$1" == "" ] ; then
	echo "Usage:"
	echo "$0 flashwriter      # Must be run first"
	echo ""
	echo "$0 sa0              # programs SA0"
	echo "$0 bl2              # programs BL2"
	echo "$0 sa6              # programs SA6"
	echo "$0 bl31             # programs BL31"
	echo "$0 uboot            # programs u-boot"
	echo "$0 all              # programs sa0,bl2,sa6,bl31,uboot all at once"
	echo ""
	echo "$0 switches         # Show the switch settings for Renesas boards (in case you forgot)"
	exit
fi

# Print current selected board
echo "Board: $BOARD_NAME"
echo ""

if [ "$1" == "flashwriter" ] ; then
	echo "-----------------------------------------------------------------"
	echo " Make sure the board is configured for \"SCIF Download mode"\"
	echo " Power on the board and press the RESET button."
	echo " Then, press ENTER on the keyboard to continue."
	echo "-----------------------------------------------------------------"
	read dummy
	echo "Sending Flash Writter Binary..."
	cat $FLASHWRITER > /dev/ttyUSB0
	sleep 1
	# Clear out the extra left over characters
	echo -en "\r\n" > /dev/ttyUSB0
	echo "Complete"
	exit
fi

if [ "$1" == "switches" ] ; then
	echo -e $SW_SETTINGS
	exit
fi

if [ "$1" == "sa0" ] || [ "$1" == "all" ] ; then
	do_xls2 "bootparam SA0" E6320000 000000 $SA0_SREC
fi

if [ "$1" == "bl2" ] || [ "$1" == "all" ] ; then
	do_xls2 "BL2" E6304000 040000 $BL2_SREC
fi

if [ "$1" == "sa6" ] || [ "$1" == "all" ] ; then
	do_xls2 "Cert Header SA6" E6320000 180000 $SA6_SREC
fi

if [ "$1" == "bl31" ] || [ "$1" == "all" ] ; then
	do_xls2 "BL31" 44000000 1C0000 $BL31_SREC
fi

if [ "$1" == "uboot" ] || [ "$1" == "all" ] ; then
	do_xls2 "u-boot" 50000000 300000 $UBOOT_SREC
fi

echo "done"


#bootparam_sa0.srec gets written to E6320000 (begining of SystemRAM)

# ATF - S-Record Versions
# /home/renesas/rzg/arm-trusted-firmware/z_deploy/bootparam_sa0.srec
# /home/renesas/rzg/arm-trusted-firmware/z_deploy/bl2-ek874.srec
# /home/renesas/rzg/arm-trusted-firmware/z_deploy/cert_header_sa6.srec
# /home/renesas/rzg/arm-trusted-firmware/z_deploy/bl31-ek874.srec


# ATF - Binary Versions
# /home/renesas/rzg/arm-trusted-firmware/tools/dummy_create/bootparam_sa0.bin
# /home/renesas/rzg/arm-trusted-firmware/tools/dummy_create/cert_header_sa6.bin
# /home/renesas/rzg/arm-trusted-firmware/build/rcar/release/bl2.bin
# /home/renesas/rzg/arm-trusted-firmware/build/rcar/release/bl31.bin

