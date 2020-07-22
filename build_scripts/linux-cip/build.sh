#!/bin/bash

#---------------------------------------------------------------------------
# Please read the README.md file first for proper setup
#---------------------------------------------------------------------------

# Please set the prefix of your toolchain
PATH=/opt/poky/2.4.3/sysroots/x86_64-pokysdk-linux/usr/bin/aarch64-poky-linux:$PATH
export CROSS_COMPILE="aarch64-poky-linux-"
export ARCH=arm64

# All build outfile files will be in .out (to keep them separate from the source code)
OUT=.out

# Download and keep VLP64 release patches in a .patches directory
PATCHES_DIR=.patches

# Copy output files to a .deploy directory
DEPLOY_DIR=.deploy

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
  echo "./build.sh deploy                   # copy all the output files to $DEPLOY_DIR"
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

  if [ ! -e $PATCHES_DIR/meta-rzg2 ] ; then
    mkdir -p $PATCHES_DIR
    cd $PATCHES_DIR
    git clone https://github.com/renesas-rz/meta-rzg2
    cd ..
  fi

  VALID=
  if [ "$2" == "master" ] ; then
    CIP_SHA="master"
    CIP_BRANCH="linux-4.19.y-cip"
    META_BRANCH="master"
    META_PATCH_DIR=meta-rzg2/recipes-kernel/linux/linux-renesas/patches/v1.0.3_patch
    DIR="vlp64_master"
    echo "WARNING.....this might not work....."
  fi
  if [ "$2" == "BSP-1.0.2" ] ; then
    VALID=1
  fi
  if [ "$2" == "BSP-1.0.3" ] ; then
    VALID=1
  fi
  if [ "$2" == "BSP-1.0.3-RT" ] ; then
    VALID=1
  fi
  if [ "$2" == "BSP-1.0.4" ] ; then
    VALID=1
  fi
  if [ "$VALID" == "" ] ; then
    echo "Please choose a VLP64 release version:"
    echo ""
#   echo "./build.sh make_patches master"
    echo "./build.sh make_patches BSP-1.0.2"
    echo "./build.sh make_patches BSP-1.0.3"
    echo "./build.sh make_patches BSP-1.0.3-RT"
    echo "./build.sh make_patches BSP-1.0.4"
    exit
  fi

  # Find out what meta-rzg2 branch we should use by looking at
  # the last 2 chracters "-RT" ?
  if [ "${2:2,-3}" == "-RT" ] ; then
    META_BRANCH="master-rt"
  else
    META_BRANCH="master"
  fi

  # Create an output directory name
  # convert "BSP-" to "vlp64_v"
  # remove "-RT"
  # add "_patch"
  DIR=`echo $2 | sed "s/BSP-/vlp64_v/" | sed "s/\.//g" | sed "s/-RT/rt/"`

  # Determine where patch files are stored
  # convert "BSP-" to "v"
  # convert "-RT" to "rt"
  # add in full path
  TMP=`echo $2 | sed "s/BSP-/v/" | sed "s/-RT//"`
  META_PATCH_DIR="meta-rzg2/recipes-kernel/linux/linux-renesas/patches/${TMP}_patch"

  if [ "${2:2,-3}" == "-RT" ] ; then
    META_BRANCH="master-rt"
  else
    META_BRANCH="master"
  fi

  #echo META_PATCH_DIR=$META_PATCH_DIR
  #echo DIR=$DIR
  #echo META_BRANCH=$META_BRANCH


  if [ -e $PATCHES_DIR/$DIR ] ; then
    echo "ERROR: You have already created patches for that version and probably already"
    echo "have a branch named \"$DIR\""
    echo "Please check by entering the command line: "
    echo "    $ git branch"
    exit
  fi

  # Check out the branch that we want
  cd $PATCHES_DIR/meta-rzg2
  CURRENT_BRANCH=$(git branch | sed -n -e 's/^\* \(.*\)/\1/p')
  if [ "$META_BRANCH" != "$CURRENT_BRANCH" ] ; then
    git checkout $META_BRANCH
  fi
  git pull
  cd ../..

  # Look inside the linux-renesas_4.19.bb to find what is being set for BRANCH
  # and SRCREV. Also remember to remove the double quotes "".
  CIP_SHA=`grep "SRCREV = " $PATCHES_DIR/meta-rzg2/recipes-kernel/linux/linux-renesas_4.19.bb | awk {'print $3'} | sed "s:\"::g"`
  CIP_BRANCH=`grep "BRANCH = " $PATCHES_DIR/meta-rzg2/recipes-kernel/linux/linux-renesas_4.19.bb | awk {'print $3'} | sed "s:\"::g"`

  #BRANCH=$(git branch | sed -n -e 's/^\* \(.*\)/\1/p')   # Get current branch name (no need to)
  #DIR=$BRANCH     # Use branch name as output directory name

  # Some patches are just diff, so turn them into mailbox patches
  # so we can apply them with 'git am'

  if [ -e $PATCHES_DIR/$DIR/patches ] ; then
    rm $PATCHES_DIR/$DIR/patches/*
  else
    mkdir -p $PATCHES_DIR/$DIR/patches
  fi

  # Copy all the patches
  cp $PATCHES_DIR/$META_PATCH_DIR/*.patch $PATCHES_DIR/$DIR/patches

  cd $PATCHES_DIR/$DIR/patches
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
  mkdir -p $PATCHES_DIR/$DIR/ecc_patches
  cp $PATCHES_DIR/meta-rzg2/recipes-kernel/linux/linux-renesas/patches/option_patch/*.patch $PATCHES_DIR/$DIR/ecc_patches


  # Copy all the kenrel config options
  mkdir -p $PATCHES_DIR/$DIR/configs
  cp $PATCHES_DIR/meta-rzg2/recipes-kernel/linux/linux-renesas/*.cfg $PATCHES_DIR/$DIR/configs

  # For checking that the conversion worked: meld $PATCHES_DIR/meta-rzg2/recipes-kernel/linux/linux-renesas/patches $PATCHES_DIR/$DIR"

  echo "To create a new branch of your current cip-linux repository and then" >> $PATCHES_DIR/$DIR/git_command.txt
  echo "apply these patches on top, copy/paste the following commands:" >> $PATCHES_DIR/$DIR/git_command.txt
  echo "" >> $PATCHES_DIR/$DIR/git_command.txt
  echo "git fetch" >> $PATCHES_DIR/$DIR/git_command.txt
  echo "git checkout $CIP_BRANCH" >> $PATCHES_DIR/$DIR/git_command.txt
  echo "git checkout -b $DIR $CIP_SHA ; git am $PATCHES_DIR/$DIR/patches/*" >> $PATCHES_DIR/$DIR/git_command.txt

  echo "------------------------- Complete ----------------------------------"
  echo ""
  cat $PATCHES_DIR/$DIR/git_command.txt
  echo ""

  exit
fi

if [ ! -e $PATCHES_DIR/meta-rzg2 ] ; then
  echo "ERROR: Directory $PATCHES_DIR/meta-rzg2 does not exist yet"
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
  if [ "$ANS" != "n" ] ; then cat $PATCHES_DIR/$DIR/configs/touch.cfg >> arch/arm64/configs/defconfig ; fi

  echo -n "Set default CPU Frequncy to max [Y/n]: " ; read ANS;
  if [ "$ANS" != "n" ] ; then cat $PATCHES_DIR/$DIR/configs/gsx.cfg >> arch/arm64/configs/defconfig ; fi

  echo -n "Include USB3 support [Y/n]: " ; read ANS;
  if [ "$ANS" != "n" ] ; then cat $PATCHES_DIR/$DIR/configs/usb3.cfg >> arch/arm64/configs/defconfig ; fi
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
  if [ "$ANS" != "n" ] ; then cat $PATCHES_DIR/$DIR/configs/wifi.cfg >> arch/arm64/configs/defconfig ; fi
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
  if [ "$ANS" != "n" ] ; then cat $PATCHES_DIR/$DIR/configs/bluetooth.cfg >> arch/arm64/configs/defconfig ; fi
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
  if [ "$ANS" == "y" ] ; then cat $PATCHES_DIR/$DIR/configs/docker.cfg >> arch/arm64/configs/defconfig ; fi

  echo -n "Include capacity aware migration strategy support [y/N]: " ; read ANS;
  if [ "$ANS" == "y" ] ; then cat $PATCHES_DIR/$DIR/configs/capacity_aware_migration_strategy.cfg >> arch/arm64/configs/defconfig ; fi

  make O=$OUT defconfig

  # put defconfig back to original
  git checkout arch/arm64/configs/defconfig
  exit
fi


# $ ./build.sh make_patches
if [ "$1" == "deploy" ] ; then

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

# Add '-s' for silent Build
MAKE="make -j$BUILD_THREADS O=$OUT"

# If this is the first time building, we need to configure first
if [ ! -e "$OUT/.config" ] ; then
  echo "ERROR: First you must run: ./build.sh make_config"
  exit
fi

CMD="$MAKE $1 $2 $3"
echo $CMD ; $CMD


