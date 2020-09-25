# renesas-u-boot-cip Build Script

This script lets you build the kernel for RZ/G2 **outside** of the Yocto environment.

I would suggest that you keep your linux-cip directory at the same directory level as this rzg_stuff repository.
For example:
```
├── home
│   └── chris
│       └── rzg2
│           ├── linux-cip
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

### Clone and patch the kernel repository
Use the script **rzg_stuff/vlp64_util.sh** with the "create" command.

For example:
```
$ cd /home/chris/rzg2/rzg_stuff/build_scripts
$ ./vlp64_util.sh create kernel /home/chris/rzg2
```
### Copy in our custom build.sh script (if not already there)
```
$ cp /home/chris/rzg2/rzg_stuff/build_scripts/kernel/build.sh  /home/chris/rzg2/linux-cip
```

### Then run:
```
$ ./build.sh make_config
$ ./build.sh _all
$ ./build.sh deploy
```

### Output Files
The files you need to boot your board with will be under .deploy
