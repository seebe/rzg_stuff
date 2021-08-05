#!/bin/bash

# By default, it will assume you are running this script from the base of the
# Yocto BSP directory. Since the BSP does not build Flash Writer yet, we'll
# provide one here.
#
# To use your own files:
# Set (export) on command line before calling this script if you want to specify your own files.
# For example, to use the files in the build_script
#
#   $ export FILE_FLASHWRITER=build_scripts/output/Flash_Writer_SCIF_RZG2L_SMARC_DDR4_2GB.mot
#   $ export FILE_BL2=build_scripts/output/bl2_bp-smarc-rzg2l.srec
#   $ export FILE_FIP=build_scripts/output/fip-smarc-rzg2l.srec
#   $ ./program_bootloaders.sh


if [ -z "$FILE_FLASHWRITER" ] ; then
  FILE_FLASHWRITER=Flash_Writer_SCIF_RZG2L_SMARC_DDR4_2GB.mot
fi
if [ -z "$FILE_BL2" ] ; then
  FILE_BL2=build/tmp/deploy/images/smarc-rzg2l/bl2_bp-smarc-rzg2l.srec
fi
if [ -z "$FILE_FIP" ] ; then
  FILE_FIP=build/tmp/deploy/images/smarc-rzg2l/fip-smarc-rzg2l.srec
fi
echo -e "\nFILE_FLASHWRITER = $FILE_FLASHWRITER\nFILE_BL2 = $FILE_BL2\nFILE_FIP = $FILE_FIP\n\n"

# File check
if [ ! -e "$FILE_FLASHWRITER" ] ; then
  echo "ERROR: $FILE_FLASHWRITER does not exits"
  exit
fi
if [ ! -e "$FILE_BL2" ] ; then
  echo "ERROR: $FILE_BL2 does not exits"
  exit
fi
if [ ! -e "$FILE_FIP" ] ; then
  echo "ERROR: $FILE_FIP does not exits"
  exit
fi

# USB connection check
SERIAL_DEVICE_INTERFACE=/dev/ttyUSB0
if [ ! -e "$SERIAL_DEVICE_INTERFACE" ] ; then
  echo "ERROR: Serial console connection not plugged in. Interface $SERIAL_DEVICE_INTERFACE not detected."
  exit
fi

# Turn off some conversions that disrupt sending binary files over tty connections.
# These are already the defaults for /dev/ttyUSB0, so this requirement is really only for
# when using /dev/ttyACM0
stty min 1 time 0 -brkint -icrnl ixoff -imaxbel -opost -onlcr -isig -icanon -echo -echoe -F $SERIAL_DEVICE_INTERFACE 115200


echo -n "
Set switches SW11 on Carrier board to \"SCIF Download Mode\".

SW11-1 = OFF
SW11-2 = ON
SW11-3 = OFF
SW11-4 = ON

      +---------+
      | ON      |
 SW11 |   =   = |
      | =   =   |
      | 1 2 3 4 |
      +---------+

Press Enter to continue..."
read dummy


echo "Downloading Flash Writer loader..."

stat -L --printf="%s bytes\n" $FILE_FLASHWRITER
dd if=$FILE_FLASHWRITER of=$SERIAL_DEVICE_INTERFACE bs=1k status=progress
sleep 1

# It will take about 10 seconds to complete.
# Then,you should see
#
# Flash writer for RZ/G2L Series V0.85 Jan.25,2021
# >

# flush RX buffer
echo -en "\r" > $SERIAL_DEVICE_INTERFACE

echo "Erasing Flash..."
echo -en "xcs\r" > $SERIAL_DEVICE_INTERFACE
sleep 1
echo -en "y\r" > $SERIAL_DEVICE_INTERFACE
sleep 2

echo "Programming bl2_bp..."
echo -en "xls2\r" > $SERIAL_DEVICE_INTERFACE
sleep 1
echo -en "11E00\r" > $SERIAL_DEVICE_INTERFACE
sleep 1
echo -en "0000\r" > $SERIAL_DEVICE_INTERFACE
sleep 3
stat -L --printf="%s bytes\n" $FILE_BL2
dd if=$FILE_BL2 of=$SERIAL_DEVICE_INTERFACE bs=1k status=progress
#cat output/bl2_bp.srec > $SERIAL_DEVICE_INTERFACE
sleep 1
#echo -en "y\r" > $SERIAL_DEVICE_INTERFACE

if [ "${FILE_FIP: -4}" == "srec" ] ; then

echo "Programming fip..."
echo -en "xls2\r" > $SERIAL_DEVICE_INTERFACE
sleep 1
echo -en "0000\r" > $SERIAL_DEVICE_INTERFACE
sleep 1
echo -en "1D200\r" > $SERIAL_DEVICE_INTERFACE
sleep 3
stat -L --printf="%s bytes\n" $FILE_FIP
dd if=$FILE_FIP of=$SERIAL_DEVICE_INTERFACE bs=1k status=progress
sleep 4
#echo -en "y\r" > $SERIAL_DEVICE_INTERFACE

fi

if [ "${FILE_FIP: -3}" == "bin" ] ; then

	echo "Sorry, programming .bin files does not work yet :("
	exit

	echo "Programming fip..."
	echo -en "xls3\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1

	# get the file size of our binary
	SIZE_DEC=$(stat -L --printf="%s" $FILE_FIP)
	SIZE_HEX=$(printf '%X' $SIZE_DEC)
	echo -en "$SIZE_HEX\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1

	# SPI address
	echo -en "1D200\r" > $SERIAL_DEVICE_INTERFACE
	sleep 2

	echo "Sending file..."
	stat -L --printf="%s bytes\n" $FILE_FIP
	dd if=$FILE_FIP of=$SERIAL_DEVICE_INTERFACE bs=1k status=progress
	sleep 1

	# You only need to send a 'y', not the 'y' + CR. But, if the flash is already
	# blank, flash writer will not ask you to confirm, so we send y + CR
	# just in case. So if the flash is already blank you will just see an
	# extra 'command not found' message which does not hurt anything.
	echo -en "y\r" > $SERIAL_DEVICE_INTERFACE
	sleep 1
	echo ""

fi


echo "
Set Mode pins for SPI Boot Mode.

 SW11-1 = OFF
 SW11-2 = OFF
 SW11-3 = OFF
 SW11-4 = ON

      +---------+
      | ON      |
 SW11 |       = |
      | = = =   |
      | 1 2 3 4 |
      +---------+

Change from on-board eMMC to SD Card socket

On the SOM (CPU) board, there is a little switch (SW1) by the SD card socket.
Set both 1 and 2 to the \"ON\" position.

 SW1-1 = ON
 SW1-2 = ON
      +-----+
      | ON  |
      | = = |
      |     |
      | 1 2 |
      +-----+

=> setenv bootargs 'root=/dev/mmcblk1p2 rootwait'
=> setenv bootcmd 'mmc dev 1;fatload mmc 1:1 0x48080000 Image-smarc-rzg2l.bin; fatload mmc 1:1 0x48000000 r9a07g044l2-smarc.dtb; booti 0x48080000 - 0x48000000'
=> setenv bootcmd 'mmc dev 1;fatload mmc 1:1 0x48080000 Image; fatload mmc 1:1 0x48000000 r9a07g044l2-smarc.dtb; booti 0x48080000 - 0x48000000'

# SD card in the SOM board:
 SW1-1 = ON
 SW1-2 = ON
      +-----+
      | ON  |
      | = = |
      |     |
      | 1 2 |
      +-----+
=> mmc dev 0 ; fatload mmc 0:1 0x48080000 Image ; fatload mmc 0:1 0x48000000 r9a07g044l2-smarc.dtb
=> setenv bootargs 'root=/dev/mmcblk0p2 rootwait' ; booti 0x48080000 - 0x48000000

# SD card in the Carrier board:
 SW1-1 = ON
 SW1-2 = OFF
      +-----+
      | ON  |
      | =   |
      |   = |
      | 1 2 |
      +-----+
=> mmc dev 1 ; fatload mmc 1:1 0x48080000 Image ; fatload mmc 1:1 0x48000000 r9a07g044l2-smarc.dtb
=> setenv bootargs 'root=/dev/mmcblk1p2 rootwait' ; booti 0x48080000 - 0x48000000


"

