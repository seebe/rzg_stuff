#!/bin/bash

set -e

# Set your parameters here

# These pathes are available in the VLP, path:
# meta-rzg2/recipes-kernel/kernel-module-uvcs/kernel-module-uvcs
PATCHES_PATH=../../patches/uvcs

# This is the path where the kernel is built
KERNELSRCPATH=~/repos/my-linux-cip/.out

# SDK path. It is used to set the cross build environment variables
SDK_PATH=/opt/poky/2.4.3-we

# The module (.ko) can be installed automatically on the target via scp
TARGET_IP_ADDRESS=192.168.10.125

# Do not edit

# The sources are not available on github
# File is RCG3VUDRL4101ZDO.tar.bz2 in the vlp:
# meta-rzg2/recipes-kernel/kernel-module-uvcs/kernel-module-uvcs-drv
# or in the folder RCG3VUDRL4101ZDO in the RCG3VUDRL4101ZDO_3_0_17.zip part of the multimedia package
tar -xvf RCG3VUDRL4101ZDO.tar.bz2
pushd RCG3VUDRL4101ZDO

# Patch file is available in the vlp:
# meta-rzg2/recipes-kernel/kernel-module-uvcs/kernel-module-uvcs-drv
git apply ${PATCHES_PATH}/0001-Fixing-build-error-kernel-module-uvcs.patch

# Prepare environment
source ${SDK_PATH}/environment-setup-aarch64-poky-linux
export KERNELDIR=${KERNELSRCPATH}
export UVCS_SRC=$PWD/src
export UVCS_INC=$PWD
export VCP4_SRC=$PWD/src
KERNEL_VERSION=$(<${KERNELDIR}/include/config/kernel.release)

pushd src/makefile

# Make
make 

cp Module.symvers $KERNELDIR/include/UVCS.symvers

# Install
scp uvcs_drv.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra


