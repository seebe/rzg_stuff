#!/bin/bash

#---------------------------------------------------------------------------
# Please read the README.md file first for proper setup
#---------------------------------------------------------------------------

# HiHope RZ/G2M
MACHINE=hihope-rzg2m
EMMC_BOOT=1
#ECC_FULL=0    # 0=no ECC, 1=ECC dual channel, 2=ECC single channel

# HiHope RZ/G2N
#MACHINE=hihope-rzg2n
#EMMC_BOOT=1
#ECC_FULL=0   # 0=no ECC, 1=ECC dual channel, 2=ECC single channel

# HiHope RZ/G2H
#MACHINE=hihope-rzg2h
#EMMC_BOOT=1
#ECC_FULL=0   # 0=no ECC, 1=ECC dual channel, 2=ECC single channel

# Silicon Linux RZ/G2E
#MACHINE=ek874
#ECC_FULL=0   # 0=no ECC, 1=ECC dual channel, 2=ECC single channel


if [ "$MACHINE" == "" ] ; then
  echo "You need to set MACHINE first"
  exit
fi

#PATH=/opt/linaro/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin:$PATH
#export CROSS_COMPILE="aarch64-linux-gnu-"
#export ARCH=arm64

# Check for Yocto SDK setup
if [ "$TARGET_PREFIX" == "" ] && [ "$CROSS_COMPILE" == "" ] ; then
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

if [ -e plat/renesas/rzg ] ; then
  PLATFORM=rzg
else
  PLATFORM=rcar
fi

# PLAT
#	Set string is "rcar" (VLP v1.0.0-4) or "rzg" (VLP v1.0.5+)

# LOG_LEVEL
#	The IPL provides logging functions ERROR(), NOTICE(), WARN(), INFO() and VERBOSE().
#	50 is all functions for output logs
#
#	Log level   Valid logging function
#	-------------------------------------------------------
#	0           No functions output logs
#	10          ERROR()
#	20          ERROR(), NOTICE()
#	30          ERROR(), NOTICE(), WARN()
#	40          ERROR(), NOTICE(), WARN(), INFO()
#	50          ERROR(), NOTICE(), WARN(), INFO(), VERBOSE()

# DEBUG
#	Set value is 0 or 1. 0 is a release build, and 1 is a debug build
#	If LOG_LEVEL value hasn??t been set, LOG_LEVEL is set as the DEBUG value in the following table
#
#	DEBUG build    LOG_LEVEL  Valid logging functions
#	-------------------------------------------------------
#	0     release  20         ERROR(), NOTICE()
#	1     debug    40         ERROR(), NOTICE(), WARN(), INFO()

# SPD
#	The IPL provides configuration to load image of BL32
#	Set string is ??none?? or ??opteed??.
#	"none" = Does not load the image of BL32
#	"opteed" = Load the image of BL32 from HyperFlash / QSPI Flash / eMMC

# RCAR_QOS_TYPE
#	AXI-bus has the QoS arbitration to control latency and bandwidth.
#	0 = Enable the QoS arbitration setting (Default setting)
#	3 = Disable the QoS arbitration setting


# RCAR_DRAM_SPLIT
#	DRAM split setting in the SDRAM setting
#	0 = Linear (No split)
#	1 = 4 channel split
#	2 = 2 channel split
#	3 = R-Car H3: 4 channel split / R-Car M3: 2 channel split / R-Car M3N:Linear / R-Car E3: Linear

# PMIC_ROHM_BD9571
#	This option represents the range of code implementation depending on the PMIC (ROHM BD9571) mounted on the
#	evaluation board described in 3.1 hardware environment.


# RCAR_AVS_SETTING_ENABLE
#	PMIC initial voltage setting
#	This option must be set to disabled in the case of R-Car E3.
#	0 = disable
#	1 = enable


# LSI
#	G2E,G2M,G2N,G2H

# RCAR_SA6_TYPE:
#	0 = for Hyper Flash / QPSI Flash boot (Default setting)
#	1 = for eMMC boot

# RCAR_BL33_EXECUTION_EL
#	Set the exception level of BL33
#	0 = EL1 (Default setting)
#	1 = EL2
#

# RCAR_SYSTEM_SUSPEND
#	0 = No Suspend to RAM
#	1 = Suspend to RAM

# RCAR_REF_INT
#	Select DRAM refresh interval.
#	0 = Default setting (H3, M3, M3N 1.95us / E3 3.90us)
#	1 = Optional setting (H3, M3, M3N 3.90us / E3 7.80us)

# RCAR_REWT_TRAINING
#	Select "periodic write DQ training" mode.
#	0 = not available
#	1 = available (Default setting)

# RCAR_BL2_DCACHE
#	enables MMU and D-cache (L1 data cache / L2 cache) on IPL.
#	0 = Disable the D-cache setting (Default setting)
#	1 = Enable the D-cache setting

# RCAR_SA0_SIZE
#	Switch the IPL size of dummy certificate
#	0 = For R-Car E3, IPL size is 80KB.
#	1 = For R-Car H3/M3/M3N, IPL size is 170KB. (Default setting)

# RCAR_DRAM_DDR3L_MEMCONF
#	Select DRAM memory size.
#	0 = 1G Byte
#	1 = 2G Byte (Default setting)

# RCAR_DRAM_DDR3L_MEMDUAL
#	Select the SoC output (the number of connected SDRAM on board)
#	0 = CS0, ODT0 enable and CS1, ODT1 disable (SDRAM 2pieces)
#	1 = CS0, ODT0, CS1, ODT1 enable (SDRAM 4pieces) (Default setting)

# RCAR_DRAM_LPDDR4_MEMCONF
#	(RZ/G2H only)
#	The LPDDR4 settings code included in the IPL release supports 2 types of memory configurations for R-Car H3
#	0 = 1G Byte x 4 channel : 4GB
#	1 = 2G Byte x4 channel : 8GB (Default setting)

# RZ/G2E
if [ "$MACHINE" == "ek874" ] ; then
  ATFW_OPT="LSI=G2E RCAR_SA0_SIZE=0 RCAR_AVS_SETTING_ENABLE=0 RZG_EK874=1 PMIC_ROHM_BD9571=0 RCAR_SYSTEM_SUSPEND=0 RCAR_DRAM_DDR3L_MEMCONF=1 RCAR_DRAM_DDR3L_MEMDUAL=1 SPD="none""
  if [ "$ECC_FULL" != "0" ] ; then
    ATFW_OPTS_ECC=" LIFEC_DBSC_PROTECT_ENABLE=0 RZG_DRAM_EK874_ECC=1 "
  fi
fi

#RZ/G2M
if [ "$MACHINE" == "hihope-rzg2m" ] ; then
  # The RZ/G2M v1.3 device mounted on the HiHope-RZG2M board has been found to be unable to boot unless "RCAR_SECURE_BOOT=0"
  ATFW_OPT="LSI=G2M RCAR_DRAM_SPLIT=2 RCAR_AVS_SETTING_ENABLE=0 RZG_HIHOPE_RZG2M=1 PMIC_ROHM_BD9571=0 RCAR_SYSTEM_SUSPEND=0 RCAR_SECURE_BOOT=0 SPD="none""
  if [ "$ECC_FULL" != "0" ] ; then
    ATFW_OPTS_ECC=" LIFEC_DBSC_PROTECT_ENABLE=0 RZG_DRAM_HIHOPE_RZG2M_ECC=1 RCAR_DRAM_SPLIT=0"
  else
    # Reserve Lossy Decompression area for multimedia (only be used if no ECC)
    ATFW_OPT_LOSSY="RCAR_LOSSY_ENABLE=1"
  fi
fi

# RZ/G2N
if [ "$MACHINE" == "hihope-rzg2n" ] ; then
  ATFW_OPT="LSI=G2N RCAR_AVS_SETTING_ENABLE=0 RZG_HIHOPE_RZG2N=1 PMIC_ROHM_BD9571=0 RCAR_SYSTEM_SUSPEND=0 SPD="none""
  if [ "$ECC_FULL" != "0" ] ; then
    ATFW_OPTS_ECC=" LIFEC_DBSC_PROTECT_ENABLE=0 RZG_DRAM_HIHOPE_RZG2N_ECC=1"
  else
    # Reserve Lossy Decompression area for multimedia (only be used if no ECC)
    ATFW_OPT_LOSSY="RCAR_LOSSY_ENABLE=1"
  fi
fi

# RZ/G2H
if [ "$MACHINE" == "hihope-rzg2h" ] ; then
  ATFW_OPT="LSI=G2H RCAR_DRAM_SPLIT=2 RCAR_DRAM_LPDDR4_MEMCONF=1 RCAR_DRAM_CHANNEL=5 RCAR_AVS_SETTING_ENABLE=0 RZG_HIHOPE_RZG2H=1 PMIC_ROHM_BD9571=0 RCAR_SYSTEM_SUSPEND=0 SPD="none""
  if [ "$ECC_FULL" != "0" ] ; then
    ATFW_OPTS_ECC= " LIFEC_DBSC_PROTECT_ENABLE=0 RZG_DRAM_HIHOPE_RZG2H_ECC=1 RCAR_DRAM_SPLIT=0"
  else
    # Reserve Lossy Decompression area for multimedia (only be used if no ECC)
    ATFW_OPT_LOSSY="RCAR_LOSSY_ENABLE=1"
  fi
fi

# MBED is required for VLP v1.0.5+
if [ "$PLATFORM" == "rzg" ] &&  [ "$MBEDTLS_DIR" == "" ] ; then
  if [ -e mbedtls ] ; then
    MBEDTLS_DIR=mbedtls
  elif [ -e ../mbedtls ] ; then
    MBEDTLS_DIR=../mbedtls
  else
    echo "ERROR: You need to have the mbed TLS repo to build"
    exit
  fi
fi

# Cert tool was changed from dummy_tool to rzg for VLP64 v1.0.5+
if [ "$PLATFORM" == "rzg" ] ; then
  TOOL=rzg
else
  TOOL=dummytool
fi


# For eMMC boot, you need to set RCAR_SA6_TYPE=1
if [ "$EMMC_BOOT" == "1" ] ; then
  ATFW_OPT="$ATFW_OPT RCAR_SA6_TYPE=1"
fi

if [ "${ECC_FULL}" == "" ] ; then
  ECC_FULL=0
fi

# Let the Makefile handle setting up the CFLAGS and LDFLAGS as it is a standalone application
unset CFLAGS
unset LDFLAGS
unset AS
unset LD

make distclean
make -j $BUILD_THREADS bl2 bl31 ${TOOL} PLAT=${PLATFORM} ${ATFW_OPT} ${ATFW_OPTS_ECC} RZG_DRAM_ECC_FULL=${ECC_FULL} ${ATFW_OPT_LOSSY} \
	RCAR_RPC_HYPERFLASH_LOCKED=0 \
	MBEDTLS_DIR=$MBEDTLS_DIR \
	O=$OUT $1 $2 $3

# Copy file to deploy folder
if [ ! -e "build/${PLATFORM}/release/bl2/bl2.elf" ] ; then
  exit
fi

if [ "$EMMC_BOOT" == "1" ] ; then
	DEPLOYDIR=z_deploy_emmc
else
	DEPLOYDIR=z_deploy_spi
fi

mkdir -p $DEPLOYDIR

cp build/${PLATFORM}/release/bl2/bl2.elf ${DEPLOYDIR}/bl2-${MACHINE}.elf
cp build/${PLATFORM}/release/bl2.bin ${DEPLOYDIR}/bl2-${MACHINE}.bin
cp build/${PLATFORM}/release/bl2.srec ${DEPLOYDIR}/bl2-${MACHINE}.srec
cp build/${PLATFORM}/release/bl31/bl31.elf ${DEPLOYDIR}/bl31-${MACHINE}.elf
cp build/${PLATFORM}/release/bl31.bin ${DEPLOYDIR}/bl31-${MACHINE}.bin
cp build/${PLATFORM}/release/bl31.srec ${DEPLOYDIR}/bl31-${MACHINE}.srec

# VLP 1.0.4
if [ -e tools/dummy_create/bootparam_sa0.srec ] ; then
	cp tools/dummy_create/bootparam_sa0.srec ${DEPLOYDIR}/bootparam_sa0.srec
	cp tools/dummy_create/cert_header_sa6.srec ${DEPLOYDIR}/cert_header_sa6.srec
fi

# VLP 1.0.5
if [ -e tools/renesas/rzg_layout_create/bootparam_sa0.srec ] ; then
	cp tools/renesas/rzg_layout_create/bootparam_sa0.srec ${DEPLOYDIR}/bootparam_sa0.srec
	cp tools/renesas/rzg_layout_create/cert_header_sa6.srec ${DEPLOYDIR}/cert_header_sa6.srec
fi

# Save what build this was
CURRENT_BRANCH=$(git branch | sed -n -e 's/^\* \(.*\)/\1/p')
echo "Built from branch \"$CURRENT_BRANCH\"" > ${DEPLOYDIR}/build_version.txt

echo "-------------------------------------"
echo "    Files copied to ${DEPLOYDIR}"
echo "-------------------------------------"


