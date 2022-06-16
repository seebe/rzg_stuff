#!/bin/bash

set -e

# Do not edit
source ../config.ini

# Note that this script support kernel v5.10 only
if [ ${KERNEL_VERSION} != 5.10 ]
then
  echo "This script support kernel v5.10 only"
  exit -1
fi


# The sources are not available on github
# File is mali_pkg_eval_v1.0.tar.gz

tar xvfz ${MALI_TAR}
pushd mali_pkg
tar xvfz mali_km_r35p0.tar.gz
pushd mali_km

# Patch files are part of the package
patch -p1 -N < ${MALI_PATCHES_PATH}/5.10/0001-support-for-linux-kernel-v5.10.patch  || true
patch -p1 -N < ${MALI_PATCHES_PATH}/5.10/0002-Set-the-performance-governor-by-default.patch  || true
patch -p1 -N < ${MALI_PATCHES_PATH}/5.10/0003-fix-kernel-warning-when-try-to-enable-disable-regula.patch  || true


# Prepare environment
eval ${SDK_SETUP}
export KDIR=${KERNEL_OUT_DIR}
export BUILD=release
export MALI_PLATFORM_NAME="device tree"
export CONFIG_MALI_MIDGARD=m
export MALI_KBASE_DIR="drivers/gpu/arm/midgard"
KERNEL_VERSION=$(<${KDIR}/include/config/kernel.release)

pushd ${MALI_KBASE_DIR}

# Make
make -j$(nproc) 

cp Module.symvers $KDIR/../include/mali.symvers

# Install
if [ ${TARGET_INSTALL} = TRUE ]
then 
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp mali_kbase.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
popd

mkdir -p ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra
cp ${MALI_KBASE_DIR}/mali_kbase.ko ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra

popd
popd

