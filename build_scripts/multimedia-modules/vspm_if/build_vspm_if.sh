#!/bin/bash

set -e

# Set your parameters here

# These pathes are available in the VLP, path:
# meta-rzg2/recipes-kernel/kernel-module-vspmif/kernel-module-vspmif 
PATCHES_PATH=../patches/vspmif

# This is the path where the kernel is built
KERNELSRCPATH=~/repos/my-linux-cip/.out

# SDK path. It is used to set the cross build environment variables
SDK_PATH=/opt/poky/2.4.3-we

# The module (.ko) can be installed automatically on the target via scp
TARGET_IP_ADDRESS=192.168.10.125

# Do not edit

# The sources are available on github
git clone -b rcar_gen3 git://github.com/renesas-rcar/vspmif_drv.git

pushd vspmif_drv

# Checkout the version that we need
git checkout 6172cc7273aae0345db894faa5ab59777549c247

# Patch
git apply ${PATCHES_PATH}/0001-vspm_if_main-Add-missing-linux-header.patch

# Prepare environment
source ${SDK_PATH}/environment-setup-aarch64-poky-linux
export KERNELSRC=${KERNELSRCPATH}
pushd vspm_if-module/files/vspm_if/drv
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -C $KERNELSRC M=$PWD KBUILD_EXTRA_SYMBOLS=../include/vspm.symvers modules

cp ../include/vspm_if.h $KERNELSRC/../include
cp Module.symvers $KERNELSRC/include/vspm_if.symvers

# Install
scp vspm_if.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra



















