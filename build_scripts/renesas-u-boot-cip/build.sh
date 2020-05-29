#!/bin/bash

#---------------------------------------------------------------------------
# Please read the README.md file first for proper setup
#---------------------------------------------------------------------------

# HiHope RZ/G2M
#MACHINE=hihope-rzg2m
#DEFCONFIG=r8a774a1_hihope-rzg2m_defconfig

# HiHope RZ/G2N
#MACHINE=hihope-rzg2n
#DEFCONFIG=r8a774b1_hihope-rzg2n_defconfig

# Silicon Linux RZ/G2E
#MACHINE=ek874
#DEFCONFIG=r8a774c0_ek874_defconfig



# Set the output directory (because I like all my build files separate from the source code)
OUT=.out_${MACHINE}

# Check for MACHINE setting
if [ "$MACHINE" == "" ] ; then
  echo ""
  echo "ERROR: Please set MACHINE and DEFCONFIG in build.sh"
  echo ""
  exit
fi

# Check for Yocto SDK setup
if [ "$TARGET_PREFIX" == "" ] ; then
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

# If this is the first time building, we need to configure first
if [ ! -e "$OUT/.config" ] ; then
  echo $MAKE $DEFCONFIG
  $MAKE $DEFCONFIG
fi

CMD="$MAKE $1 $2 $3"
echo $CMD ; $CMD

