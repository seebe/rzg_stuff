# Multimedia Modules build script

This is a script to build the multimedia module of the RZ/G2E-N-M-H (kernel version 4.19 and 5.10) and RZ/G2L (kernel 5.10 only) devices independently of Yocto.

USAGE:

1) Because of licensing, you have to download the multimedia package yourself from the Renesas website.

Kernel 4.19:
https://www.renesas.com/us/en/products/microcontrollers-microprocessors/rz-cortex-a-mpus/rzg-linux-platform/rzg-marketplace/verified-linux-package/rzg2-mlp-eva

Kernel 5.10, RZ/G2E-N-M-H:
https://www.renesas.com/us/en/products/microcontrollers-microprocessors/rz-mpus/rzg-linux-platform/rzg-marketplace/verified-linux-package/rz-mpu-multimedia-package-rzg2h-rzg2m-rzg2n-and-rzg2e#overview

Kernel 5.10, RZ/G2L, GPU:
https://www.renesas.com/us/en/products/microcontrollers-microprocessors/rz-arm-based-high-end-32-64-bit-mpus/rzg2l-mali-graphic-library-evaluation-version

Kernel 5.10, RZ/G2L, codec:
https://www.renesas.com/us/en/software-tool/rz-mpu-video-codec-library-evaluation-version-rzg2l-and-rzv2l

The expected file names are, respectively:

RZG2_Group_Evaluation_Software_Package_for_Linux_20200619.tar.gz
RTK0EF0045Z0022AZJ-v1.0_EN.zip
RTK0EF0045Z13001ZJ-v1.0_EN.zip
RTK0EF0045Z15001ZJ-v0.56_EN.zip

2) Copy the downloaded files in the mm_packages folder

3) Execute the extract.sh script, this will allow the other scripts to use the right files.
The file names may vary but the script should be able to cope with that.

4) Update the parameters (e.g. Linux kernel, SDK path, device, etc) to match your environment in the config.ini file.
The file names may need to be adjusted too (in case the version is not exactly the one shown in the file names above).

5) Launch build_all.sh to build all modules related to the device chosen.
You can also build the modules one by one by entering the corresponding folder and launching the related script.

6) The modules are going to be installed in the chosen deploy directory (DEPLOY_DIR).
The path is already adjusted (e.g. lib/modules/...), ready to be copied in the target root file system.

KNOWN ISSUES:
The SDK compiler (built with Yocto VLP3.0.0) issues errors related to unsupported flags.
In order to be able to build all modules successfully another Arm toochain has to be used (see config.ini).

In contrast with what is built by Yocto, the Mali module built issues an harmless but annoying kernel warning periodically.
The warning can be silenced applyng an additional patch before building.
Edit file mali/build_mali.sh and append the following line to the patches:

		patch -p1 -N < ../../../silent_mali_kernel_warning.patch || true

Then build as per point 5.
