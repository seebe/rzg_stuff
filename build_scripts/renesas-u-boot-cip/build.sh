#!/bin/bash

#---------------------------------------------------------------------------
# Please read the README.md file first for proper setup
#---------------------------------------------------------------------------

# PLEASE CHOOSE YOU BOARD
#MACHINE=hihope-rzg2m	# HiHope RZ/G2M
#MACHINE=hihope-rzg2n	# HiHope RZ/G2N
#MACHINE=hihope-rzg2h	# HiHope RZ/G2H
#MACHINE=ek874		# Silicon Linux RZ/G2E


# Define the defconfigs for Renesas boards
if [ "$MACHINE" == "hihope-rzg2m" ] ; then DEFCONFIG=r8a774a1_hihope-rzg2m_defconfig ; fi
if [ "$MACHINE" == "hihope-rzg2n" ] ; then DEFCONFIG=r8a774b1_hihope-rzg2n_defconfig ; fi
if [ "$MACHINE" == "hihope-rzg2h" ] ; then DEFCONFIG=r8a774e1_hihope-rzg2h_defconfig ; fi
if [ "$MACHINE" == "ek874" ] ; then DEFCONFIG=r8a774c0_ek874_defconfig ; fi


# Set the output directory (because I like all my build files separate from the source code)
OUT=.out_${MACHINE}

# Check for MACHINE setting
if [ "$MACHINE" == "" ] ; then
  echo ""
  echo "ERROR: Please set MACHINE in build.sh"
  echo ""
  exit
fi

if [ "$DEFCONFIG" == "" ] ; then
  echo ""
  echo "ERROR: Please set DEFCONFIG in build.sh"
  echo ""
  exit
fi


#PATH=/opt/linaro/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin:$PATH
#export CROSS_COMPILE="aarch64-linux-gnu-"
#export ARCH=arm64

# Check for Yocto SDK setup
if [ "$TARGET_PREFIX" == "" ] && [ "$CROSS_COMPILE" == "" ] ; then
  echo "Yocto SDK environment not set up"
  echo "source /opt/poky/2.4.3/environment-setup-aarch64-poky-linux"
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

# Add '-s' for silent Build
MAKE="make -j$BUILD_THREADS O=$OUT"

# While the Yocto SDK setup script (environment-setup-aarch64-poky-linux) sets CC, and includes
# the --sysroot parameter, we have to explictly put CC= on the make command line because of how
# the u-boot Makefile was written and looks for thigns like libgcc.a
if [ "$TARGET_PREFIX" != "" ] ; then
	# Yocto SDK Toolchain build
	MAKE="make CC=\""$CC"\" -j$BUILD_THREADS O=$OUT"
fi

# If this is the first time building, we need to configure first
if [ ! -e "$OUT/.config" ] ; then
  echo $MAKE $DEFCONFIG
  eval $MAKE $DEFCONFIG
fi

CMD="$MAKE $1 $2 $3"
echo $CMD
eval $CMD

# Note:
# u-boot.bin is u-boot-dtb.bin (u-boot.bin + u-boot.dtb) renamed to u-boot.bin
# u-boot.srec is just u-boot (no dtb).
# u-boot-elf.srec is u-boot + dtb
