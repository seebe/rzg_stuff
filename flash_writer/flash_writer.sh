#!/bin/bash

# Assumes FTDI USB Serial Device converter attached as ttyUSB0

# Read in our settings
source config.ini

if [ "$BOARD" == "" ] ; then
	echo "ERROR: Board not selected in config.ini"
	echo "Please edit config.ini in a text editor before continuing"
	exit
fi

# 0 = SPI Flash
# 1 = eMMC
if [ "$FLASH" == "" ] ; then
	echo "ERROR: FLASH not selected in config.ini"
	echo "Please edit config.ini in a text editor before continuing"
	exit
fi

if [ "$BOARD" == "ek874" ] ; then

	BOARD_NAME="Silicon Linux RZ/G2E evaluation kit (EK874)"

	SW_SETTINGS="Switch settings for SW12 which is placed near the micro SD card slot.
Please TURN OFF board power when changing switch settings.

	SPI Flash boot
	----------------------------------
	1 = ON
	2 = ON
	3 = ON
	4 = OFF
	5 = ON
	6 = ON

	SCIF Download mode
	----------------------------------
	1 = OFF
	2 = OFF
	3 = OFF
	4 = OFF
	5 = ON
	6 = ON
"
fi

if [ "$BOARD" == "hihope-rzg2m" ] || [ "$BOARD" == "hihope-rzg2n" ] || \
   [ "$BOARD" == "hihope-rzg2h" ] ; then

	BOARD_NAME="Hoperun Technology HiHope"
	if [ "$BOARD" == "hihope-rzg2m" ] ; then BOARD_NAME="$BOARD_NAME RZ/G2M" ; fi
	if [ "$BOARD" == "hihope-rzg2n" ] ; then BOARD_NAME="$BOARD_NAME RZ/G2N" ; fi
	if [ "$BOARD" == "hihope-rzg2h" ] ; then BOARD_NAME="$BOARD_NAME RZ/G2H" ; fi

	SW_SETTINGS="Switch settings for SW1002.
    ----------  ----------
    | SW1003 |  | SW1002 | << this one
    ----------  ----------
                ----------
                | SW1001 |
                ----------

Please TURN OFF board power when changing switch settings.

	SPI Flash boot              eMMC boot
	--------------              ---------
	1 = ON                      1 = ON
	2 = ON                      2 = ON
	3 = ON                      3 = ON
	4 = ON                      4 = ON
	5 = ON                      5 = OFF
	6 = OFF                     6 = OFF
	7 = ON                      7 = ON
	8 = ON                      8 = OFF


	SCIF Download mode         USB Download mode
	------------------         -----------------
	1 = ON                      1 = ON
	2 = ON                      2 = ON
	3 = ON                      3 = ON
	4 = ON                      4 = ON
	5 = OFF                     5 = OFF
	6 = OFF                     6 = OFF
	7 = OFF                     7 = OFF
	8 = OFF                     8 = ON
"
fi

# Common settings
if [ "$BOARD" == "ek874" ] || [ "$BOARD" == "hihope-rzg2m" ] || \
   [ "$BOARD" == "hihope-rzg2n" ] || [ "$BOARD" == "hihope-rzg2h" ] ; then

	if [ "$FILES_DIR" == "" ] ; then
		FILES_DIR=$VLP64_BASE/build/tmp/deploy/images/${BOARD}
	fi
	if [ "$FLASHWRITER" == "" ] ; then
		FLASHWRITER=$FILES_DIR/AArch64_Flash_writer_SCIF_DUMMY_CERT_E6300400_${BOARD}.mot
	fi
	if [ "$SA0_SREC" == "" ] ; then
		SA0_SREC=$FILES_DIR/bootparam_sa0.srec
	fi
	if [ "$BL2_SREC" == "" ] ; then
		BL2_SREC=$FILES_DIR/bl2-${BOARD}.srec
	fi
	if [ "$SA6_SREC" == "" ] ; then
		SA6_SREC=$FILES_DIR/cert_header_sa6.srec
	fi
	if [ "$BL31_SREC" == "" ] ; then
		BL31_SREC=$FILES_DIR/bl31-${BOARD}.srec
	fi
	if [ "$UBOOT_SREC" == "" ] ; then
		UBOOT_SREC=$FILES_DIR/u-boot-elf-${BOARD}.srec
	fi
fi

do_xls2() {
	#Note: Need to send a CR + NL (\r\n) at the end of each command
	echo "Writting $1 ($4)"
	echo "Sending XLS2 command..."
	echo -en "XLS2\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "$2\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "$3\r\n" > /dev/ttyUSB0
	sleep 1
	echo "Sending file..."
	#cat $4 > /dev/ttyUSB0
	stat --printf="%s bytes\n" $4
	dd if=$4 of=/dev/ttyUSB0 bs=1k status=progress
	sleep 1
	echo -en "y\r\n" > /dev/ttyUSB0
	sleep 1
	echo ""
}

do_em_w() {
	#Note: Need to send a CR + NL (\r\n) at the end of each command
	echo "Writting $1 ($5)"
	echo "Sending EM_W command..."
	echo -en "EM_W\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "$2\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "$3\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "$4\r\n" > /dev/ttyUSB0
	sleep 1
	echo "Sending file..."
	#cat $5 > /dev/ttyUSB0
	stat --printf="%s bytes\n" $5
	dd if=$5 of=/dev/ttyUSB0 bs=1k status=progress
	sleep 1
	echo ""
}


# Usage is displayed when no arguments on comamnd line
if [ "$1" == "" ] ; then
	echo "Usage:"
	echo "$0 fw               # Downloads the flash writer program after RESET (must be run first)"
	echo ""
	echo "$0 sa0              # programs SA0 (Boot Parameters)"
	echo "$0 bl2              # programs BL2 (Trusted Boot Firmware)"
	echo "$0 sa6              # programs SA6 (Cert Header)"
	echo "$0 bl31             # programs BL31 (EL3 Runtime Software)"
	echo "$0 uboot            # programs u-boot (BL33, Non-trusted Firmware)"
	echo "$0 all              # programs sa0,bl2,sa6,bl31,uboot all at once"
	echo ""
	echo "$0 emmc_config      # Configure an eMMC for booting (only needed once)"
	echo ""
	echo "$0 sw               # Show the switch settings for Renesas boards (in case you forgot)"
	echo ""
	echo "   Note: You can also pass a filename on the command line."
	echo "         Example: $ $0 sa0 ../../arm-trusted-firmware/tools/dummy_create/bootparam_sa0.srec"
	exit
fi

# Print current selected board
echo "Board: $BOARD_NAME"
echo ""

if [ "$1" == "fw" ] ; then

	if [ "$2" != "" ] ; then
		FLASHWRITER=$2
	fi

	echo "-----------------------------------------------------------------"
	echo " Make sure the board is configured for \"SCIF Download mode"\"
	echo " Power on the board and press the RESET button."
	echo " Then, press ENTER on the keyboard to continue."
	echo "-----------------------------------------------------------------"
	read dummy
	echo "Sending Flash Writter Binary ($FLASHWRITER)"
	stat --printf="%s bytes\n" $FLASHWRITER
	#cat $FLASHWRITER > /dev/ttyUSB0
	dd if=$FLASHWRITER of=/dev/ttyUSB0 bs=1k status=progress
	sleep 1
	# Clear out the extra left over characters
	echo -en "\r\n" > /dev/ttyUSB0
	echo "Complete"
	exit
fi

if [ "$1" == "sw" ] ; then
	printf '%s\n' "$SW_SETTINGS"
	exit
fi

if [ "$1" == "emmc_config" ] ; then

	echo "Setting EXT_CSD regiser 179..."

	# Set the EXT_CSD register byte179, PARTITION_CONFIG bit[6] = H??0(No boot acknowledge sent).
	# Set the EXT_CSD register byte179, PARTITION_CONFIG bit[5:3] = H??1 (Boot Area partition1).
	echo -en "EM_SECSD\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "b1\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "0a\r\n" > /dev/ttyUSB0
	sleep 1

	# Set the EXT_CSD register byte177, BOOT_BUS_CONDITIONS bit[4:3] = H??1(50MHz SDR).
	# Set the EXT_CSD register byte177, BOOT_BUS_CONDITIONS bit[1:0] = H??2(x8 bus widths).
	echo "Setting EXT_CSD regiser 177..."
	echo -en "EM_SECSD\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "b3\r\n" > /dev/ttyUSB0
	sleep 1
	echo -en "08\r\n" > /dev/ttyUSB0
	sleep 1
fi


if [ "$1" == "sa0" ] || [ "$1" == "all" ] ; then
	if [ "$2" != "" ] ; then
		SA0_SREC=$2
	fi

	if [ "$FLASH" == "0" ] ; then
		do_xls2 "bootparam SA0" E6320000 000000 $SA0_SREC
	else
		do_em_w "bootparam SA0" 1 000000 E6320000 $SA0_SREC
	fi
fi

if [ "$1" == "bl2" ] || [ "$1" == "all" ] ; then
	if [ "$2" != "" ] ; then
		BL2_SREC=$2
	fi
	if [ "$FLASH" == "0" ] ; then
		do_xls2 "BL2" E6304000 040000 $BL2_SREC
	else
		do_em_w "BL2" 1 00001E E6304000 $BL2_SREC
	fi
fi

if [ "$1" == "sa6" ] || [ "$1" == "all" ] ; then
	if [ "$2" != "" ] ; then
		SA6_SREC=$2
	fi
	if [ "$FLASH" == "0" ] ; then
		do_xls2 "Cert Header SA6" E6320000 180000 $SA6_SREC
	else
		do_em_w "Cert Header SA6" 1 000180 E6320000 $SA6_SREC
	fi
fi

if [ "$1" == "bl31" ] || [ "$1" == "all" ] ; then
	if [ "$2" != "" ] ; then
		BL31_SREC=$2
	fi
	if [ "$FLASH" == "0" ] ; then
		do_xls2 "BL31" 44000000 1C0000 $BL31_SREC
	else
		do_em_w "BL31" 1 000200 44000000 $BL31_SREC
	fi
fi

if [ "$1" == "uboot" ] || [ "$1" == "all" ] ; then
	if [ "$2" != "" ] ; then
		UBOOT_SREC=$2
	fi
	if [ "$FLASH" == "0" ] ; then
		do_xls2 "u-boot" 50000000 300000 $UBOOT_SREC
	else
		do_em_w "u-boot" 2 000000 50000000 $UBOOT_SREC
	fi
fi

echo "done"

