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

# Set default tty interface if not set
if [ "$SERIAL_DEVICE_INTERFACE" == "" ] ; then
	SERIAL_DEVICE_INTERFACE=/dev/ttyUSB0
	#SERIAL_DEVICE_INTERFACE=/dev/ttyACM0
fi

# Turn off some conversions that disrupt sending binary files over tty connections.
# These are already the defaults for /dev/ttyUSB0, so this requirement is really only for
# when using /dev/ttyACM0
stty -icrnl -onlcr -isig -icanon -echoe -opost -F $SERIAL_DEVICE_INTERFACE

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
	if [ "$SA0_FILE" == "" ] ; then
		SA0_FILE=$FILES_DIR/bootparam_sa0.srec
	fi
	if [ "$BL2_FILE" == "" ] ; then
		BL2_FILE=$FILES_DIR/bl2-${BOARD}.bin
	fi
	if [ "$SA6_FILE" == "" ] ; then
		SA6_FILE=$FILES_DIR/cert_header_sa6.srec
	fi
	if [ "$BL31_FILE" == "" ] ; then
		BL31_FILE=$FILES_DIR/bl31-${BOARD}.bin
	fi
	if [ "$UBOOT_FILE" == "" ] ; then
		#UBOOT_FILE=$FILES_DIR/u-boot-elf-${BOARD}.srec
		UBOOT_FILE=$FILES_DIR/u-boot.bin
	fi
fi

# do_xls2
# $1 = string
# $2 = RAM address to download to
# $3 = SPI address to write to
# $4 = filename
do_xls2() {
	# Flash writer just looks for CR. If it see LF, it ignores it.
	echo "Writting $1 ($4)"
	echo "Sending XLS2 command..."
	echo -en "XLS2\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "$2\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "$3\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo "Sending file..."
	#cat $4 > $SERIAL_DEVICE_INTERFACE
	stat -L --printf="%s bytes\n" $4
	dd if=$4 of=$SERIAL_DEVICE_INTERFACE bs=1k status=progress
	sleep 1

	# You only need to send a 'y', not the 'y' + CR. But, if the flash is already
	# blank, flash writer will not ask you to confirm, so we send y + CR
	# just in case. So if the flash is already blank you will just see an
	# extra 'command not found' message which does not hurt anything.
	echo -en "y\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo ""
}

# do_xls3
# $1 = string
# $2 = SPI address to write to
# $3 = filename
do_xls3() {
	# Flash writer just looks for CR. It ignores LF characters.
	echo "Writting $1 ($3)"
	echo "Sending XLS3 command..."
	echo -en "XLS3\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1

	# get the file size of our binary
	SIZE_DEC=$(stat -L --printf="%s" $3)
	SIZE_HEX=$(printf '%X' $SIZE_DEC)
	echo -en "$SIZE_HEX\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1

	echo -en "$2\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1

	echo "Sending file..."
	#cat $3 > $SERIAL_DEVICE_INTERFACE
	stat -L --printf="%s bytes\n" $3
	dd if=$3 of=$SERIAL_DEVICE_INTERFACE bs=1k status=progress
	sleep 1

	# You only need to send a 'y', not the 'y' + CR. But, if the flash is already
	# blank, flash writer will not ask you to confirm, so we send y + CR
	# just in case. So if the flash is already blank you will just see an
	# extra 'command not found' message which does not hurt anything.
	echo -en "y\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo ""
}

# do_em_w
# $1 = string
# $2 = partition number
# $3 = eMMC block address to write to
# $4 = RAM address to download to
# $5 = filename
do_em_w() {
	# Flash writer just looks for CR. It ignores LF characters.
	echo "Writting $1 ($5)"
	echo "Sending EM_W command..."
	echo -en "EM_W\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "$2\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "$3\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "$4\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo "Sending file..."
	#cat $5 > $SERIAL_DEVICE_INTERFACE
	stat -L --printf="%s bytes\n" $5
	dd if=$5 of=$SERIAL_DEVICE_INTERFACE bs=1k status=progress
	sleep 1
	echo ""
}

# do_em_wb
# $1 = string
# $2 = partition number
# $3 = eMMC block address to write to
# $4 = filename
do_em_wb() {
	# Flash writer just looks for CR. It ignores LF characters.
	echo "Writting $1 ($4)"
	echo "Sending EM_WB command..."
	echo -en "EM_WB\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "$2\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "$3\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1

	# get the file size of our binary
	SIZE_DEC=$(stat -L --printf="%s" $4)
	SIZE_HEX=$(printf '%X' $SIZE_DEC)
	echo -en "$SIZE_HEX\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1

	echo "Sending file..."
	#cat $4 > $SERIAL_DEVICE_INTERFACE
	stat -L --printf="%s bytes\n" $4
	dd if=$4 of=$SERIAL_DEVICE_INTERFACE bs=1k status=progress
	sleep 1
	echo ""
}

# do_spi_write
# $1 = string
# $2 = RAM address to download to
# $3 = SPI address to write to
# $4 = filename
do_spi_write() {

	# Send a CR (\r) just to make sure there are not extra characters left over from the last transfer
	#echo -en "\r" > $SERIAL_DEVICE_INTERFACE

	# Check if file is SREC or bin
	FILENAME=$(basename $4)
	FILENAME_EXT=`echo ${FILENAME: -5}`
	if [ "$FILENAME_EXT" == ".srec" ] ; then
		# S-Record Write
		do_xls2 "$1" $2 $3 $4
	else
		# Binary Write (RAM address not needed)
		do_xls3 "$1" $3 $4
	fi
}

# do_emmc_write
# $1 = string
# $2 = partition number
# $3 = eMMC starting block to write
# $4 = RAM address to download to
# $5 = filename
do_emmc_write() {
	# Send a CR (\r) just to make sure there are not extra characters left over from the last transfer
	#echo -en "\r" > $SERIAL_DEVICE_INTERFACE

	# Check if file is SREC or bin
	FILENAME=$(basename $5)
	FILENAME_EXT=`echo ${FILENAME: -5}`
	if [ "$FILENAME_EXT" == ".srec" ] ; then
		# S-Record Write
		do_em_w "$1" $2 $3 $4 $5
	else
		# Binary Write
		do_em_wb "$1" $2 $3 $5
	fi
}

# Print current selected board
if [ "$FLASH" == "0" ] ; then
	FLASH_TEXT="SPI Flash"	# 0 = SPI Flash
else
	FLASH_TEXT="eMMC Flash"	# 1 = eMMC
fi
echo "----------------------------------------------------"
echo "   Board: $BOARD_NAME"
echo "  Target: $FLASH_TEXT"
echo "----------------------------------------------------"

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
	stat -L --printf="%s bytes\n" $FLASHWRITER
	#cat $FLASHWRITER > $SERIAL_DEVICE_INTERFACE
	dd if=$FLASHWRITER of=$SERIAL_DEVICE_INTERFACE bs=1k status=progress
	sleep 1
	# Clear out the extra left over characters
	echo -en "\r" > $SERIAL_DEVICE_INTERFACE
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
	echo -en "EM_SECSD\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "b1\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "0a\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1

	# Set the EXT_CSD register byte177, BOOT_BUS_CONDITIONS bit[4:3] = H??1(50MHz SDR).
	# Set the EXT_CSD register byte177, BOOT_BUS_CONDITIONS bit[1:0] = H??2(x8 bus widths).
	echo "Setting EXT_CSD regiser 177..."
	echo -en "EM_SECSD\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "b3\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo -en "08\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
fi


if [ "$1" == "sa0" ] || [ "$1" == "all" ] ; then
	if [ "$2" != "" ] ; then
		SA0_FILE=$2
	fi

	if [ "$FLASH" == "0" ] ; then
		do_spi_write "bootparam SA0" E6320000 000000 $SA0_FILE
	else
		do_emmc_write "bootparam SA0" 1 000000 E6320000 $SA0_FILE
	fi
fi

if [ "$1" == "bl2" ] || [ "$1" == "all" ] ; then
	if [ "$2" != "" ] ; then
		BL2_FILE=$2
	fi
	if [ "$FLASH" == "0" ] ; then
		do_spi_write "BL2" E6304000 040000 $BL2_FILE
	else
		do_emmc_write "BL2" 1 00001E E6304000 $BL2_FILE
	fi
fi

if [ "$1" == "sa6" ] || [ "$1" == "all" ] ; then
	if [ "$2" != "" ] ; then
		SA6_FILE=$2
	fi
	if [ "$FLASH" == "0" ] ; then
		do_spi_write "Cert Header SA6" E6320000 180000 $SA6_FILE
	else
		do_emmc_write "Cert Header SA6" 1 000180 E6320000 $SA6_FILE
	fi
fi

if [ "$1" == "bl31" ] || [ "$1" == "all" ] ; then
	if [ "$2" != "" ] ; then
		BL31_FILE=$2
	fi
	if [ "$FLASH" == "0" ] ; then
		do_spi_write "BL31" 44000000 1C0000 $BL31_FILE
	else
		do_emmc_write "BL31" 1 000200 44000000 $BL31_FILE
	fi
fi

if [ "$1" == "uboot" ] || [ "$1" == "all" ] ; then
	if [ "$2" != "" ] ; then
		UBOOT_FILE=$2
	fi
	if [ "$FLASH" == "0" ] ; then
		do_spi_write "u-boot" 50000000 300000 $UBOOT_FILE
	else
		do_emmc_write "u-boot" 2 000000 50000000 $UBOOT_FILE
	fi
fi

echo "done"

