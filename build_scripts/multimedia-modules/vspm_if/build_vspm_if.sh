#!/bin/bash

set -e

# Do not edit

source ../config.ini

# The sources are available on github
if [ ! -d "vspmif_drv" ] ; then
  git clone -b rcar_gen3 git://github.com/renesas-rcar/vspmif_drv.git
fi

pushd vspmif_drv

# Checkout the version that we need
git checkout 6172cc7273aae0345db894faa5ab59777549c247

# Patch
patch -p1 -N < ${VSPMIF_PATCHES_PATH}/0001-vspm_if_main-Add-missing-linux-header.patch || true

# Prepare environment
eval ${SDK_SETUP}
export KERNELSRC=${KERNEL_OUT_DIR}
pushd vspm_if-module/files/vspm_if/drv
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -C $KERNELSRC M=$PWD KBUILD_EXTRA_SYMBOLS=../include/vspm.symvers modules

cp ../include/vspm_if.h $KERNELSRC/../include
cp Module.symvers $KERNELSRC/include/vspm_if.symvers

# Install
if [ ${TARGET_INSTALL} = TRUE ]
then 
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp vspm_if.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
pushd

cp ./vspm_if-module/files/vspm_if/drv/vspm_if.ko ../../build



















