# Partitioning Script
This script will erase and reformat a **USB Flash drive** or **SD Card** (via USB card reader) so that it can be used for RZ/G Linux systems.


## Partion Types
It will have 2 partions:

1. FAT16 partition (that can be access by Windows)
2. ext3 partion that can hold a Linux file system.

## Partion Sizes
The **500MB partition** size is recomended because it doesn't really hold anything else other than the kernel and device tree. But, you might want to copy something into this partition (like an MP3, a JPG or maybe a demo app) from a Windows machine so that you can use access it on your board after it boots up.

The **max** partition size is default because it will alwasy work for any size drive. However you don't really need a lot of space, and the bigger you make it, the longer it takes to format. I woudl say **2GB** is about as much as you need for the file system.

## Partion Lables
The script also assigns volume labels to the partions: **RZ_FAT ** and **RZ_ext**.
This makes the partitions easy to identify in your Linux host machine.
In Ubuntu, when you plug this formatted drive in, they partitions should automatically get mapped to the following locations:

* /media/chris/RZ_FAT
* /media/chris/RZ_ext

(of course, 'chris' will be your username instead)


## Usage
* Plug in a USB Flash drive

* Run:   $ sudo ./usb_partition.sh

* Remove the drive (first, right click on USB icon on Desktop and select "Eject")

* Insert the drive back in

