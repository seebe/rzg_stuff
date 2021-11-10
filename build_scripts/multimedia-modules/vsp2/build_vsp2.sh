#!/bin/bash

set -e

# Do not edit

source ../config.ini

# The sources are available on github
if [ ! -d "vsp2driver" ] ; then
  git clone -b rcar-gen3 git://github.com/renesas-rcar/vsp2driver.git
fi

pushd vsp2driver

# Checkout the version that we need
git checkout 0ecf35aa05c103ba4d3ab83e3320a22fccd912c3

# Prepare environment
source ${SDK_PATH}/environment-setup-aarch64-poky-linux
export KERNELSRC=${KERNEL_OUT_DIR}
pushd vsp2driver
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -C $KERNELSRC M=$PWD KBUILD_EXTRA_SYMBOLS=../include/vspm.symvers modules

cp linux/vsp2.h $KERNELSRC/../include
cp Module.symvers $KERNELSRC/include/vsp2.symvers

# Install
if [ ${TARGET_INSTALL} = TRUE ]
then 
  scp vsp2.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
pushd

cp ./vsp2driver/vsp2.ko ../../build



















