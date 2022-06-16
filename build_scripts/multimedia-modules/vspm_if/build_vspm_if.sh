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
if [ ${KERNEL_VERSION} = 4.19 ]
then
  git checkout 6172cc7273aae0345db894faa5ab59777549c247
elif [ ${KERNEL_VERSION} = 5.10 ]
then
  git checkout 2fdb2838a5625e4231f1cff5d10079acc4954952
else
  echo "Kernel version not set"
  popd
  exit -1
fi
  
# Patch
if [ ${KERNEL_VERSION} = 4.19 ]
then
  patch -p1 -N < ${VSPMIF_PATCHES_PATH}/0001-vspm_if_main-Add-missing-linux-header.patch || true
elif [ ${KERNEL_VERSION} = 5.10 ]
then
  if [ $device = RZG2L ]
  then
    patch -p1 -N < ${VSPMIF_PATCHES_PATH}/5.10/0001-Add-ISU-to-vspmif.patch  || true
    patch -p1 -N < ${VSPMIF_PATCHES_PATH}/5.10/0002-Remove-width-height-in-isu_dst_t.patch  || true
    patch -p1 -N < ${VSPMIF_PATCHES_PATH}/5.10/0003-Correcting-variable-type.patch  || true
    patch -p1 -N < ${VSPMIF_PATCHES_PATH}/5.10/0004-Remove-unused-memory.patch  || true
    patch -p1 -N < ${VSPMIF_PATCHES_PATH}/5.10/0005-Correction-32bit-variable.patch  || true
  fi    
fi

# Prepare environment
eval ${SDK_SETUP}
export KERNELSRC=${KERNEL_OUT_DIR}
pushd vspm_if-module/files/vspm_if/drv
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -j$(nproc) -C $KERNELSRC M=$PWD KBUILD_EXTRA_SYMBOLS=../include/vspm.symvers modules

cp ../include/vspm_if.h $KERNELSRC/../include
cp Module.symvers $KERNELSRC/../include/vspm_if.symvers

# Install
if [ ${TARGET_INSTALL} = TRUE ]
then 
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp vspm_if.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
popd

mkdir -p ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra
cp ./vspm_if-module/files/vspm_if/drv/vspm_if.ko ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra

popd

















