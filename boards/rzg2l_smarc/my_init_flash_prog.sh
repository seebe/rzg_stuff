#!/bin/bash
DISK=/dev/mmcblk0
USB_DRIVE=/dev/sda1
FILE_NAME=sd_card.img.gz
BL2=/home/root/bl2_bp.bin
FIP=/home/root/fip.bin
ENV_FINAL_VAR=/home/root/final_env_variables.txt
# Populate /proc /sys /dev
mount -t proc proc /proc
mount -t sysfs sysfs /sys
mount -t devtmpfs none /dev
# Erasing eMMC
echo -e "\n== Destroying Master Boot Record (sector 0) =="
sleep 1
echo dd if=/dev/zero of=${DISK} bs=512 count=1
dd if=/dev/zero of=${DISK} bs=512 count=1
sync
# Waiting for USB
while [ ! -e ${USB_DRIVE} ]; do
    sleep 1
    counter=$((counter + 1))
    if [ $counter -ge 50 ]; then
        exit
    fi
done
# Mounting USB thumb drive
mount ${USB_DRIVE} /mnt
echo "Programming eMMC, it should take 3-5 minutes please wait..."
dd if=/mnt/${FILE_NAME} | gzip -dc | dd of=${DISK} bs=1M
sync
echo "Enlarging ext partition to fit the eMMC size..."
echo ", +" | sfdisk -N 2 ${DISK}
resize2fs "${DISK}p2"
# You may not need to reprogram BL2 and FIP,
# you may just want to modify environment variables however
# this script does both things for the sake of completeness.
echo "Reprogramming BL2 and FIP"
echo "onto eMMC boot partition 0..."
echo 0 > /sys/block/mmcblk0boot0/force_ro  # disable the soft write-protect base
dd if=${BL2} of=/dev/mmcblk0boot0 bs=512 skip=0 seek=1
dd if=${FIP} of=/dev/mmcblk0boot0 bs=512 skip=0 seek=256
echo "... and QSPI"
dd if=/dev/zero of=boot.img bs=1024 count=1024
dd if=${BL2} of=boot.img conv=notrunc
dd if=${FIP} of=boot.img conv=notrunc bs=512 seek=233
flashcp -v boot.img /dev/mtd0
echo "Resetting environment variables"
fw_setenv --script ${ENV_FINAL_VAR}
echo "Printing environment variables.."
fw_printenv
echo "Done"
echo "Wait 5s before reboot"
sleep 5
reboot -f
