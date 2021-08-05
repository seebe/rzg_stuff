#!/bin/bash

# This build script can be used to build
#  * arm-trusted-firmware
#  * u-boot
#  * Flash Writer
#  * kernel

# Please read "Toolchain Installs.txt" to install the toolchains.

# Please read "Instructions for BSP v1.1.txt" to learn how to download the repositories

# The output files you need will be copied to the 'output' directory.


#----------------------------------------------
# Settings
#----------------------------------------------
ATF_DIR=rzg_trusted-firmware-a
UBOOT_DIR=renesas-u-boot-cip
FW_DIR=rzg2_flash_writer
BOARD=rzg2l-smarc


#----------------------------------------------
# Help Menu
#----------------------------------------------
if [ "$1" == "" ] ; then

  echo "\
Please select what you want to build:

  ./build.sh a                       # Build arm-trusted-firmware
  ./build.sh u                       # Build u-boot
  ./build.sh f                       # Build Flash Writer

  ./build.sh k                       # Build kernel
"
  exit
fi

#----------------------------------------------
# script start
#----------------------------------------------
OUTPUT="$(pwd)/output"
mkdir -p $OUTPUT

# As for GCC 4.9, you can get a colorized output
export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# Find out how many CPU processor cores we have on this machine
# so we can build faster by using multithreaded builds
NPROC=2
if [ "$(which nproc)" != "" ] ; then  # make sure nproc is installed
  NPROC=$(nproc)
fi
BUILD_THREADS=$(expr $NPROC + $NPROC)


#----------------------------------------------
# ARM Trusted Firmware
#----------------------------------------------
if [ "$1" == "a" ] || [ "$1" == "arm-trusted-firmware" ]  ; then

  if [ ! -e "$UBOOT_DIR/u-boot.bin" ] ; then
    echo -e "\nERROR: You must build u-boot first since it is added to the BL31/FIP image".
    exit
  fi

  PATH=/opt/arm/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin:$PATH
  export CROSS_COMPILE=aarch64-none-linux-gnu-

  if [ ! -e $ATF_DIR ] ; then
    echo -e "\nERROR: Directory $ATF_DIR does not exit.\nPlease read \"Instructions for xxxxx.txt\"\n"
    exit
  fi

  cd $ATF_DIR

  BOARD_TYPE="BOARD_RZG2L_EVA"
  #BOARD_TYPE="BOARD_RZG2L_15MMSQ"
  #BOARD_TYPE="BOARD_RZG2LC_13MMSQ"

  # Taken from trusted-firmware-a.inc in the Yocto BSP
  #PLATFORM_smarc-rzg2l="rzg2l"
  #EXTRA_FLAGS_smarc-rzg2l="BOARD_TYPE=BOARD_RZG2L_EVA"
  #FLASH_ADDRESS_BL2_BP_smarc-rzg2l="00000"
  #FLASH_ADDRESS_FIP_smarc-rzg2l="1D200"

 # Log levels
  # NONE    0
  # ERROR   10
  # NOTICE  20  (Makefile default)
  # WARNING 30
  # INFO    40
  # VERBOSE 50
  LOG_LEVEL=20


  # This will generate bl2.bin and bl31.bin
  # 'make all' or 'make bl2 bl31' will work
  if [ "$2" == "" ] ; then
    set -- "$2" "all"
  fi
  CMD="make PLAT=rzg2l BOARD_TYPE=$BOARD_TYPE LOG_LEVEL=$LOG_LEVEL $2 $3 $4"
  # Print out the command, then run it
  echo -e "$CMD\n"
  $CMD


  # if clean or distclean, then exit
  if [ ! -e build/rzg2l/release/bl2.bin ] ; then
    exit
  fi

  # Create bootparams.bin
  # - bootparams.bin totls size is 512 bytes
  # - First 4 bytes is the size of bl2.bin (4-byte aligned)
  # - Last 2 bytes are 0x55, 0xAA
  # - Middle of the file is 0xFF
  cd build/rzg2l/release
  echo -e "\n[Creating bootparams.bin]"
  SIZE=$(stat -L --printf="%s" bl2.bin)
  SIZE_ALIGNED=$(expr $SIZE + 3)
  SIZE_ALIGNED2=$((SIZE_ALIGNED & 0xFFFFFFFC))
  SIZE_HEX=$(printf '%08x\n' $SIZE_ALIGNED2)
  echo "  bl2.bin size=$SIZE, Aligned size=$SIZE_ALIGNED2 (0x${SIZE_HEX})"
  STRING=$(echo \\x${SIZE_HEX:6:2}\\x${SIZE_HEX:4:2}\\x${SIZE_HEX:2:2}\\x${SIZE_HEX:0:2})
  printf "$STRING" > bootparams.bin
  for i in `seq 1 506` ; do printf '\xff' >> bootparams.bin ; done
  printf '\x55\xaa' >> bootparams.bin

  # Combine bootparams.bin and bl2.bin into single binary
  # Only if a new version of bl2.bin is created
  if [ "bl2.bin" -nt "bl2_bp.bin" ] || [ ! -e "bl2_bp.bin" ] ; then
    echo -e "\n[Adding bootparams.bin to bl2.bin]"
    cat bootparams.bin bl2.bin > bl2_bp.bin
  fi

  cd ../../..

  # Build the Fip Tool
  echo -e "\n[Building FIP tool]"
  cd tools/fiptool
  make PLAT=rzg2l
  cd ../..

  echo -e "[Create fip.bin]"
  tools/fiptool/fiptool create --align 16 --soc-fw build/rzg2l/release/bl31.bin --nt-fw ../$UBOOT_DIR/u-boot.bin fip.bin
  cp fip.bin $OUTPUT/fip-smarc-rzg2l.bin

  echo -e "[Convert BIN SREC format]"
  #<BL2>
  ${CROSS_COMPILE}objcopy -I binary -O srec --adjust-vma=0x00011E00 --srec-forceS3 build/rzg2l/release/bl2_bp.bin $OUTPUT/bl2_bp-smarc-rzg2l.srec

  #<FIP>
  ${CROSS_COMPILE}objcopy -I binary -O srec --adjust-vma=0x00000000 --srec-forceS3 fip.bin $OUTPUT/fip-smarc-rzg2l.srec

  echo -e "[Output files]"
  echo "  $OUTPUT/bl2_bp-smarc-rzg2l.srec"
  echo "  $OUTPUT/fip-smarc-rzg2l.srec"
  echo "  $OUTPUT/fip-smarc-rzg2l.bin"

  exit
fi

#----------------------------------------------
# u-boot
#----------------------------------------------
if [ "$1" == "u" ] || [ "$1" == "u-boot" ]  ; then

  PATH=/opt/arm/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin:$PATH
  export CROSS_COMPILE=aarch64-none-linux-gnu-

  if [ ! -e "renesas-u-boot-cip" ] ; then
    git clone --branch $UBOOT_BRANCH $UBOOT_URL
  fi

  cd renesas-u-boot-cip

  if [ ! -e ".config" ] && [ "$2" == "" ] ; then 
    # First build
    make smarc-rzg2l_defconfig
  fi

  echo "make -j$BUILD_THREADS $2 $3 $4"
  make -j$BUILD_THREADS $2 $3 $4

  if [ -e u-boot.bin ] ; then
    echo -e "\n\n"
    echo -e "\t*****************************************************************"
    echo -e "\t Please rebuild arm-trusted-firmware to package u-boot with BL31 "
    echo -e "\t*****************************************************************\n"
  fi

  exit
fi

#----------------------------------------------
# Flash Writer
#----------------------------------------------
if [ "$1" == "f" ] || [ "$1" == "flash_writer" ] ; then

  if [ ! -e $FW_DIR ] ; then
    echo -e "\nERROR: Directory $FW_DIR does not exit.\nPlease read \"Instructions for xxxxx.txt\"\n"
    exit
  fi

  cd $FW_DIR

  export PATH=$PATH:/opt/arm/gcc-arm-10.2-2020.11-x86_64-aarch64-none-elf/bin
  export CROSS_COMPILE=aarch64-none-elf-
  export CC=${CROSS_COMPILE}gcc
  export AS=${CROSS_COMPILE}as
  export LD=${CROSS_COMPILE}ld
  export AR=${CROSS_COMPILE}ar
  export OBJDUMP=${CROSS_COMPILE}objdump
  export OBJCOPY=${CROSS_COMPILE}objcopy

  make clean
  make BOARD=RZG2L_SMARC

  echo -e "\n[Copy Output File]"
  cp -v AArch64_output/Flash_Writer_SCIF_RZG2L_SMARC_DDR4_2GB.mot $OUTPUT

  echo -e "\n[Output files]"
  echo -e "  output/Flash_Writer_SCIF_RZG2L_SMARC_DDR4_2GB.mot\n"
fi


#----------------------------------------------
# Kernel
#----------------------------------------------
if [ "$1" == "k" ] || [ "$1" == "kernel" ] ; then

  PATH=/opt/linaro/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin:$PATH
  export CROSS_COMPILE=aarch64-linux-gnu-
  export ARCH=arm64

  if [ ! -e linux-cip ] ; then
    echo "no linux-cip directory"
    exit
  fi

  cd linux-cip

  # All build outfile files will be in .out (to keep them separate from the source code)
  OUT=.out

  # Add '-s' for silent Build
  MAKE="make -j$BUILD_THREADS O=$OUT"

  # If this is the first time building, we need to configure first
  if [ ! -e "$OUT/.config" ] && [ "$2" != "defconfig" ] ; then
    $MAKE defconfig
  fi

  CMD="$MAKE $2 $3 $4"
  echo $CMD ; $CMD

  # Copy binaries to output directory
  if [ -e $OUT/arch/arm64/boot/Image ] ; then
    echo -e "\[Copy binaries to output]"
    cp -v $OUT/arch/arm64/boot/Image  $OUTPUT
    cp -v $OUT/arch/arm64/boot/dts/renesas/r9a07g044l-g2lsmarc.dtb  $OUTPUT   # Big board - RZ/G2L
    cp -v $OUT/arch/arm64/boot/dts/renesas/r9a07g044c2-dev.dtb  $OUTPUT   # Big board - RZ/G2LC
    cp -v $OUT/arch/arm64/boot/dts/renesas/r9a07g044l-smarc-rzg2l.dtb  $OUTPUT   # Promotion Board
  fi

  exit
fi
