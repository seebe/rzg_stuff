#!/bin/bash

set -e

# Do not edit

source ../config.ini

# The sources are available on github
if [ ! -d "mmngr_drv" ] ; then
  git clone -b rcar_gen3 git://github.com/renesas-rcar/mmngr_drv.git
fi
pushd mmngr_drv

if [ ${KERNEL_VERSION} = 4.19 ]
then
  # To build a kernel 4.19.x module we need v1.8
  git checkout v1.8
elif [ ${KERNEL_VERSION} = 5.10 ]
then
  # To build a kernel 5.10.x module we need v1.11
  git checkout 2439802426474136312bd10bc4c143fbf1c84850
else
  echo "Kernel version not set"
  popd
  exit -1
fi


# Patch. Patches can be found in vlp:
# meta-rzg2/recipes-kernel/kernel-module-mmngr/kernel-module-mmngr 
# meta-rzg2/recipes-kernel/kernel-module-mmngr/kernel-module-mmngrbuf 

# mmngr
if [ ${KERNEL_VERSION} = 4.19 ]
then
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
elif [ ${KERNEL_VERSION} = 5.10 ]
then
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0001-Add-physical-address-translating-feature.patch || true 
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0002-mmngr_drv-mmngr-Add-checking-NULL-vma-in-mm_cnv_addr.patch || true 
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0003-mmngr-Get-start-address-of-MMP-area-from-DT.patch || true 
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0004-Do-not-parse-and-init-lossy-mem-area-for-RZ-G2L-Seri.patch || true 
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0005-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZG2M.patch || true 
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0006-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZG2N.patch || true 
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0007-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZG2E.patch || true 
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0008-mmngr-module-mmngr_drv-add-support-IPMMU-for-RZ-G2H.patch || true 
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0009-mmngr_drv-mmngr-Add-IPMMU-support-for-RZ-G2M-v3.0.patch || true 
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0010-mmngr_drv-mmngr-Update-PA-VA-mapping-table-for-HiHop.patch || true 
  patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0011-mmngr-change-address-setting-for-H3N-Swap-mode.patch || true 
  if [ $device = RZG2L ]
  then
    patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0001-Reduce-MM_OMXBUF_SIZE-for-omx.patch || true 
    patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0002-Fix-ioctl-MM_IOC_VTOP-hang-up.patch || true 
    patch -p1 -N < ${MMNGR_PATCHES_PATH}/5.10/0003-mmngr_drv-mmngr-module-drv-Update-physical-convert-f.patch || true 
  fi    
fi


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

  RZG2L)
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
cp Module.symvers $KERNELSRC/../include/mmngr.symvers

# Install 
if [ ${TARGET_INSTALL} = TRUE ]
then 
  scp mmngr.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
popd 
mkdir -p ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra
cp ./mmngr_drv/mmngr/mmngr-module/files/mmngr/drv/mmngr.ko ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra

pushd mmngr_drv/mmngrbuf/mmngrbuf-module/files/mmngrbuf/drv/
cp ../include/*.h $KERNELSRC/../include

# Make
make -j$(nproc) -C $KERNELSRC M=$PWD
cp Module.symvers $KERNELSRC/../include/mmngrbuf.symvers

# Install 
if [ ${TARGET_INSTALL} = TRUE ]
then 
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp mmngrbuf.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
popd
cp ./mmngr_drv/mmngrbuf/mmngrbuf-module/files/mmngrbuf/drv/mmngrbuf.ko ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra
popd

















