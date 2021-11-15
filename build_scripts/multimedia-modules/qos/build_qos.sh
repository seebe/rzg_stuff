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
git checkout d32fbee4d7b76056c37935ff31102c3583801a29

# Patch
patch -p1 -N < ${QOS_PATCHES_PATH}/0001-qos_drv-include-mod_devicetable.h.patch || true

# Prepare environment
eval ${SDK_SETUP}
unset KERNELSRC
export KERNELSRC=${KERNEL_OUT_DIR}
pushd qos-module/files/qos/drv/
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make

cp Module.symvers $KERNELSRC/include/qos.symvers

# Install
if [ ${TARGET_INSTALL} = TRUE ]
then 
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp qos.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
pushd

cp ./qos-module/files/qos/drv/qos.ko ../../build




















