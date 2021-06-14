# Multimedia Modules build script

This is a script to build the multimedia module of the RZ/G2E-N-M-H devices independently of Yocto.

Because of licensing, you have to download the multimedia package yourself from the Renesas website:

https://www.renesas.com/us/en/products/microcontrollers-microprocessors/rz-cortex-a-mpus/rzg-linux-platform/rzg-marketplace/verified-linux-package/rzg2-mlp-eva

In order to build all modules you have to extract and copy the relevant GPU file:

 RZ/G2E -> GSX_KM_E3.tar.bz2 from the RCE3G001L4101ZDO_2_0_9.zip
 RZ/G2N -> GSX_KM_M3N.tar.bz2 from the RCN3G001L4101ZDO_2_0_9.zip
 RZ/G2M -> GSX_KM_M3.tar.bz2 from the RCM3G001L4101ZDO_2_0_9.zip
 RZ/G2H -> GSX_KM_H3.tar.bz2 from the RCH3G001L4101ZDO_2_0_9.zip

in the gles directory.

Then extract the RCG3VUDRL4101ZDO.tar.bz2 from the RCG3VUDRL4101ZDO_3_0_17.zip and copy in the ucvs folder.

In addition in each of the script you have to update the parameters (e.g. Linux kernel and SDK path) to match your environment.
