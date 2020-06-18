#!/bin/bash

#---------------------------------------------------------------------------
# Please read the README.md file first for proper setup
#---------------------------------------------------------------------------

# Please set the prefix of your toolchain
PATH=/opt/poky/2.4.3/sysroots/x86_64-pokysdk-linux/usr/bin/aarch64-poky-linux:$PATH
export CROSS_COMPILE="aarch64-poky-linux-"
export ARCH=arm64

# All outfile files will be in .out
OUT=.out

# Instructions
#
# Check out CIP Linux repository
# $ git clone git://git.kernel.org/pub/scm/linux/kernel/git/cip/linux-cip.git
# $ cd linux-cip
# $ git checkout linux-4.19.y-cip

# Then copy in this build.sh

# Then run:
#  $ ./build.sh make_patches
#  $ ./build.sh make_config
#  $ ./build.sh _all
#  $ ./build.sh deploy


if [ "$1" == "" ] ; then
  echo "Options:"
  echo "./build.sh make_patches             # Download and get patches for a specific VLP64 release"
  echo "./build.sh make_config              # Create a defconfig based on what you need to enable"
  echo "./build.sh _all                     # build the kernel and device tree"
  echo "./build.sh dtbs                     # build the Device Trees"
  echo "./build.sh deploy                   # copy all the output files to z_deploy"
  exit
fi

# Check for Yocto SDK setup
# WARNING: Use the setup script from the SDK causes issues.
# Just set the toolchain manually above
#if [ "$TARGET_PREFIX" == "" ] && [ "$CROSS_COMPILE" == "" ] ; then
#  echo "Yocto SDK environment not set up"
#  echo "source /opt/poky/2.4.3/environment-setup-aarch64-poky-linux"
#  exit
#fi

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

# $ ./build.sh make_patches
if [ "$1" == "make_patches" ] ; then

  if [ ! -e z_patches/meta-rzg2 ] ; then
    mkdir -p z_patches
    cd z_patches
    git clone https://github.com/renesas-rz/meta-rzg2
    cd ..
  fi

  BRANCH=
  if [ "$2" == "master" ] ; then
    CIP_SHA="master"
    CIP_BRANCH="linux-4.19.y-cip"
    META_BRANCH="master"
    META_PATCH_DIR=meta-rzg2/recipes-kernel/linux/linux-renesas/patches/v1.0.3_patch
    DIR="vlp64_master"
    echo "WARNING.....this might not work....."
  fi
  if [ "$2" == "BSP-1.0.2" ] ; then
    CIP_SHA="5b7dee96a2b4"
    CIP_BRANCH="linux-4.19.y-cip"
    META_BRANCH="master"
    META_PATCH_DIR=meta-rzg2/recipes-kernel/linux/linux-renesas/patches/v1.0.2_patch
    DIR="vlp64_v102"
  fi
  if [ "$2" == "BSP-1.0.3" ] ; then
    CIP_SHA="c2f78bed33cb"
    CIP_BRANCH="linux-4.19.y-cip"
    META_BRANCH="master"
    META_PATCH_DIR=meta-rzg2/recipes-kernel/linux/linux-renesas/patches/v1.0.3_patch
    DIR="vlp64_v103"
  fi
  if [ "$2" == "BSP-1.0.3-RT" ] ; then
    CIP_SHA="09df861aa89a"
    CIP_BRANCH="linux-4.19.y-cip-rt"
    META_BRANCH="master-rt"
    META_PATCH_DIR=meta-rzg2/recipes-kernel/linux/linux-renesas/patches/v1.0.3_patch
    DIR="vlp64_v103rt"
  fi
  if [ "$META_BRANCH" == "" ] ; then
    echo "Please choose a VLP64 release version:"
    echo ""
    echo "./build.sh make_patches master"
    echo "./build.sh make_patches BSP-1.0.2"
    echo "./build.sh make_patches BSP-1.0.3"
    echo "./build.sh make_patches BSP-1.0.3-RT"
    exit
  fi

  if [ -e z_patches/$DIR ] ; then
    echo "ERROR: You have already created patches for that version and probably already"
    echo "have a branch named \"$DIR\""
    echo "Please check by entering the command line: "
    echo "    $ git branch"
    exit
  fi

  # Check out the branch that we want
  cd z_patches/meta-rzg2
  CURRENT_BRANCH=$(git branch | sed -n -e 's/^\* \(.*\)/\1/p')
  if [ "$META_BRANCH" != "$CURRENT_BRANCH" ] ; then
    git checkout $META_BRANCH
  fi
  cd ../..

  #BRANCH=$(git branch | sed -n -e 's/^\* \(.*\)/\1/p')   # Get current branch name (no need to)
  #DIR=$BRANCH     # Use branch name as output directory name

  # Some patches are just diff, so turn them into mailbox patches
  # so we can apply them with 'git am'

  if [ -e z_patches/$DIR/patches ] ; then
    rm z_patches/$DIR/patches/*
  else
    mkdir -p z_patches/$DIR/patches
  fi

  # Copy all the patches
  cp z_patches/$META_PATCH_DIR/*.patch z_patches/$DIR/patches

  cd z_patches/$DIR/patches
  for filename in *.patch ; do
    #echo $filename
    LINE=`grep --line-number --max-count=1 "diff --git" $filename | sed 's/:.*//'`
    #echo LINE=$LINE

    if [ "$LINE" != "1" ] ; then
      LINE=`expr $LINE - 1`
      #sed -i -e "1,${LINE}d" $filename   # remove the entire header
      continue    # skip this file, it already has a good format
    fi
    # Add in git git mailbox header at begining of file
    SUBJECT=${filename::-6}
    sed -i "1 i\From: vlp64@renesas.com" $filename
    sed -i "2 i\Date: $(date -R)" $filename
    sed -i "3 i\Subject: $SUBJECT" $filename
    sed -i "4 i\ " $filename
    sed -i "5 i\ $filename" $filename
    sed -i "6 i\---" $filename
  done
  cd ../../..
 
  # Copy the option_patch (for ECC)
  mkdir -p z_patches/$DIR/ecc_patches
  cp z_patches/meta-rzg2/recipes-kernel/linux/linux-renesas/patches/option_patch/*.patch z_patches/$DIR/ecc_patches


  # Copy all the kenrel config options
  mkdir -p z_patches/$DIR/configs
  cp z_patches/meta-rzg2/recipes-kernel/linux/linux-renesas/*.cfg z_patches/$DIR/configs


  # For checking that the conversion worked: meld z_patches/meta-rzg2/recipes-kernel/linux/linux-renesas/patches z_patches/$DIR"
  echo "------------------------- Complete ----------------------------------"
  echo ""
  echo "To create a new branch of your current cip-linux repository and then"
  echo "apply these patches on top, copy/paste the following commands:"
  echo ""
  echo "git checkout $CIP_BRANCH"
  echo "git checkout -b $DIR $CIP_SHA ; git am z_patches/$DIR/patches/*"
  echo ""
  exit
fi

if [ ! -e z_patches/meta-rzg2 ] ; then
  echo "ERROR: Directory z_patches/meta-rzg2 does not exist yet"
  echo "       Please run \"./build.sh make_patches\" first"
  exit
fi


if [ "$1" == "make_config" ] ; then

  echo -e "This will make a kernel configuration using the default base configuration\nand adding in other optional drivers and features.\n"

  # detect what VLP release we are building
  if [ -e localversion-cip ] ; then
    CHECK=$(grep cip5 localversion-cip)
    if [ "$CHECK" != "" ] ; then
      DIR="vlp64_v102"
    fi
    CHECK=$(grep cip10 localversion-cip)
    if [ "$CHECK" != "" ] ; then
      DIR="vlp64_v103"
    fi
  fi

  if [ -e localversion-cip-rt ] ; then
    CHECK=$(grep rt4 localversion-cip-rt)
    if [ "$CHECK" != "" ] ; then
      DIR="vlp64_v103rt"
    fi
  fi

  echo -e "\nINFO: Detected $DIR\n"

  mkdir -p $OUT

  # First start with the defconfig in the kernel
  #cp -v arch/arm64/configs/defconfig $OUT/.config

  # Now add each option
  # BSP defaults:
  echo -n "Include Touch Panel support? [Y/n]: " ; read ANS;
  if [ "$ANS" != "n" ] ; then cat z_patches/$DIR/configs/touch.cfg >> arch/arm64/configs/defconfig ; fi

  echo -n "Set default CPU Frequncy to max [Y/n]: " ; read ANS;
  if [ "$ANS" != "n" ] ; then cat z_patches/$DIR/configs/gsx.cfg >> arch/arm64/configs/defconfig ; fi

  echo -n "Include USB3 support [Y/n]: " ; read ANS;
  if [ "$ANS" != "n" ] ; then cat z_patches/$DIR/configs/usb3.cfg >> arch/arm64/configs/defconfig ; fi
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
  if [ "$ANS" != "n" ] ; then cat z_patches/$DIR/configs/wifi.cfg >> arch/arm64/configs/defconfig ; fi
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
  if [ "$ANS" != "n" ] ; then cat z_patches/$DIR/configs/bluetooth.cfg >> arch/arm64/configs/defconfig ; fi
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
  if [ "$ANS" == "y" ] ; then cat z_patches/$DIR/configs/docker.cfg >> arch/arm64/configs/defconfig ; fi

  echo -n "Include capacity aware migration strategy support [y/N]: " ; read ANS;
  if [ "$ANS" == "y" ] ; then cat z_patches/$DIR/configs/capacity_aware_migration_strategy.cfg >> arch/arm64/configs/defconfig ; fi

  make O=$OUT defconfig

  # put defconfig back to original
  git checkout arch/arm64/configs/defconfig
  exit
fi


# $ ./build.sh make_patches
if [ "$1" == "deploy" ] ; then

  mkdir -p z_deploy
  mkdir -p z_deploy/modules

  mkdir -p z_deploy/hihope-rzg2m
  mkdir -p z_deploy/hihope-rzg2n
  mkdir -p z_deploy/hihope-rzg2h
  mkdir -p z_deploy/ek874

  # Kernel (rename to match Yocto output...but it's all the same kernel)
  cp -v $OUT/arch/arm64/boot/Image z_deploy
  cp -v $OUT/arch/arm64/boot/Image z_deploy/hihope-rzg2m/Image-hihope-rzg2m.bin
  cp -v $OUT/arch/arm64/boot/Image z_deploy/hihope-rzg2n/Image-hihope-rzg2n.bin
  cp -v $OUT/arch/arm64/boot/Image z_deploy/hihope-rzg2h/Image-hihope-rzg2h.bin
  cp -v $OUT/arch/arm64/boot/Image z_deploy/ek874/Image-ek874.bin

  #Device Trees
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a*.dtb z_deploy

  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774a1-hihope-rzg2m.dtb    z_deploy/hihope-rzg2m/Image-r8a774a1-hihope-rzg2m.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774a1-hihope-rzg2m-ex.dtb z_deploy/hihope-rzg2m/Image-r8a774a1-hihope-rzg2m-ex.dtb

  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774b1-hihope-rzg2n.dtb    z_deploy/hihope-rzg2n/Image-r8a774b1-hihope-rzg2n.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774b1-hihope-rzg2n-ex.dtb z_deploy/hihope-rzg2n/Image-r8a774b1-hihope-rzg2n-ex.dtb

  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774e1-hihope-rzg2h.dtb    z_deploy/hihope-rzg2h/Image-r8a774e1-hihope-rzg2h.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774e1-hihope-rzg2h-ex.dtb z_deploy/hihope-rzg2h/Image-r8a774e1-hihope-rzg2h-ex.dtb

  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774c0-cat874.dtb      z_deploy/ek874/Image-r8a774c0-cat874.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774c0-ek874.dtb       z_deploy/ek874/Image-r8a774c0-ek874.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774c0-es10-cat874.dtb z_deploy/ek874/Image-r8a774c0-es10-cat874.dtb
  cp -v $OUT/arch/arm64/boot/dts/renesas/r8a774c0-es10-ek874.dtb  z_deploy/ek874/Image-r8a774c0-es10-ek874.dtb

  # Modules
  mkdir -p z_deploy/modules
  make O=$OUT INSTALL_MOD_PATH=../z_deploy/modules/ modules_install

  exit
fi

# Add '-s' for silent Build
MAKE="make -j$BUILD_THREADS O=$OUT"

# If this is the first time building, we need to configure first
if [ ! -e "$OUT/.config" ] ; then
  echo "ERROR: First you must run: ./build.sh make_config"
  exit
fi

CMD="$MAKE $1 $2 $3"
echo $CMD ; $CMD


