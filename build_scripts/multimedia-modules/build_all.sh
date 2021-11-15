#!/bin/bash
if [ -z "$(ls -A ./mm_packages)" ]; then
   echo "mm_packages is empty, please download and copy the multimedia package into it"
   exit
else
   pushd mm_packages
   tar -xvf "RZG2_Group_Evaluation_Software_Package_for_Linux_20200619.tar.gz"
   pushd proprietary
   unzip -o "*.zip"
   popd
   popd
fi

pushd vspm
./build_vspm.sh
popd
pushd vspm_if
./build_vspm_if.sh
popd
pushd vsp2
./build_vsp2.sh
popd
pushd mmngr
./build_mmngr.sh
popd
pushd gles
./build_gles.sh
popd
pushd uvcs
./build_uvcs.sh
popd
pushd qos
./build_qos.sh
popd
