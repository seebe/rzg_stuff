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
if [ ${KERNEL_VERSION} = 4.19 ]
then
  git checkout 7f854a9a1c4760255a54b7c14891d1545ed1bf43
elif [ ${KERNEL_VERSION} = 5.10 ]
then
  git checkout 07787fc1168e7fe37c305aca151a6f756f35874f
else
  echo "Kernel version not set"
  popd
  exit -1
fi

if [ $device = RZG2L ]
then
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0001-Add-ISU-driver.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0002-Add-option-ISU_CSC_RAW.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0003-Add-ISU-to-VSPM.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0004-Modify-Makefile.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0005-remove-work-around-clock-reset-supply.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0006-Support-MUTUAL-mode-for-ISU.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0007-Update-and-fix-some-small-bugs-of-ISU-driver.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0008-Correcting-variable-type.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0009-Wrong-initialize-value-of-clip.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0010-Fix-wrong-output-size-in-setting-case-rs_par-is-NULL.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0011-Fix-error-cannot-detect-NOOUT-in-case-rs_par-NULL.patch || true
  patch -p1 -N < ${VSPM_PATCHES_PATH}/5.10/0012-vspm_main-Update-isu-clock-enable.patch || true
fi    
  

# Prepare environment
eval ${SDK_SETUP}
export KERNELSRC=${KERNEL_OUT_DIR}
pushd vspm-module/files/vspm/drv
KERNEL_VERSION=$(<${KERNELSRC}/include/config/kernel.release)

# Make
make -j$(nproc) -C $KERNELSRC M=$PWD

# Copy some headers into kernel source code (used by other modules)
cp ../include/vspm_public.h $KERNELSRC/../include/
cp ../include/vspm_cmn.h $KERNELSRC/../include/
cp ../include/vsp_drv.h $KERNELSRC/../include/
cp ../include/fdp_drv.h $KERNELSRC/../include/
if [ $device = RZG2L ]
then
 cp ../include/isu_drv.h $KERNELSRC/../include/
fi
cp Module.symvers $KERNELSRC/../include/vspm.symvers

# Install
if [ ${TARGET_INSTALL} = TRUE ]
then 
  ssh root@${TARGET_IP_ADDRESS} "mkdir -p /lib/modules/${KERNEL_VERSION}/extra"
  scp vspm.ko root@${TARGET_IP_ADDRESS}:/lib/modules/${KERNEL_VERSION}/extra
fi
popd

mkdir -p ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra
cp ./vspm-module/files/vspm/drv/vspm.ko ${DEPLOY_DIR}/lib/modules/${KERNEL_VERSION}/extra

popd

















