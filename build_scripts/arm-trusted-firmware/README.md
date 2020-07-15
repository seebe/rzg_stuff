# arm-trusted-firmware Build Script

This script lets you build the Initial Program Loader (IPL), which is basically the arm-trusted-firmware code base that has been modified for RZ/G **outside** of the Yocto environment.

ARM publishes the arm-trusted-firmware code base. The Renesas R-Car team adds patches on top of that to support Renesas devices and posts that to github. The RZ/G team adds patches on top of the R-Car patches to support RZ/G devices and supplies them inside the Yocto meta layer meta-rzg also on github.
Therefore, in order to reproduce what is being built inside of Yocto, we have to:
1. Clone the r-car repository
2. Clone the meta-rzg2 repository and extract the patch files, then apply them to the r-car code base
3. Reproduce the same configuration options that were outlined in the Yocto build receipt.

That is basically what this script is designed to do.

The script will also copy all the build output files into one place to make it easier to program with flash writer.
 * ./arm-trusted-firmware/z_deploy_emmc
 * ./arm-trusted-firmware/z_deploy_spi

## Directory Location

I would suggest that you keep your arm-trusted-firmware directory at the same directory level as this rzg_stuff repository. If you do that, then the "rzg_stuff/flash_writer/config.ini" file is already set up to pull the binaries directly from your arm-trusted-firmware directory.
For example:
```
├── home
│   └── chris
│       └── rzg2
│           ├── arm-trusted-firmware
│           ├── rzg2_flash_writer
│           └── rzg_stuff

```

## Build Instructions
### Clone and check out R-Car ARM Trusted Firmware repository
```
$ cd /home/chris/rzg2
$ git clone git://github.com/renesas-rcar/arm-trusted-firmware.git
$ cd arm-trusted-firmware
$ git checkout rcar_gen3
```
### Copy in our custom build.sh script
```
$ cp ../rzg_stuff/build_scripts/arm-trusted-firmware/build.sh  .
```

### Choose a specific VLP64 version that you want to build
You can choose to build using the master (latest and greatest) patches, or reproduce a specific VLP64 release.
What we will do is in the arm-trusted-firmware git repository, we will make a new separate branch in order to keep track of what VLP64 version we are trying to reproduce. Also, we will check out and use the same arm-trusted-firmware commit point that the VLP64 Yocto recipe used since we are trying to replicate that as close as we can.

Also note, when the VLP64 BSPs are released from Renesas, they are released as Yocto build. The Yocto recipes include patch files that get applied on top of publicly available repositories. However, these 'patch files' are not all in the same format, so they cannot just be applied to our local git repositories.
Therefore the build script 'make_patches' command will convert them all to the same format.

**Choose one** of the following commands:
```
$ ./build.sh make_patches master
$ ./build.sh make_patches BSP-1.0.2
$ ./build.sh make_patches BSP-1.0.3
$ ./build.sh make_patches BSP-1.0.3-RT
```    
Pay attention to the output of this script

### Apply your patches
The command "$ ./build.sh make_patches xxx " will output a command that you will need to copy/paste and run on the command line. This will create a new branch of your current arm-trusted-firmware repository and then apply these patches on top.
For example, if you selected "BSP-1.0.3", it will output the command line:
```
git checkout -b vlp64_v103 c8b88aa5dc11 ; git am z_patches/vlp64_v103/*
```

## Select the board and boot method
To select the board you would like to build for, please **edit the build.sh** file and make your selection at the top. Selections are made by un-commenting the **MACHINE** line you want (removing the # sign).
By default, SPI Flash boot is assuming. If you want to build an image that boots from eMMC instead, set EMMC_BOOT=1.

For example, to build files for a HiHope RZ/G2M board that will boot from eMMC:
```
# HiHope RZ/G2M
MACHINE=hihope-rzg2m
EMMC_BOOT=1
```

## Build the arm-trusted-firmware code
Finally, to build, simply execute the build.sh script without any parameters.
```
./build.sh
```
The output files will be in:
 * ./arm-trusted-firmware/z_deploy_emmc/
 * ./arm-trusted-firmware/z_deploy_spi/

## Programming with flash writer
If you use the "rzg_stuff/flash_writer/flash_writer.sh" script,  it is already set up to pull files from this build process.
Within the **rzg_stuff/flash_writer/confi.ini** file, simply define your **BOARD=** and **FLASH=** settings at the top, and then set (un-comment) **BUILT_OUTSIDE_YOCTO=1** at the bottom.

