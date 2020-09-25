# renesas-u-boot-cip Build Script

This script lets you build u-boot for RZ/G2 **outside** of the Yocto environment.

## Directory Location

I would suggest that you keep your renesas-u-boot-cip directory at the same directory level as this rzg_stuff repository. If you do that, then the "rzg_stuff/flash_writer/config.ini" file is already set up to pull the binaries directly from renesas-u-boot-cip directory.
For example:
```
├── home
│   └── chris
│       └── rzg2
│           ├── renesas-u-boot-cip
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

### Clone and patch the u-boot repository
Use the script **rzg_stuff/vlp64_util.sh** with the "create" command.

For example:
```
$ cd /home/chris/rzg2/rzg_stuff/build_scripts
$ ./vlp64_util.sh create u-boot /home/chris/rzg2
```
### Copy in our custom build.sh script (if not already there)
```
$ cp /home/chris/rzg2/rzg_stuff/build_scripts/u-boot/build.sh  /home/chris/rzg2/renesas-u-boot-cip
```


## Select the board to build
To select the board you would like to build for, please **edit the build.sh** file and make your selection at the top. Selections are made by un-commenting the **MACHINE** and **DEFCONFIG** lines you want (removing the # sign).

For example, to build for a HiHope RZ/G2M board:
```
# HiHope RZ/G2M
MACHINE=hihope-rzg2m
DEFCONFIG=r8a774a1_hihope-rzg2m_defconfig
```

## Build the code
Finally, to build, simply execute the build.sh script without any parameters.
```
./build.sh
```
The output files will be in:
 * ./renesas-u-boot-cip/.out_xxxx/

(xxxx = MACHINE name)


## Programming with flash writer
If you use the "rzg_stuff/flash_writer/flash_writer.sh" script,  it is already set up to pull files from this build process.
Within the **rzg_stuff/flash_writer/confi.ini** file, simply define your **BOARD=** and **FLASH=** settings at the top, and then set (un-comment) **BUILT_OUTSIDE_YOCTO=1** at the bottom.
