# rzg2\_flash\_writer Build Script

This script lets you build the RZ/G2 Flash Writer software **outside** of the Yocto environment.

## Directory Location

I would suggest that you keep your rzg2\_flash\_writer directory at the same directory level as this rzg_stuff repository.
If you do that, then the "rzg_stuff/flash\_writer" script is already set up to pull the binaries directly from other project directory.
For example:
<pre>
├── home
│   └── chris
│       └── rzg2
│           ├── arm-trusted-firmware
│           ├── renesas-u-boot-cip
│           ├── rzg2_flash_writer
│           └── rzg_stuff

</pre>

## Build Instructions
### Clone and check out the rzg2\_flash\_writer repository
```
$ cd /home/chris/rzg2
$ git clone https://github.com/renesas-rz/rzg2_flash_writer.git
$ cd rzg2_flash_writer
$ git checkout master
```

For RZ/G2L:
```
$ git checkout rz_g2l
```


### Copy in our custom build.sh script
```
$ cp ../rzg_stuff/build_scripts/rzg2_flash_writer/build.sh  .
```

## Select your board and build
To build, simply execute the build.sh script without any parameters.
```
./build.sh
```
Then use the GUI menu to “Select your board” to select the board you want to build.

You do not need to change the other settings (the defaults will be chosen by the Makefile)

After, select the < Build > button at the bottom.

Your settings will automatically be saved in the file **board.ini**.

The output files will be in:

 * rzg2_flash\_writer/AArch64\_output/

## (Optional) Build with Command Line only
You may also build using the command line. In that case, pass the settings on the command line before build.sh.
For example, to build for a HiHope RZ/G2M board:
```
$ source /opt/poky/2.4.3/environment-setup-aarch64-poky-linux
$ BOARD=HIHOPE ./build.sh clean
$ BOARD=HIHOPE ./build.sh
```

The output files will be in:
 * rzg2\_flash\_writer/AArch64\_output/


## Programming with flash writer
If you use the "rzg\_stuff/flash_writer/flash\_writer.sh" script,  it is already set up to pull files from this build process.

Within the rzg\_stuff/flash\_writer/example\_confi.ini file, simply define your **BOARD=** and **FLASH=** settings at the top, and then set (un-comment) **BUILT\_OUTSIDE\_YOCTO=1** at the bottom.
