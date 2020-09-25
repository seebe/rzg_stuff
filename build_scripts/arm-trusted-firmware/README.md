# arm-trusted-firmware Build Script

This script lets you build the Initial Program Loader (IPL), which is basically the arm-trusted-firmware code base that has been modified for RZ/G **outside** of the Yocto environment.

**BSP-1.0.0 to BSP-1.0.4:**
ARM publishes the arm-trusted-firmware code base. The Renesas R-Car team adds patches on top of that to support Renesas devices and posts that to github. The RZ/G team adds patches on top of the R-Car patches to support RZ/G devices and supplies them inside the Yocto meta layer meta-rzg also on github.
Therefore, in order to reproduce what is being built inside of Yocto, we have to:
1. Clone the r-car repository
2. Clone the meta-rzg2 repository and extract the patch files, then apply them to the r-car code base
3. Reproduce the same configuration options that were outlined in the Yocto build receipt.

**BSP-1.0.5:**
ARM publishes the arm-trusted-firmware code base. The RZ/G team adds patches including the R-Car patches to support RZ/G devices and supplies them inside the Yocto meta layer meta-rzg on github.
Therefore, in order to reproduce what is being built inside of Yocto, we have to:
1. Clone the official ARM Trusted Firmware repository
2. Clone the meta-rzg2 repository and extract the patch files, then apply them to the code base
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

### Install a Toolchain
You can use the Yocto SDK toolchain from VLP64 v1.0.4 or later.
Or, you can use an external toolchain such as Linaro.
For example:
    **Linaro AArch64 2019.12**
     https://releases.linaro.org/components/toolchain/binaries/
```
$ sudo -p mkdir /opt/linaro
$ cd /opt/linaro
$ sudo https://releases.linaro.org/components/toolchain/binaries/7.5-2019.12/aarch64-linux-gnu/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar.xz
$ sudo tar xf gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar.xz
```

### Clone and patch the ARM Trusted Firmware repository
Use the script **rzg_stuff/vlp64_util.sh** with the "create" command.

For example:
```
$ cd /home/chris/rzg2/rzg_stuff/build_scripts
$ ./vlp64_util.sh create arm-trusted-firmware /home/chris/rzg2
```
### Copy in our custom build.sh script (if not already there)
```
$ cp /home/chris/rzg2/rzg_stuff/build_scripts/arm-trusted-firmware/build.sh  /home/chris/rzg2/arm-trusted-firmware
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

