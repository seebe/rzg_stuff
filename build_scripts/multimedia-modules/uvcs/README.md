# UVCS module build script

This is a script to build the UVCSnel module of the RZ/G2E-N-M-H devices independently of Yocto.

The source files required can be downloaded from this web-page (Multimedia Package):
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

The require file is RCG3VUDRL4101ZDO.tar.bz2 that can be found in the folder RCG3VUDRL4101ZDO in the RCG3VUDRL4101ZDO_3_0_17.zip part of the multimedia package.


Patch files are also required and they can be found in the VLP:
meta-rzg2/recipes-kernel/kernel-module-uvcs-drv/kernel-module-uvcs-drv


