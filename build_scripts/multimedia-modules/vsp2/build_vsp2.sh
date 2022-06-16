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
if [ ${KERNEL_VERSION} = 4.19 ]
then
  git checkout 0ecf35aa05c103ba4d3ab83e3320a22fccd912c3
elif [ ${KERNEL_VERSION} = 5.10 ]
then
  git checkout b3a116d8ce68371cac21011ca3b3190ae3576987
else
  echo "Kernel version not set"
  popd
  exit -1
fi

# Prepare environment
eval ${SDK_SETUP}
export KERNELSRC=${KERNEL_OUT_DIR}
pushd vsp2driver
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -j$(nproc) -C $KERNELSRC M=$PWD KBUILD_EXTRA_SYMBOLS=../include/vspm.symvers modules

cp linux/vsp2.h $KERNELSRC/../include
cp Module.symvers $KERNELSRC/../include/vsp2.symvers

# Install
if [ ${TARGET_INSTALL} = TRUE ]
then 
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp vsp2.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
popd

mkdir -p ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra
cp ./vsp2driver/vsp2.ko ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra

popd


















