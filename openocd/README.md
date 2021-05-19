# This is a collection of files to extend the support of OpenOCD to RZ/G2.

This guide:

https://renesas.info/wiki/RZ-G/RZG_openocd

can be followed as baseline. You just have to patch the openocd sources with the patch files available here after the clone.

Then the command to attach to RZ/G2 using JTAG with OpenOCD is:

openocd -f share/openocd/scripts/interface/ftdi/flyswatter2.cfg -c “set SOC G2L” -f share/openocd/scripts/target/renesas_rz_g2.cfg

The possible SOC are: G2H, G2M, G2N, G2E and G2L (default).

Note that you don't really need sudo to run OpenOCD, just add yourself to the plugdev and dialout groups:

```
 sudo usermod -a -G plugdev username
 sudo usermod -a -G dialout username
```

The gdb command files can be launched using the ```source``` command, e.g.

```
(gdb) source ~/rzg_stuff/openocd/gdb_smarc_g2l_uboot
```


