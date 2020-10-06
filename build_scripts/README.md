These scripts allow you to build outside of the Yocto build environment.

You will find a README.md in each directory.

### Toolchain

You can use the Yocto SDK toolchain from VLP64 v1.0.4 or later.

Or, you can use an exernal toolchan such as Linaro.
For example:
    **Linaro AArch64 2019.12**
     https://releases.linaro.org/components/toolchain/binaries/
```
$ sudo mkdir -p /opt/linaro
$ cd /opt/linaro
$ sudo wget https://releases.linaro.org/components/toolchain/binaries/7.5-2019.12/aarch64-linux-gnu/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar.xz
$ sudo tar xf gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar.xz
```
