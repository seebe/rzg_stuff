# README of the RZ/Five Bare Metal example
</Div>

The RZ/Five Bare Metal example is a sample software for Renesas RZ/Five Series MPUs.

Build instructions:
1) Build Andes GNU toolchain by following the instructions here:
https://github.com/andestech/nds-gnu-toolchain
Make sure you modify the Newlib build script according to this settings:
nds64le-elf-newlib-v5d	rv64imfdcxandes	lp64d	andes-25-series	riscv64-elf
2) Set path and environment variables accordingly, e.g.
PATH=NDS_DIR/nds64le-elf-newlib-v5d/bin:$PATH; export CROSS_COMPILE=riscv64-elf-; export ARCH=riscv
3) make
