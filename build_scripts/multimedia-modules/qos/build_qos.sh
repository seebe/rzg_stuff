#!/bin/bash

set -e

# Set your parameters here

# These pathes are available in the VLP, path:
# meta-rzg2/recipes-kernel/kernel-module-qos/kernel-module-qos
PATCHES_PATH=../../patches/qos

# This is the path where the kernel is built
KERNELSRCPATH=~/repos/my-linux-cip/.out

# SDK path. It is used to set the cross build environment variables
SDK_PATH=/opt/poky/2.4.3-we

# The module (.ko) can be installed automatically on the target via scp
TARGET_IP_ADDRESS=192.168.10.125

# Do not edit

# The sources are available on github
git clone -b rcar-gen3 git://github.com/renesas-rcar/qos_drv.git

pushd qos_drv

# Checkout the version we need
git checkout d32fbee4d7b76056c37935ff31102c3583801a29

# Patch
git apply ${PATCHES_PATH}/0001-qos_drv-include-mod_devicetable.h.patch

# Prepare environment
source ${SDK_PATH}/environment-setup-aarch64-poky-linux
unset KERNELSRC
export KERNELSRC=${KERNELSRCPATH}
pushd qos-module/files/qos/drv/
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make

cp Module.symvers $KERNELSRC/include/qos.symvers

# Install
scp qos.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra



















