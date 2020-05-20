# initramfs and programming eMMC

## Introduction to initramfs
--------------------------------------------------------------------------------
I'm not going to go into great detail on what initrd and initramfs is. I'll just summarize it this way:

When a kernel boot, it needs something to run at the end. We call that a file system, and that can be on a hard drive, SD card, eMMC, etc...
But, there were times when the kernel needed to run executable sand scripts BEFORE it could mount that file system.....something in between the end of kernel boot and mounting the root file system.
So, initrd (old away) and initramfs (new way) are used.
Basically, you are making a mini file system that only sits in RAM along with the kernel (hence, nothing to be 'mounted').
And for that mini file system, you can include the entire thing inside the actual kernel binary itself (you point to it in a menuconfig setting), or you manually load it into RAM memory before you boot and pass the physical RAM address to the kernel.

Now, if you want to learn even more, you can start reading here:
https://www.kernel.org/doc/Documentation/filesystems/ramfs-rootfs-initramfs.txt

And of course Google 'to your heart's content' on all the different uses of intiramfs.


## Why this is useful for programming new boards
--------------------------------------------------------------------------------
When you make a board, all the flash parts are blank.
For the RZ/G2, there is a utility (flash writer) to at least program the bootloader over a serial link.
However, trying to program an entire eMMC over a UART serial link would be quite painful (take a lot time).

But, you could easily use your normal kernel with a file system that is contained entirely in ram (ie, intiramfs) and then use Linux to load your eMMC however you like.

Basically use flash writer to program u-boot, and then use u-boot to start up your kernel+initramfs. From there, your will have plenty of options on how you can get your file system image into eMMC (copy from and SD card, copy over USB, copy over Ethernet, etc..)


## Instructions for programming eMMC
--------------------------------------------------------------------------------
If you've already read all this, or you don't really care you just want the 'answer', here it is.
By default, the RZ/G2 BSP kernels already have initramfs enabled by default.
The file **rzg2_initramfs.cpio.gz** in this repository should work with any RZ/G2 board, so you can just use it as is instead of building it yourself (as discussed later in this document).
Also, we assume you have a disk image file that you already created using the "image_creator" script for example.

1. Copy file rzg2_initramfs.cpio.gz to an SD card (or USB Flash drive) where you also have your kernel and Device Tree. For example, the FAT16 Partition 1.
2. Copy your file system image (.img or .img.gz file) that you want to program into eMMC to SD card (or USB Flash drive). For example, the FAT16 Partition 1. A compressed img.gz file should be small enough to fit in that FAT16 partition.
3. Power on your RZ/G2 board, but press the space bar on your keyboard to make it stop in u-boot (not auto boot)
4. Copy/Paste these commands into u-boot:

    => fatload mmc 0:1 0x48080000 Image-hihope-rzg2m_initramfs.bin ; fatload mmc 0:1 0x48000000 Image-r8a774a1-hihope-rzg2m-ex.dtb
    => fatload mmc 0:1 0x49000000 rzg2_initramfs.cpio.gz
    => setenv bootargs 'initrd=0x49000000,32M' ;  booti 0x48080000 - 0x48000000

5. Log in as root (no password needed)
6. Mount your SD card so you can get at your files

NOTE: On the HiHope board, the Device Tree is configured such that:
 * eMMC = /dev/mmcblk0
 * SD Card = /dev/mmcblk1
 * USB Flash Drive = /dev/sda

Mount SD Card on HiHope:

    $ mount /dev/mmcblk1p1 /mnt
    $ ls -l /mnt

Mount USB Flash Drive on HiHope:

    $ mount /dev/sda1 /mnt
    $ ls -l /mnt


7. Copy your image from SD Card (or USB Flash drive) into eMMC

* If you have a raw uncompressed image (MBR, partition table and all) .img file, as in, it's a 6GB file, then you can use 'dd'

    $ dd if=/mnt/rzg2m_buildroot.img of=/dev/mmcblk0 bs=1M conv=fsync

* If you have a raw uncompressed image (MBR, partition table and all), but you compressed it with gzip (.img.gz file) to make it smaller when copying on (as in, it's a 500MB file), then you can use gunzip to decompress and pipe it directly into dd to program it directly into your eMMC.

    $ gunzip -cfk /mnt/rzg2m_buildroot.img.gz | dd of=/dev/mmcblk0 bs=1M conv=fsync

8. Rescan and check eMMC partition (Optional, not really needed, and might be confusing, skip if not sure)
* If you want the kernel to re-scan you eMMC to see if your partitions show up, you will need to unbind (logically disconnect) the device driver, then bind (logically connect) it back again.

 * Rescan an eMMC on channel 0

       $ echo ee100000.sd > /sys/bus/platform/drivers/renesas_sdhi_internal_dmac/unbind
       $ echo ee100000.sd > /sys/bus/platform/drivers/renesas_sdhi_internal_dmac/bind

 * Rescan an eMMC on channel 1

       $ echo ee160000.sd > /sys/bus/platform/drivers/renesas_sdhi_internal_dmac/unbind
       $ echo ee160000.sd > /sys/bus/platform/drivers/renesas_sdhi_internal_dmac/bind

* NOTE: On the HiHope boards:
  * SD/MMC Channel 0 ("ee100000.sd") is connected to the SD Card socket
  * SD/MMC Channel 1 ("ee160000.sd") is connected to the eMMC chip

 * NOTE: When you unbind and bind again, you will get a different mmc block number. Meaning /dev/mmcblk0 will be /dev/mmcblk2 after re-binding.

9. Boot kernel using eMMC file system
Reset your board (power switch) and once again stop it in u-boot by pressing the space bar (or any keyboard key).
Enter the commands below to boot your system. They are actually almost the same as the default commands, but we need to change bootargs so root will be mmcblk0p2 (instead of the default mmcblk1p2)

    => fatload mmc 0:1 0x48080000 Image-hihope-rzg2m.bin; fatload mmc 0:1 0x48000000 Image-r8a774a1-hihope-rzg2m-ex.dtb
    => setenv bootargs 'root=/dev/mmcblk0p2 rootwait'
    => booti 0x48080000 - 0x48000000

10. done. enjoy.


# Use Buildroot to create your rootfs to use a initramfs
--------------------------------------------------------------------------------
These steps are for if you want to know how that rzg2_initramfs.cpio.gz file (mini file system) was created.
We first need to create a separate mini file system.
I would not recommended using Yoto for this because it would way to complicated and big for what you really want.
Instead, I would just use Buildroot. It's simple and small and will get the job done quite nicely.

## Download and build Buildroot for RZ/G2
--------------------------------------------------------------------------------
Get the latest stable version of Buildroot. (https://buildroot.org/)
I happened to use Buildroot 2020.02.1

    $ wget https://buildroot.org/downloads/buildroot-2020.02.1.tar.bz2
    $ tar xf buildroot-2020.02.1.tar.bz2

Copy in buildroot_rzg2_defconfig to the base of your Buildroot  directory and rename it to .config

 * NOTE: The packages dosfstools (for mkfs.fat) and e2fsprogs (for mkfs.ext4) were added because they are helpful in setting up a eMMC. You can see them set inside the buildroot_rzg2_defconfig file.

Do an initial build of Buildroot. All you should have to do is just run 'make' in the Buildroot directory. Buildroot will take care of downloading a toolchain and the appropriate source packages.

    $ make


## Changes to busybox to be initramfs compatible
--------------------------------------------------------------------------------
There are some changes that are needed for Buidlroot and busybox if you want to use them for initramfs.
Honestly, unless someone tells you, you could spend hours trying to figure these out for the first time.

 * In your Buildroot directory

       $ make busybox-menuconfig

 * Then in the busybox settings menu, find this setting to enable static builds.

       Settings -> 
       --- Build Options
       [*] Build static binary (no shared libs)
 
 * Build Buildroot again.

       $ make


## Extract your Buildroot output
--------------------------------------------------------------------------------
Extract your buildroot/output/images/rootfs.tar file someplace on your PC.
If you exact this with 'sudo', then all your files will be owned by root, which will make more sense to your board since it will run as root.

    (assumes you start in the Buildroot directory)
    $ cd ..
    $ mkdir rootfs
    $ cd rootfs
    $ sudo ../buildroot/output/images/rootfs.tar

Now you will have a directory 'rootfs' at the same level as your buildroot directory.


## Add console and null to /dev
--------------------------------------------------------------------------------
You need to make a /dev/console device node, otherwise /etc/init.d/rcS won't run.
You'll see the message: "Warning: unable to open an initial console."
The early init process wants /dev/null, so we'll make that one too.
That is all we really need to make because soon /dev will get populated and everything else will get created automatically. So really, /dev/console and /dev/null are the bare minimum we need.

To make the node (assuming you are in your rootfs directory):

    $ cd dev
    $ sudo mknod console c 5 1
    $ sudo mknod null c 1 3
    $ cd ..

## Add a command to populate /dev directory
--------------------------------------------------------------------------------
Normally, the /dev directory is automatically populated with your devices when the following are configured in your kernel:
 * CONFIG_DEVTMPFS=y
 * CONFIG_DEVTMPFS_MOUNT=y
 
However, this is only done AFTER a root filesystem has been mounted. When using an initramfs, we stop the kernel 
before it mounts a root file system (since initramfs was intended to do things before this happened). This
means /dev will have nothing in it (and that is not good).

So to fix this, we need to modify the default init script that Buildroot creates for us and add this line:

1. Edit the 'inittab' file rootfs/etc/inittab

       $ sudo gedit etc/inittab

2. Add a coomand to 'mount -t devtmpfs' as the first operation to do, even before mounting /proc

For Example:

    # Startup the system
    ::sysinit:/bin/mount -t devtmpfs none /dev   # Manually mount /dev when using initramfs
    ::sysinit:/bin/mount -t proc proc /proc
    ::sysinit:/bin/mount -o remount,rw /
    ::sysinit:/bin/mkdir -p /dev/pts /dev/shm

3. Save and exit the text editor


## Create the file /init that the kernel will look for
--------------------------------------------------------------------------------
When kernel boots, and after the initramfs has been copied into tmpfs, the kernel will check to see if there is the file /init (meaning an executable file named init at the root).
If the file exists, then the kernel will run that. If the file does not exists, it will then attempt to mount a root file system and then check that file system for the file /sbin/init.

Normally when you build a root file system using something like Buildroot or Yocto, you are not going to have a /init file. But, if you are going to turn that root file system into a initramfs
file system, you are going to have to place in a /init.

For busybox, individual executable are all just  symlinks back to busybox (busybox is the only really executable, everything is just links back to it).

So at the base of your root file system that you plan to turn into an initramfs, enter this command:

(Assuming you are at the base of your rootfs directory)

    $ sudo ln -s bin/busybox init

This will make a link file named 'init' which points to busybox.
Hopefully you should end up with something like this:

    $ ls -l init
    lrwxrwxrwx 1 root root 11 May 18 15:56 init -> bin/busybox


## Create an initramfs file (rzg2_initramfs.cpio.gz)
--------------------------------------------------------------------------------
In the base of your rootfs directory, use the command below to create your cpio.gz file.

    $ sudo find . | sudo cpio --quiet -H newc -o | sudo gzip -9 -n > ../rzg2_initramfs.cpio.gz


## Your own custom init script
--------------------------------------------------------------------------------
You don't actually have to call Buildroot's init.
You can make your own that is basically a shell script.
That way after the kernel boots, the kernel will run your script and say program your eMMC and be done.

For example:

----------------------------------------
    #!/bin/sh
    
    echo "RZ/G2 initramfs script"
    mount -t devtmpfs none /dev
    mount -t proc proc /proc
    mount -t sysfs sysfs /sys
    
    # drop to a shell prompt (no login)
    /bin/sh
-------------------------------------------------
