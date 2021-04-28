#!/bin/bash

if [ ! -e "/dev/ttyUSB0" ] ; then
  echo "ERROR: Serial console connection not plugged in. Interface /dev/ttyUSB0 not detected."
  exit
fi

# Turn off some conversions that disrupt sending binary files over tty connections.
# These are already the defaults for /dev/ttyUSB0, so this requirement is really only for
# when using /dev/ttyACM0
stty min 1 time 0 -brkint -icrnl ixoff -imaxbel -opost -onlcr -isig -icanon -echo -echoe -F /dev/ttyUSB0 115200

# Working directory needs to be the base directory
if [ ! -e meta-rzg2 ] ; then
  cd ..
fi


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

FILE_FLASHWRITER=Flash_Writer_SCIF_RZG2L_SMARC_DDR4_2GB.mot
FILE_BL2=build/tmp/deploy/images/smarc-rzg2l/bl2_bp-smarc-rzg2l.srec
FILE_FIP=build/tmp/deploy/images/smarc-rzg2l/fip-smarc-rzg2l.srec


stat -L --printf="%s bytes\n" $FILE_FLASHWRITER
dd if=$FILE_FLASHWRITER of=/dev/ttyUSB0 bs=1k status=progress
sleep 1

# It will take about 10 seconds to complete.
# Then,you should see
#
# Flash writer for RZ/G2L Series V0.85 Jan.25,2021
# >

# flush RX buffer
echo -en "\r" > /dev/ttyUSB0

echo "Erasing Flash..."
echo -en "xcs\r" > /dev/ttyUSB0
sleep 1
echo -en "y\r" > /dev/ttyUSB0
sleep 2

echo "Programming bl2_bp.srec..."
echo -en "xls2\r" > /dev/ttyUSB0
sleep 1
echo -en "11E00\r" > /dev/ttyUSB0
sleep 1
echo -en "0000\r" > /dev/ttyUSB0
sleep 3
stat -L --printf="%s bytes\n" $FILE_BL2
dd if=$FILE_BL2 of=/dev/ttyUSB0 bs=1k status=progress
#cat output/bl2_bp.srec > /dev/ttyUSB0
sleep 1
#echo -en "y\r" > /dev/ttyUSB0


echo "Programming fip.srec..."
echo -en "xls2\r" > /dev/ttyUSB0
sleep 1
echo -en "0000\r" > /dev/ttyUSB0
sleep 1
echo -en "1D200\r" > /dev/ttyUSB0
sleep 3
stat -L --printf="%s bytes\n" $FILE_FIP
dd if=$FILE_FIP of=/dev/ttyUSB0 bs=1k status=progress
sleep 4
#echo -en "y\r" > /dev/ttyUSB0

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

