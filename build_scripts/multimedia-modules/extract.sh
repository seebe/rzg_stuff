#!/bin/bash

set -e

if [ -z "$(ls -A ./mm_packages)" ]; then
   echo "mm_packages is empty, please download and copy the multimedia package into it"
   exit
else
   pushd mm_packages
   tar -xvf "RZG2_Group_Evaluation_Software_Package_for_Linux_20200619.tar.gz"
   if [ -z "$(ls -A ./proprietary)" ]; then
   : ; else
      pushd proprietary
      unzip -o "*.zip"
      popd
   fi
   unzip -o "*.zip"
   if [ -z "$(ls -A ./RTK0EF0045Z0022AZJ*)" ]; then
   : ; else
      pushd RTK0EF0045Z0022AZJ-v1.?_EN
      tar -xvf "meta-rz-features.tar.gz"
      popd
   fi
   if [ -z "$(ls -A ./RTK0EF0045Z13001ZJ*)" ]; then
   : ; else
      pushd RTK0EF0045Z13001ZJ-v?.?_EN
      tar -xvf "meta-rz-features.tar.gz"
      popd
   fi
   if [ -z "$(ls -A ./RTK0EF0045Z15001ZJ*)" ]; then
   : ; else
      pushd RTK0EF0045Z15001ZJ-v?.??_EN
      tar -xvf "meta-rz-features.tar.gz"
      popd
   fi
   popd
fi

