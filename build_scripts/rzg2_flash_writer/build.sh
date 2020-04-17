#!/bin/bash

if [ "$TARGET_PREFIX" == "" ] ; then

  echo "Yocto SDK environment not set up"
  echo "source /opt/poky/2.4.3/environment-setup-aarch64-poky-linux"
  exit
fi

#make clean

################################
#    HiHope RZ/G2M and RZ/G2N
################################
#BOARD=HIHOPE
#OUTFILE=AArch64_Flash_writer_SCIF_DUMMY_CERT_E6300400_hihope.mot

################################
# RZG2E
################################
#BOARD=EK874
#OUTFILE=AArch64_Flash_writer_SCIF_DUMMY_CERT_E6300400_ek874.mot

if [ "$BOARD" == "" ] ; then
  echo "You need to set BOARD first"
  exit
fi

make BOARD=$BOARD $

