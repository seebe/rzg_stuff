#!/bin/bash

set -e

# Do not edit

source ../config.ini

KBUILD_DIR_r8a774e1=build/linux/r8a7795_linux
KBUILD_DIR_r8a774b1=build/linux/r8a77965_linux
KBUILD_DIR_r8a774a1=build/linux/r8a7796_linux
KBUILD_DIR_r8a774c0=build/linux/r8a7799_linux
if [ ${KERNEL_VERSION} = 4.19 ]
then
  KBUILD_OUTDIR_r8a774e1=binary_r8a7795_linux_release/target_aarch64/kbuild/
  KBUILD_OUTDIR_r8a774b1=binary_r8a77965_linux_release/target_aarch64/kbuild/
  KBUILD_OUTDIR_r8a774a1=binary_r8a7796_linux_release/target_aarch64/kbuild/
  KBUILD_OUTDIR_r8a774c0=binary_r8a7799_linux_release/target_aarch64/kbuild/
elif [ ${KERNEL_VERSION} = 5.10 ]
then
  KBUILD_OUTDIR_r8a774e1=binary_r8a7795_linux_nullws_drm_release/target_aarch64/kbuild/
  KBUILD_OUTDIR_r8a774b1=binary_r8a77965_linux_nullws_drm_release/target_aarch64/kbuild/
  KBUILD_OUTDIR_r8a774a1=binary_r8a7796_linux_nullws_drm_release/target_aarch64/kbuild/
  KBUILD_OUTDIR_r8a774c0=binary_r8a7799_linux_nullws_drm_release/target_aarch64/kbuild/
  echo ${KBUILD_OUTDIR_r8a774c0}
else
  echo "Kernel version not set"
  exit -1
fi

case $device in

  RZG2E)
    GLES_TAR=${GLES_TAR_r8a774c0}
    KBUILD_DIR=${PWD}/rogue_km/${KBUILD_DIR_r8a774c0}
    KBUILD_OUTDIR=${PWD}/rogue_km/${KBUILD_OUTDIR_r8a774c0}
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
tar -xvf ${GLES_TAR}

# Patch sources
pushd rogue_km

if [ ${KERNEL_VERSION} = 419 ]
then
  patch -p1 -N < ${GLES_PATCHES_PATH}/0001-supporting-kernel-version-4.19-and-later.patch || true
  patch -p1 -N < ${GLES_PATCHES_PATH}/0002-common-linux-dma_support-replace-__get_order-to-get_.patch || true
  if [ $device = RZG2H ]
  then 
    patch -p1 -N < ${GLES_PATCHES_PATH}/0001-r8a7795-Makefile-support-fixed-device-memory-for-PVR.patch || true
  fi
  if [ $device = RZG2M ]
  then 
    patch -p1 -N < ${GLES_PATCHES_PATH}/0001-r8a7796-Makefile-support-fixed-device-memory-for-PVR.patch || true
  fi
elif [ ${KERNEL_VERSION} = 5.10 ]
then
  patch -p1 -N < ${GLES_PATCHES_PATH}/5.10/0001-Fix-compiling-error-when-enable-SUPPORT_FIXED_DEVICE.patch || true
  if [ $device = RZG2H ]
  then 
    patch -p1 -N < ${GLES_PATCHES_PATH}/5.10/0001-r8a7795-Makefile-support-fixed-device-memory-for-PVR.patch || true
  fi
  if [ $device = RZG2M ]
  then 
    patch -p1 -N < ${GLES_PATCHES_PATH}/5.10/0001-r8a7796-Makefile-support-fixed-device-memory-for-PVR.patch || true
  fi
  patch -p1 -N < ${GLES_PATCHES_PATH}/5.10/0001-Silence-warnings-being-treated-as-errors.patch || true
fi

  
# Set-up environment
unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
export KERNELDIR=$KERNEL_OUT_DIR
export KBUILD_OUTDIR=${KBUILD_OUTDIR}
export KBUILD_DIR=${KBUILD_DIR}
KERNEL_VERSION=$(<${KERNEL_OUT_DIR}/include/config/kernel.release)
eval ${SDK_SETUP}
pushd ${KBUILD_DIR}

# Make
make -j$(nproc)

# Install, either to a folder:
make DISCIMAGE=${SDKTARGETSYSROOT} install
# and/or to the target:

# do not use make install rather scp
#if [ ${TARGET_INSTALL} = TRUE ]
#then 
# make INSTALL_TARGET=${TARGET_IP_ADDRESS} install
#fi
popd
pwd

if [ ${TARGET_INSTALL} = TRUE ] ; then
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp ${KBUILD_OUTDIR}/../pvrsrvkm.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
mkdir -p ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra
cp ${KBUILD_OUTDIR}/../pvrsrvkm.ko ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra

popd

