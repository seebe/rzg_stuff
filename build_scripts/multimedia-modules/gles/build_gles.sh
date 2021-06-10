#!/bin/bash

set -e

# Set your parameters here

# Device to be chosen

device=RZG2E
#device=RZG2N
#device=RZG2M
#device=RZG2H

# The sources are not available in github, so the tar file is required.
# It cannot be provided with the script because of licensing.
GLES_TAR_r8a774e1=./GSX_KM_H3.tar.bz2
GLES_TAR_r8a774b1=./GSX_KM_M3N.tar.bz2
GLES_TAR_r8a774a1=./GSX_KM_M3.tar.bz2
GLES_TAR_r8a774c0=./GSX_KM_E3.tar.bz2

# These pathes are available in the VLP, path:
# meta-rzg2/recipes-kernel/kernel-module-gles/kernel-module-gles
PATCHES_PATH=./patches/gles

# This is the path where the kernel is built
KERNEL_OUT_DIR=~/repos/my-linux-cip/.out

# SDK path. It is used to set the cross build environment variables but also for the installation
SDK_PATH=/opt/poky/2.4.3-we

# The module (.ko) can be installed automatically on the target via scp
TARGET_IP_ADDRESS=192.168.10.125

# Do not edit
KBUILD_DIR_r8a774e1=/build/linux/r8a7795_linux
KBUILD_DIR_r8a774b1=/build/linux/r8a77965_linux
KBUILD_DIR_r8a774a1=/build/linux/r8a7796_linux
KBUILD_DIR_r8a774c0=/build/linux/r8a7799_linux
KBUILD_OUTDIR_r8a774e1=binary_r8a7795_linux_release/target_aarch64/kbuild/
KBUILD_OUTDIR_r8a774b1=binary_r8a77965_linux_release/target_aarch64/kbuild/
KBUILD_OUTDIR_r8a774a1=binary_r8a7796_linux_release/target_aarch64/kbuild/
KBUILD_OUTDIR_r8a774c0=binary_r8a7799_linux_release/target_aarch64/kbuild/

case $device in

  RZG2E)
    GLES_TAR=${GLES_TAR_r8a774c0}
    KBUILD_DIR=${PWD}/rogue_km/${KBUILD_DIR_r8a774c0}
    KBUILD_OUTDIR=${PWD}/rogue_km/${KBUILD_OUTDIR_r8a774co}
    ;;
    
  RZG2N)
    GLES_TAR=${GLES_TAR_r8a774b1}
    KBUILD_DIR=${PWD}/rogue_km/${KBUILD_DIR_r8a774b1}
    KBUILD_OUTDIR=${PWD}/rogue_km/${KBUILD_OUTDIR_r8a774b1}
    ;;

  RZG2M)
    GLES_TAR=${GLES_TAR_r8a774a1}
    KBUILD_DIR=${PWD}/rogue_km/${KBUILD_DIR_r8a774a1}
    KBUILD_OUTDIR=${PWD}/rogue_km/${KBUILD_OUTDIR_r8a774a1}
    ;;

  RZG2H)
    GLES_TAR=${GLES_TAR_r8a774e1}
    KBUILD_DIR=${PWD}/rogue_km/${KBUILD_DIR_r8a774e1}
    KBUILD_OUTDIR=${PWD}/rogue_km/${KBUILD_OUTDIR_r8a774e1}
    ;;

esac

# Untar
tar xvf ${GLES_TAR}

# Patch sources
pushd rogue_km
git apply ../${PATCHES_PATH}/0001-supporting-kernel-version-4.19-and-later.patch
git apply ../${PATCHES_PATH}/0002-common-linux-dma_support-replace-__get_order-to-get_.patch
if [ $device = RZG2H ]
then 
  git apply ../${PATCHES_PATH}/0001-r8a7795-Makefile-support-fixed-device-memory-for-PVR.patch
fi
if [ $device = RZG2M ]
then 
  git apply ../${PATCHES_PATH}/0001-r8a7796-Makefile-support-fixed-device-memory-for-PVR.patch
fi
  
# Set-up environment
unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
export KERNELDIR=$KERNEL_OUT_DIR
export KBUILD_OUTDIR=${KBUILD_OUTDIR}
export KBUILD_DIR=${KBUILD_DIR}
source ${SDK_PATH}/environment-setup-aarch64-poky-linux
pushd ${KBUILD_DIR}

# Make
make

# Install, either to a folder:
make DISCIMAGE=${SDK_PATH}/sysroots/aarch64-poky-linux/ install
# and/or to the target:
make INSTALL_TARGET=${TARGET_IP_ADDRESS} install

