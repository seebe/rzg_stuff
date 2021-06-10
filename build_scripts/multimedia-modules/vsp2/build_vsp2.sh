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
git clone -b rcar-gen3 git://github.com/renesas-rcar/vsp2driver.git

pushd vsp2driver

# Checkout the version that we need
git checkout 0ecf35aa05c103ba4d3ab83e3320a22fccd912c3

# Prepare environment
source ${SDK_PATH}/environment-setup-aarch64-poky-linux
export KERNELSRC=${KERNELSRCPATH}
pushd vsp2driver
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -C $KERNELSRC M=$PWD KBUILD_EXTRA_SYMBOLS=../include/vspm.symvers modules

cp linux/vsp2.h $KERNELSRC/../include
cp Module.symvers $KERNELSRC/include/vsp2.symvers

# Install
scp vsp2.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra



















