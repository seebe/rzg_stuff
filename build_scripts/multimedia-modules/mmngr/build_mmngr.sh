#!/bin/bash

set -e

# Do not edit

source ../config.ini

# The sources are available on github
if [ ! -d "mmngr_drv" ] ; then
  git clone -b rcar_gen3 git://github.com/renesas-rcar/mmngr_drv.git
fi
pushd mmngr_drv

# To build a kernel 4.19.x module we need v1.8
git checkout v1.8

# Patch. Patches can be found in vlp:
# meta-rzg2/recipes-kernel/kernel-module-mmngr/kernel-module-mmngr 
# meta-rzg2/recipes-kernel/kernel-module-mmngr/kernel-module-mmngrbuf 

# mmngr
# patch -p1 -N < ${MMNGR_PATCHES_PATH}/0001-Add-physical-address-translating-feature.patch -> this patch is corrupted
# patch -p1 < ${MMNGR_PATCHES_PATH}/0002-mmngr_drv-mmngr-Add-checking-NULL-vma-in-mm_cnv_addr.patch -> this patch does not apply
patch -p1 -N < ${MMNGR_PATCHES_PATH}/0003-mmngr-Get-start-address-of-MMP-area-from-DT.patch || true
patch -p1 -N < ${MMNGR_PATCHES_PATH}/0004-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZG2M.patch || true
patch -p1 -N < ${MMNGR_PATCHES_PATH}/0005-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZG2N.patch || true
patch -p1 -N < ${MMNGR_PATCHES_PATH}/0006-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZG2E.patch || true
patch -p1 -N < ${MMNGR_PATCHES_PATH}/0007-mmngr-module-mmngr_drv-fix-some-syntax-errors-to-avo.patch || true
patch -p1 -N < ${MMNGR_PATCHES_PATH}/0008-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZ-G2H.patch || true
patch -p1 -N < ${MMNGR_PATCHES_PATH}/0009-mmngr_drv-mmngr-Add-IPMMU-support-for-RZ-G2M-v3.0.patch || true
# mmngrbuf
patch -p1 -N < ${MMNGR_PATCHES_PATH}/0001-supporting-kernel-version-4.19-and-later-for-kernel-.patch || true

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

eval ${SDK_SETUP}
export KERNELSRC=${KERNEL_OUT_DIR}
pushd mmngr_drv/mmngr/mmngr-module/files/mmngr/drv/
cp ../include/*.h $KERNELSRC/../include
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -C $KERNELSRC M=$PWD
cp Module.symvers $KERNELSRC/include/mmngr.symvers

# Install 
if [ ${TARGET_INSTALL} = TRUE ]
then 
  scp mmngr.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
popd 
cp ./mmngr_drv/mmngr/mmngr-module/files/mmngr/drv/mmngr.ko ../../build

pushd mmngr_drv/mmngrbuf/mmngrbuf-module/files/mmngrbuf/drv/
cp ../include/*.h $KERNELSRC/../include

# Make
make -C $KERNELSRC M=$PWD
cp Module.symvers $KERNELSRC/include/mmngrbuf.symvers

# Install 
if [ ${TARGET_INSTALL} = TRUE ]
then 
  scp mmngrbuf.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
popd
cp ./mmngr_drv/mmngrbuf/mmngrbuf-module/files/mmngrbuf/drv/mmngrbuf.ko ../../build


















