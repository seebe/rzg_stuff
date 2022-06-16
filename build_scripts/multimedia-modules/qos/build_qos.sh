#!/bin/bash

set -e

source ../config.ini

# Do not edit

# The sources are available on github
if [ ! -d "qos_drv" ] ; then
  git clone -b rcar-gen3 git://github.com/renesas-rcar/qos_drv.git
fi 

pushd qos_drv

# Checkout the version we need
if [ ${KERNEL_VERSION} = 4.19 ]
then
  git checkout d32fbee4d7b76056c37935ff31102c3583801a29
elif [ ${KERNEL_VERSION} = 5.10 ]
then
  git checkout 90981d2aa1730589fa87b50f07d9feec09396b9b
else
  echo "Kernel version not set"
  popd
  exit -1
fi

# Patch
patch -p1 -N < ${QOS_PATCHES_PATH}/0001-qos_drv-include-mod_devicetable.h.patch || true

# Prepare environment
eval ${SDK_SETUP}
unset KERNELSRC
export KERNELSRC=${KERNEL_OUT_DIR}
pushd qos-module/files/qos/drv/
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -j$(nproc)

cp Module.symvers $KERNELSRC/../include/qos.symvers

# Install
if [ ${TARGET_INSTALL} = TRUE ]
then 
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp qos.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
popd

mkdir -p ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra
cp ./qos-module/files/qos/drv//qos.ko ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra

popd



















