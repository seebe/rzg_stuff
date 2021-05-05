# RZ/G2L SMARC board Building and Programming

## Building

```
# Extract package that was downloaded from renesas.com
$ mkdir rzg2l_bsp_v1.0
$ tar -xf rzg2l_bsp_v1.0.tar.gz -C rzg2l_bsp_v1.0
$ cd rzg2l_bsp_v1.0

# Apply additional patches
$ cd meta-rzg2
$ patch -p1 < ../extra/0001-linux-renesas-add-workaround-patch-for-gicv3.patch
$ patch -p1 < ../extra/0002-tf-a-add-rd-wr-64-bit-reg-workaround.patch
$ cd ..

# Set up Yocto Environment
$ source poky/oe-init-build-env
$ cp ../meta-rzg2/docs/template/conf/minimal/smarc-rzg2l/*.conf ./conf/

# Build
$ bitbake core-image-minimal
$ bitbake core-image-minimal -c populate_sdk
```

<br>

## Programming

Change into base of directory of the BSP (rzg2l_bsp_v1.0) if you are still in the 'build' directory
```
$ cd ..
```

Get the program script and Flash Writer binary for the board.
Run the script and follow the instructions for setting the switches and resetting the board
```
$ wget https://raw.githubusercontent.com/seebe/rzg_stuff/master/boards/rzg2l_smarc/program_bootloaders.sh
$ wget https://raw.githubusercontent.com/seebe/rzg_stuff/master/boards/rzg2l_smarc/Flash_Writer_SCIF_RZG2L_SMARC_DDR4_2GB.mot
$ chmod +x program_bootloaders.sh

$ ./program_bootloaders.sh
```


