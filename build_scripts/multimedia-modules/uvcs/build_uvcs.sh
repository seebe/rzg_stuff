#!/bin/bash

set -e

# Do not edit
source ../config.ini

# The sources are not available on github
# File is RCG3VUDRL4101ZDO.tar.bz2 in the vlp:
# meta-rzg2/recipes-kernel/kernel-module-uvcs/kernel-module-uvcs-drv
# or in the folder RCG3VUDRL4101ZDO in the RCG3VUDRL4101ZDO_3_0_17.zip part of the multimedia package
tar -xvf ${UVCS_TAR}
pushd RCG3VUDRL4101ZDO

# Patch file is available in the vlp:
# meta-rzg2/recipes-kernel/kernel-module-uvcs/kernel-module-uvcs-drv
patch -p1 -N < ${UVCS_PATCHES_PATH}/0001-Fixing-build-error-kernel-module-uvcs.patch || true

# Prepare environment
eval ${SDK_SETUP}
export KERNELDIR=${KERNEL_OUT_DIR}
export UVCS_SRC=$PWD/src
export UVCS_INC=$PWD
export VCP4_SRC=$PWD/src
KERNEL_VERSION=$(<${KERNELDIR}/include/config/kernel.release)

pushd src/makefile

# Make
make 

cp Module.symvers $KERNELDIR/include/UVCS.symvers

# Install
if [ ${TARGET_INSTALL} = TRUE ]
then 
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp uvcs_drv.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
pushd

cp ./src/makefile/uvcs_drv.ko ../../build


