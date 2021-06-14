#!/bin/bash
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
