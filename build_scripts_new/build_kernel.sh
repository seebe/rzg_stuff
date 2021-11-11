#!/bin/bash

#---------------------------------------------------------------------------
# Please read the README.md file first for proper setup
#---------------------------------------------------------------------------

# Settings
# All build output files will be in .out (to keep them separate from the source code)
OUT=.out

# Direct where the config files are kept
CONFIG_DIR=.config_options

# Copy output files to a .deploy directory
DEPLOY_DIR=.deploy

# Read in functions from build_common.sh
if [ ! -e build_common.sh ] ; then 
  echo -e "\n ERROR: File \"build_common.sh\" not found\n."
  exit
else
  source build_common.sh
fi

# Read our settings (board.ini) or whatever file SETTINGS_FILE was set to
read_setting

# Define the defconfig for Renesas boards
# Identify the BSP type
BSP_TYPE=""
if [ "$MACHINE" == "hihope-rzg2m" ] ; then DEFCONFIG="defconfig" ; BSP_TYPE="RZG2" ; fi
if [ "$MACHINE" == "hihope-rzg2n" ] ; then DEFCONFIG="defconfig" ; BSP_TYPE="RZG2" ; fi
if [ "$MACHINE" == "hihope-rzg2h" ] ; then DEFCONFIG="defconfig" ; BSP_TYPE="RZG2" ; fi
if [ "$MACHINE" == "ek874" ]        ; then DEFCONFIG="defconfig" ; BSP_TYPE="RZG2" ; fi
if [ "$MACHINE" == "smarc-rzg2l" ]  ; then DEFCONFIG="defconfig" ; BSP_TYPE="RZG2L" ; fi
if [ "$MACHINE" == "smarc-rzg2lc" ] ; then DEFCONFIG="defconfig" ; BSP_TYPE="RZG2L" ; fi


do_toolchain_menu() {

  select_toolchain "KERNEL_TOOLCHAIN_SETUP_NAME" "KERNEL_TOOLCHAIN_SETUP"

}

if [ "$KERNEL_TOOLCHAIN_SETUP_NAME" == "" ] ; then
  whiptail --msgbox "Please select a Toolchain" 0 0 0
  do_toolchain_menu
  save_setting KERNEL_TOOLCHAIN_SETUP_NAME "\"$KERNEL_TOOLCHAIN_SETUP_NAME\""
  save_setting KERNEL_TOOLCHAIN_SETUP "\"$KERNEL_TOOLCHAIN_SETUP\""
fi

# Help Menu
if [ "$1" == "" ] ; then
  echo "Options:"
#  echo "./build.sh make_config              # Create a defconfig based on what you need to enable"
  echo "./build.sh defconfig                # Configure the kernel"
  echo "./build.sh _all                     # build the kernel and device tree"
  echo "./build.sh dtbs                     # build the Device Trees"
#  echo "./build.sh deploy                   # copy all the output files to $DEPLOY_DIR"
  exit
fi


echo "cd $KERNEL_DIR"
cd $KERNEL_DIR

echo "$KERNEL_TOOLCHAIN_SETUP"
eval $KERNEL_TOOLCHAIN_SETUP

export ARCH=arm64

# Check that the binutils in the toolchain supports the linker option "--fix-cortex-a53-843419".
# NOTE: In binutils 2.25, the option "--fix-cortex-a53" was added, but in 2.26 it was renamed to "--fix-cortex-a53-843419".
# https://sourceware.org/git/?p=binutils-gdb.git;a=commit;h=7a2a1c793578a8468604e661dda025ecb8d0bd20
${CROSS_COMPILE}ld --fix-cortex-a53-843419 2>&1 >/dev/null | grep 'unrecognized option' >/dev/null
if [ "$?" == "0" ] ; then
	echo "ERROR: Toolchain does not support option --fix-cortex-a53-843419"
	echo "Please use an SDK from VLP64 1.0.4 or later"
	exit
fi

# As for GCC 4.9, you can get a colorized output
export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# Find out how many CPU processor cores we have on this machine
# so we can build faster by using multithreaded builds
NPROC=2
if [ "$(which nproc)" != "" ] ; then  # make sure nproc is installed
  NPROC=$(nproc)
fi
BUILD_THREADS=$(expr $NPROC + $NPROC)

# Let the Makefile handle setting up the CFLAGS and LDFLAGS as it is a standalone application
unset CFLAGS
unset CPPFLAGS
unset LDFLAGS
unset AS
unset LD


if [ "$1" == "make_config" ] ; then

  echo -e "This will make a kernel configuration using the default base configuration\nand adding in other optional drivers and features.\n"

  mkdir -p $OUT

  MY_DEFCONFIG=my_defconfig

  # First start with the defconfig in the kernel
  cp -v arch/arm64/configs/defconfig arch/arm64/configs/$MY_DEFCONFIG

  # Now add each option
  # BSP defaults:
  echo -n "Include Touch Panel support? [Y/n]: " ; read ANS;
  if [ "$ANS" != "n" ] ; then cat $CONFIG_DIR/touch.cfg >> arch/arm64/configs/$MY_DEFCONFIG ; fi

  echo -n "Set default CPU Frequncy to max [Y/n]: " ; read ANS;
  if [ "$ANS" != "n" ] ; then cat $CONFIG_DIR/gsx.cfg >> arch/arm64/configs/$MY_DEFCONFIG ; fi

  echo -n "Include USB3 support [Y/n]: " ; read ANS;
  if [ "$ANS" != "n" ] ; then cat $CONFIG_DIR/usb3.cfg >> arch/arm64/configs/$MY_DEFCONFIG ; fi
  if [ "$ANS" != "n" ] ; then
    USB3_FIRMWARE_V2="https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/r8a779x_usb3_v2.dlmem"
    USB3_FIRMWARE_V3="https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/r8a779x_usb3_v3.dlmem"
    if [ ! -e firmware/r8a779x_usb3_v2.dlmem ] ; then
      echo -n "WARNING: File firmware/r8a779x_usb3_v2.dlmem is required to build. Download it now [Y/n]: " ; read ANS
      if [ "$ANS" != "n" ] ; then
        cd firmware ; wget $USB3_FIRMWARE_V2 ; cd ..
      fi
    fi
    if [ ! -e firmware/r8a779x_usb3_v3.dlmem ] ; then
      echo -n "WARNING: File firmware/r8a779x_usb3_v3.dlmem is required to build. Download it now [Y/n]: " ; read ANS
      if [ "$ANS" != "n" ] ; then
        cd firmware ; wget $USB3_FIRMWARE_V3 ; cd ..
      fi
    fi
    echo -e "\nINFO: Remember that USB3.0 firmware needs to be included in rootfs\n\t/firmware/r8a779x_usb3_v2.dlmem\n\t/firmware/r8a779x_usb3_v3.dlmem\n" ;
  fi

  echo -n "Include WiFi support [Y/n]: " ; read ANS;
  if [ "$ANS" != "n" ] ; then cat $CONFIG_DIR/wifi.cfg >> arch/arm64/configs/$MY_DEFCONFIG ; fi
  if [ "$ANS" != "n" ] ; then
    REGULATORY_DB="https://git.kernel.org/pub/scm/linux/kernel/git/sforshee/wireless-regdb.git/plain/regulatory.db?h=master-2019-06-03"
    REGULATORY_DB_P7S="https://git.kernel.org/pub/scm/linux/kernel/git/sforshee/wireless-regdb.git/plain/regulatory.db.p7s?h=master-2019-06-03"
    if [ ! -e firmware/regulatory.db ] ; then
      echo -n "WARNING: File firmware/regulatory.db is required to build. Download it now [Y/n]: " ; read ANS
      if [ "$ANS" != "n" ] ; then
        cd firmware ; wget -O regulatory.db $REGULATORY_DB ; cd ..
      fi
    fi
    if [ ! -e firmware/regulatory.db.p7s ] ; then
      echo -n "WARNING: File firmware/regulatory.db.p7s is required to build. Download it now [Y/n]: " ; read ANS
      if [ "$ANS" != "n" ] ; then
        cd firmware ; wget -O regulatory.db.p7s $REGULATORY_DB_P7S ; cd ..
      fi
    fi

    echo -e "\nINFO: Remember that regulatory database firmware needs to be included in rootfs\n\t/firmware/regulatory.db\n\t/firmware/regulatory.db.p7s\n"
  fi

  echo -n "Include Bluetooth support [Y/n]: " ; read ANS;
  if [ "$ANS" != "n" ] ; then cat $CONFIG_DIR/bluetooth.cfg >> arch/arm64/configs/$MY_DEFCONFIG ; fi
  if [ "$ANS" != "n" ] ; then
    BLUETOOTH_FW=" https://git.ti.com/cgit/wilink8-bt/ti-bt-firmware/plain/TIInit_11.8.32.bts"
    #downloadfilename=TIInit_11.8.32.bts"
    if [ ! -e firmware/ti-connectivity/TIInit_11.8.32.bts ] ; then
      echo -n "WARNING: File firmware/ti-connectivity/TIInit_11.8.32.bts is required to build. Download it now [Y/n]: " ; read ANS
      if [ "$ANS" != "n" ] ; then
        mkdir firmware/ti-connectivity
        cd firmware/ti-connectivity ; wget -O TIInit_11.8.32.bts $BLUETOOTH_FW ; cd ../..
      fi
    fi

    echo -e "\nINFO: Remember that Bluetooth firmware needs to be included in rootfs\n\t/firmware/ti-connectivity/TIInit_11.8.32.bts\n"
  fi

  # Options set by local.confg
  echo -n "Include Docker support [y/N]: " ; read ANS;
  if [ "$ANS" == "y" ] ; then cat $CONFIG_DIR/docker.cfg >> arch/arm64/configs/$MY_DEFCONFIG ; fi

  echo -n "Include capacity aware migration strategy support [y/N]: " ; read ANS;
  if [ "$ANS" == "y" ] ; then cat $CONFIG_DIR/capacity_aware_migration_strategy.cfg >> arch/arm64/configs/$MY_DEFCONFIG ; fi

  make O=$OUT $MY_DEFCONFIG

  # put defconfig back to original
  #git checkout arch/arm64/configs/defconfig
  exit
fi

if [ "$1" == "deploy" ] && [ "$BSP_TYPE" == "RZG2" ] ; then

  mkdir -p $DEPLOY_DIR
  mkdir -p $DEPLOY_DIR/modules

  mkdir -p $DEPLOY_DIR/hihope-rzg2m
  mkdir -p $DEPLOY_DIR/hihope-rzg2n
  mkdir -p $DEPLOY_DIR/hihope-rzg2h
  mkdir -p $DEPLOY_DIR/ek874

  # Kernel (rename to match Yocto output...but it's all the same kernel)
  cp -v $OUT/arch/arm64/boot/Image $DEPLOY_DIR
  cp -v $OUT/arch/arm64/boot/Image $DEPLOY_DIR/hihope-rzg2m/Image-hihope-rzg2m.bin
  cp -v $OUT/arch/arm64/boot/Image $DEPLOY_DIR/hihope-rzg2n/Image-hihope-rzg2n.bin
  cp -v $OUT/arch/arm64/boot/Image $DEPLOY_DIR/hihope-rzg2h/Image-hihope-rzg2h.bin
  cp -v $OUT/arch/arm64/boot/Image $DEPLOY_DIR/ek874/Image-ek874.bin

  #Device Trees
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a*.dtb $DEPLOY_DIR

  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774a1-hihope-rzg2m.dtb    $DEPLOY_DIR/hihope-rzg2m/Image-r8a774a1-hihope-rzg2m.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774a1-hihope-rzg2m-ex.dtb $DEPLOY_DIR/hihope-rzg2m/Image-r8a774a1-hihope-rzg2m-ex.dtb

  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774b1-hihope-rzg2n.dtb    $DEPLOY_DIR/hihope-rzg2n/Image-r8a774b1-hihope-rzg2n.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774b1-hihope-rzg2n-ex.dtb $DEPLOY_DIR/hihope-rzg2n/Image-r8a774b1-hihope-rzg2n-ex.dtb

  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774e1-hihope-rzg2h.dtb    $DEPLOY_DIR/hihope-rzg2h/Image-r8a774e1-hihope-rzg2h.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774e1-hihope-rzg2h-ex.dtb $DEPLOY_DIR/hihope-rzg2h/Image-r8a774e1-hihope-rzg2h-ex.dtb

  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774c0-cat874.dtb      $DEPLOY_DIR/ek874/Image-r8a774c0-cat874.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774c0-ek874.dtb       $DEPLOY_DIR/ek874/Image-r8a774c0-ek874.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774c0-es10-cat874.dtb $DEPLOY_DIR/ek874/Image-r8a774c0-es10-cat874.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774c0-es10-ek874.dtb  $DEPLOY_DIR/ek874/Image-r8a774c0-es10-ek874.dtb

  # Modules
  mkdir -p $DEPLOY_DIR/modules
  make O=$OUT INSTALL_MOD_PATH=../$DEPLOY_DIR/modules/ modules_install

  # Firmware files
  mkdir -p $DEPLOY_DIR/firmware
  cp -v firmware/*  $DEPLOY_DIR/firmware

  exit
fi

if [ "$1" == "deploy" ] && [ "$BSP_TYPE" == "RZG2L" ] ; then

  mkdir -p $DEPLOY_DIR
  mkdir -p $DEPLOY_DIR/modules

  mkdir -p $DEPLOY_DIR/$MACHINE

  # Kernel (rename to match Yocto output...but it's all the same kernel)
  cp -v $OUT/arch/arm64/boot/Image $DEPLOY_DIR
  cp -v $OUT/arch/arm64/boot/Image $DEPLOY_DIR/${MACHINE}/Image-${MACHINE}.bin

  #Device Trees
  cp -v $OUT/arch/arm64/boot/dts/renesas/r9a*.dtb $DEPLOY_DIR

  # Modules
  mkdir -p $DEPLOY_DIR/modules
  make O=$OUT INSTALL_MOD_PATH=../$DEPLOY_DIR/modules/ modules_install

  # Firmware files
  mkdir -p $DEPLOY_DIR/firmware
  cp -v firmware/*  $DEPLOY_DIR/firmware

  exit
fi




# Add '-s' for silent Build
MAKE="make -j$BUILD_THREADS O=$OUT"

# If this is the first time building, we need to configure first
if [ ! -e "$OUT/.config" ] && [ "$1" != "defconfig" ] ; then
  echo "ERROR: First you must run: ./build.sh make_config"
  exit
fi

CMD="$MAKE $1 $2 $3"
echo $CMD ; $CMD