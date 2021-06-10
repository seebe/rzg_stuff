# GPU module build script

This is a script to build the GPU kernel module of the RZ/G2E-N-M-H devices independently of Yocto.

The source files required can be downloaded from his web-page:
https://www.renesas.com/us/en/products/microcontrollers-microprocessors/rz-cortex-a-mpus/rzg-linux-platform/rzg-marketplace/verified-linux-package/rzg2-mlp-eva

There are separate zip files:
	- GPU kernel modules, one for each GPU type;
	- GLSL off-line compiler of OpenGL ES Library, again one for each GPU type;
	- OMX Media Component Common Library for Linux;
	- OMX Media Component H.264 Decoder Library for Linux;
	- OMX Media Component H.264 Encoder Library for Linux;
	- OMX Media Component H.265 Decoder Library for Linux;
	- OMX Media Component Video Decoder Common Library for Linux;
	- OMX Media Component Video Encoder Common Library for Linux;
	- OpenGL ES Library for Linux, one for each GPU type.

The required RZ/G2E file (GSX_KM_E3.tar.bz2) is in RCE3G001L4101ZDO_2_0_9.zip.
The required RZ/G2N file (GSX_KM_M3N.tar.bz2) is in RCN3G001L4101ZDO_2_0_9.zip.
The required RZ/G2M file (GSX_KM_M3.tar.bz2) is in RCM3G001L4101ZDO_2_0_9.zip.
The required RZ/G2H file (GSX_KM_H3.tar.bz2) is in RCH3G001L4101ZDO_2_0_9.zip.

Patch files are also required and they can be found in the VLP:
meta-rzg2/recipes-kernel/kernel-module-gles/kernel-module-gles


