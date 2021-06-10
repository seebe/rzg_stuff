#!/bin/bash

set -e

# Set your parameters here

# This is the path where the kernel is built
KERNELSRCPATH=~/repos/my-linux-cip/.out

# SDK path. It is used to set the cross build environment variables
SDK_PATH=/opt/poky/2.4.3-we

# The module (.ko) can be installed automatically on the target via scp
TARGET_IP_ADDRESS=192.168.10.125

# Do not edit

# The sources are available on github
git clone -b rcar_gen3 git://github.com/renesas-rcar/vspm_drv.git

pushd vspm_drv

# Checkout the version that we need
git checkout 7f854a9a1c4760255a54b7c14891d1545ed1bf43

# Prepare environment
source ${SDK_PATH}/environment-setup-aarch64-poky-linux
export KERNELSRC=${KERNELSRCPATH}
pushd vspm-module/files/vspm/drv
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -C $KERNELSRC M=$PWD

# Copy some headers into kernel source code (used by other modules)
cp ../include/vspm_public.h $KERNELSRC/../include/
cp ../include/vspm_cmn.h $KERNELSRC/../include/
cp ../include/vsp_drv.h $KERNELSRC/../include/
cp ../include/fdp_drv.h $KERNELSRC/../include/
cp Module.symvers $KERNELSRC/include/vspm.symvers

# Install
scp vspm.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra



















