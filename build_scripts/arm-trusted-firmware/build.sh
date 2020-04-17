#!/bin/bash

# HiHope RZ/G2M
#MACHINE=hihope-rzg2m

# HiHope RZ/G2N
#MACHINE=hihope-rzg2n

# Silicon Linux RZ/G2E
#MACHINE=ek874

if [ "$MACHINE" == "" ] ; then
  echo "You need to set MACHINE first"
  exit
fi

# Check out ATF repository
# $ git clone git://github.com/renesas-rcar/arm-trusted-firmware.git
# $ cd arm-trusted-firmware
# $ git checkout rcar_gen3

# Check out meta-rzg2 layer (contains VLP64 patches)
# $ mkdir z_patches
# $ cd z_patches
# $ git clone https://github.com/renesas-rz/meta-rzg2
# $ cd meta-rzg2
# $ git checkout master
# $ cd ../..

# VLP64 v1.0.3rt
# (optional) $ cd z_patches/meta-rzg2 ; git checkout BSP-1.0.3-RT ; cd ../..
# $ git checkout -b vlp64_v103rt c8b88aa5dc11be44dee1f67a894bb0076fb5f1db
# $ ./build make_patches
DIR=vlp64_v103rt
if [ "$1" == "make_patches" ] ; then
  # Some patches are just diff, so turn them all into diff, then into mailbox patches
  mkdir -p z_patches/$DIR
  rm z_patches/$DIR/*
  cp z_patches/meta-rzg2/recipes-bsp/arm-trusted-firmware/files/*.patch z_patches/$DIR
  cd z_patches/$DIR
  for filename in *.patch ; do
    #echo $filename
    LINE=`grep --line-number --max-count=1 "diff --git" $filename | sed 's/:.*//'`
    #echo LINE=$LINE
    if [ "$LINE" != "1" ] ; then
      LINE=`expr $LINE - 1`
      sed -i -e "1,${LINE}d" $filename
    fi
    # Add in git git mailbox header at begining of file
    SUBJECT=${filename::-6}
    sed -i "1 i\From: vlp64@renesas.com" $filename
    sed -i "2 i\Date: $(date -R)" $filename
    sed -i "3 i\Subject: $SUBJECT" $filename
    sed -i "4 i\ " $filename
    sed -i "5 i\ $filename" $filename
    sed -i "6 i\---" $filename
  done
  echo "To Check: meld z_patches/meta-rzg2/recipes-bsp/arm-trusted-firmware/files z_patches/$DIR"
  echo "To Apply: git am z_patches/$DIR/*"
  exit
fi


# Check for Yocto SDK setup
if [ "$TARGET_PREFIX" == "" ] ; then
  echo "Yocto SDK environment not set up"
  echo "source /opt/poky/2.4.3/environment-setup-aarch64-poky-linux"
  exit
fi

# As for GCC 4.9, you can get a colorized output
export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# Find out how many CPU processor cores we have on this machine
# so we can build faster by using multithreaded builds
NPROC=2
if [ "$(which nproc)" != "" ] ; then  # make sure nproc is installed
  NPROC=$(nproc)
fi
BUILD_THREADS=$(expr $NPROC + $NPROC)

PLATFORM=rcar
#ATFW_OPT_LOSSY = "${@base_conditional("USE_MULTIMEDIA", "1", "RCAR_LOSSY_ENABLE=1", "", d)}"
#ATFW_OPT_r8a774c0 = "LSI=G2E RCAR_SA0_SIZE=0 RCAR_AVS_SETTING_ENABLE=0 RZG_EK874=1 PMIC_ROHM_BD9571=0 RCAR_SYSTEM_SUSPEND=0 RCAR_DRAM_DDR3L_MEMCONF=1 RCAR_DRAM_DDR3L_MEMDUAL=1 SPD="none""

#ATFW_OPT_r8a774a1 = "LSI=G2M RCAR_DRAM_SPLIT=2 RCAR_AVS_SETTING_ENABLE=0 RZG_HIHOPE_RZG2M=1 PMIC_ROHM_BD9571=0 RCAR_SYSTEM_SUSPEND=0 RCAR_SECURE_BOOT=0 SPD="none""

#ATFW_OPT_r8a774b1 = "LSI=G2N RCAR_AVS_SETTING_ENABLE=0 RZG_HIHOPE_RZG2N=1 PMIC_ROHM_BD9571=0 RCAR_SYSTEM_SUSPEND=0 SPD="none""

#ATFW_OPT_append_r8a774c0 = "${@base_conditional("USE_ECC", "1", " LIFEC_DBSC_PROTECT_ENABLE=0 RZG_DRAM_EK874_ECC=1 ", "",d)}"

#ATFW_OPT_append_r8a774a1 = "${@base_conditional("USE_ECC", "1", " LIFEC_DBSC_PROTECT_ENABLE=0 RZG_DRAM_HIHOPE_RZG2M_ECC=1 RCAR_DRAM_SPLIT=0", " ${ATFW_OPT_LOSSY} ",d)}"

#ATFW_OPT_append_r8a774b1 = "${@base_conditional("USE_ECC", "1", " LIFEC_DBSC_PROTECT_ENABLE=0 RZG_DRAM_HIHOPE_RZG2N_ECC=1", " ${ATFW_OPT_LOSSY} ",d)}"

#ATFW_OPT_append = "${@base_conditional("ECC_FULL", "1", " RZG_DRAM_ECC_FULL=1 ", "",d)}"


# (USE_MULTIMEDIA, do not set if using ECC
#RCAR_LOSSY_ENABLE=1

# RZ/G2E
if [ "$MACHINE" == "ek874" ] ; then
  ATFW_OPT="LSI=G2E RCAR_SA0_SIZE=0 RCAR_AVS_SETTING_ENABLE=0 RZG_EK874=1 PMIC_ROHM_BD9571=0 RCAR_SYSTEM_SUSPEND=0 RCAR_DRAM_DDR3L_MEMCONF=1 RCAR_DRAM_DDR3L_MEMDUAL=1 SPD="none""
fi

#RZ/G2M
if [ "$MACHINE" == "hihope-rzg2m" ] ; then
  ATFW_OPT="LSI=G2M RCAR_DRAM_SPLIT=2 RCAR_AVS_SETTING_ENABLE=0 RZG_HIHOPE_RZG2M=1 PMIC_ROHM_BD9571=0 RCAR_SYSTEM_SUSPEND=0 RCAR_SECURE_BOOT=0 SPD="none""
fi

# RZ/G2N
if [ "$MACHINE" == "hihope-rzg2n" ] ; then
ATFW_OPT="LSI=G2N RCAR_AVS_SETTING_ENABLE=0 RZG_HIHOPE_RZG2N=1 PMIC_ROHM_BD9571=0 RCAR_SYSTEM_SUSPEND=0 SPD="none""
fi

#ECC
#ECC_OPTS="LIFEC_DBSC_PROTECT_ENABLE=0 RZG_DRAM_EK874_ECC=1 "
#ECC_OPTS="LIFEC_DBSC_PROTECT_ENABLE=0 RZG_DRAM_HIHOPE_RZG2M_ECC=1 RCAR_DRAM_SPLIT=0"
#ECC_OPTS="LIFEC_DBSC_PROTECT_ENABLE=0 RZG_DRAM_HIHOPE_RZG2N_ECC=1"

#ATFW_OPT_LOSSY = "${@base_conditional("USE_MULTIMEDIA", "1", "RCAR_LOSSY_ENABLE=1", "", d)}"

#export CROSS_COMPILE="${TARGET_PREFIX}"

# Let the Makefile handle setting up the CFLAGS and LDFLAGS as it is a standalone application
unset CFLAGS
unset LDFLAGS
unset AS
unset LD

make distclean
make -j $BUILD_THREADS bl2 bl31 dummytool PLAT=${PLATFORM} ${ATFW_OPT} ${ECC_OPTS} ${RCAR_LOSSY_ENABLE} O=$OUT

DEPLOYDIR=z_deploy
mkdir -p $DEPLOYDIR

# Copy IPL to deploy folder
cp build/${PLATFORM}/release/bl2/bl2.elf ${DEPLOYDIR}/bl2-${MACHINE}.elf
cp build/${PLATFORM}/release/bl2.bin ${DEPLOYDIR}/bl2-${MACHINE}.bin
cp build/${PLATFORM}/release/bl2.srec ${DEPLOYDIR}/bl2-${MACHINE}.srec
cp build/${PLATFORM}/release/bl31/bl31.elf ${DEPLOYDIR}/bl31-${MACHINE}.elf
cp build/${PLATFORM}/release/bl31.bin ${DEPLOYDIR}/bl31-${MACHINE}.bin
cp build/${PLATFORM}/release/bl31.srec ${DEPLOYDIR}/bl31-${MACHINE}.srec
cp tools/dummy_create/bootparam_sa0.srec ${DEPLOYDIR}/bootparam_sa0.srec
cp tools/dummy_create/cert_header_sa6.srec ${DEPLOYDIR}/cert_header_sa6.srec

echo "-------------------------------------"
echo "    Files copied to ${DEPLOYDIR}"
echo "-------------------------------------"


