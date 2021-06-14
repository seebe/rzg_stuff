#!/bin/bash

set -e

# Set your parameters here

device=RZG2E
#device=RZG2N
#device=RZG2M
#device=RZG2H

# These pathes are available in the VLP, path:
# meta-rzg2/recipes-kernel/kernel-module-mmngr/kernel-module-mmngr 
# meta-rzg2/recipes-kernel/kernel-module-mmngr/kernel-module-mmngrbuf 
PATCHES_PATH=../../patches/mmngr

# This is the path where the kernel is built
KERNELSRCPATH=~/repos/my-linux-cip/.out

# SDK path. It is used to set the cross build environment variables
SDK_PATH=/opt/poky/2.4.3-we

# The module (.ko) can be installed automatically on the target via scp
TARGET_IP_ADDRESS=192.168.10.125

# Do not edit

# The sources are available on github
git clone -b rcar_gen3 git://github.com/renesas-rcar/mmngr_drv.git

pushd mmngr_drv

# To build a kernel 4.19.x module we need v1.8
git checkout v1.8

# Patch. Patches can be found in vlp:
# meta-rzg2/recipes-kernel/kernel-module-mmngr/kernel-module-mmngr 
# meta-rzg2/recipes-kernel/kernel-module-mmngr/kernel-module-mmngrbuf 

# mmngr
# git apply ${PATCHES_PATH}/0001-Add-physical-address-translating-feature.patch -> this patch is corrupted
# git apply ${PATCHES_PATH}/0002-mmngr_drv-mmngr-Add-checking-NULL-vma-in-mm_cnv_addr.patch -> this patch does not apply
git apply ${PATCHES_PATH}/0003-mmngr-Get-start-address-of-MMP-area-from-DT.patch
git apply ${PATCHES_PATH}/0004-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZG2M.patch
git apply ${PATCHES_PATH}/0005-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZG2N.patch
git apply ${PATCHES_PATH}/0006-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZG2E.patch
git apply ${PATCHES_PATH}/0007-mmngr-module-mmngr_drv-fix-some-syntax-errors-to-avo.patch
git apply ${PATCHES_PATH}/0008-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZ-G2H.patch
git apply ${PATCHES_PATH}/0009-mmngr_drv-mmngr-Add-IPMMU-support-for-RZ-G2M-v3.0.patch
# mmngrbuf
git apply ${PATCHES_PATH}/0001-supporting-kernel-version-4.19-and-later-for-kernel-.patch

# Prepare environment
case $device in

  RZG2E)
    MMNGR_CFG="MMNGR_EBISU"
    ;;
    
  RZG2N)
    MMNGR_CFG="MMNGR_SALVATORX"
    ;;

  RZG2M)
    MMNGR_CFG="MMNGR_SALVATORX"
    ;;

  RZG2H)
    MMNGR_CFG="MMNGR_SALVATORX"
    ;;

esac
export MMNGR_CONFIG=${MMNGR_CFG}
export MMNGR_SSP_CONFIG="MMNGR_SSP_DISABLE"
export MMNGR_IPMMU_MMU_CONFIG="IPMMU_MMU_DISABLE"

source ${SDK_PATH}/environment-setup-aarch64-poky-linux
export KERNELSRC=${KERNELSRCPATH}
pushd mmngr_drv/mmngr/mmngr-module/files/mmngr/drv/
cp ../include/*.h $KERNELSRC/../include
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -C $KERNELSRC M=$PWD
cp Module.symvers $KERNELSRC/include/mmngr.symvers

# Install 
scp mmngr.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra

popd 

pushd mmngr_drv/mmngrbuf/mmngrbuf-module/files/mmngrbuf/drv/
cp ../include/*.h $KERNELSRC/../include

# Make
make -C $KERNELSRC M=$PWD
cp Module.symvers $KERNELSRC/include/mmngrbuf.symvers

# Install 
scp mmngrbuf.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra















