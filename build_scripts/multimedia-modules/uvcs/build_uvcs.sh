#!/bin/bash

set -e

# Do not edit
source ../config.ini

# The sources are not available on github
# File is RCG3VUDRL4101ZDO.tar.bz2 in the vlp:
# meta-rzg2/recipes-kernel/kernel-module-uvcs/kernel-module-uvcs-drv
# or in the folder RCG3VUDRL4101ZDO in the RCG3VUDRL4101ZDO_3_0_17.zip part of the multimedia package
tar -xvf ${UVCS_TAR}
if [ $device = RZG2L ]
then
  pushd uvcs_lib_package
else
  pushd RCG3VUDRL4101ZDO
fi

# Patch file is available in the vlp:
# meta-rzg2/recipes-kernel/kernel-module-uvcs/kernel-module-uvcs-drv
patch -p1 -N < ${UVCS_PATCHES_PATH}/0001-Fixing-build-error-kernel-module-uvcs.patch || true
if [ ${KERNEL_VERSION} = 5.10 ]
then
  patch -p1 -N < ${UVCS_PATCHES_PATH}/5.10/0002-kernel-module-uvcs-drv-fix-built-error-with-kernel-v.patch || true
fi

# Prepare environment
eval ${SDK_SETUP}
export KERNELDIR=${KERNEL_OUT_DIR}
export UVCS_SRC=$PWD/src
export UVCS_INC=$PWD
export VCP4_SRC=$PWD/src
KERNEL_VERSION=$(<${KERNELDIR}/include/config/kernel.release)

pushd src/makefile

# Make
make -j$(nproc) 

cp ../../include/uvcs_ioctl.h $KERNELDIR/../include/
cp Module.symvers $KERNELDIR/../include/UVCS.symvers

# Install
if [ ${TARGET_INSTALL} = TRUE ]
then 
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp uvcs_drv.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
popd

mkdir -p ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra
cp ./src/makefile/uvcs_drv.ko ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra

popd
