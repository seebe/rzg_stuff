#!/bin/bash

set -e

# Do not edit

source ../config.ini

# The sources are available on github
if [ ! -d "vspm_drv" ] ; then
  git clone -b rcar_gen3 git://github.com/renesas-rcar/vspm_drv.git
fi
pushd vspm_drv

# Checkout the version that we need
git checkout 7f854a9a1c4760255a54b7c14891d1545ed1bf43

# Prepare environment
eval ${SDK_SETUP}
export KERNELSRC=${KERNEL_OUT_DIR}
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
if [ ${TARGET_INSTALL} = TRUE ]
then 
  scp vspm.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
pushd

cp ./vspm-module/files/vspm/drv/vspm.ko ../../build



















