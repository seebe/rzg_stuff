# RZ/G2 Build Scripts

These scripts allow you to build outside of the Yocto build environment.

You will find a README_xxx.md for each software.

## Repository Installs

Please refer to file **Repository Installs.txt** to find copy/paste commands to get the source code.

Note that for some repositories, especially the kernel repositories, you will need additional patches that are not in the public github.


## Toolchain Installs

You can use the Yocto SDK Toolchain from the Renesas BSP.

You can also use an external toolchain such as Linaro or ARM.
Please refer to file **Toolchain Installs.txt** to find copy/paste commands to get the source code.

## Directory Locations

This script assumes that your source code repositories are kept in a directory under this one and they use the **same directory names** as below.

For example:
<pre>
├── build_scripts_new
│   ├── rzg_trusted-firmware-a/
│   ├── mbedtls/
│   ├── renesas-u-boot-cip/
│   ├── rz_linux-cip/
│   ├── rzg2_flash_writer/
│   ├── build.sh
│   ├── build_xxxx.sh
│   ├── build_xxxx.sh
│   └── README.md
</pre>

**Hint:**<br>
You can create a new directory and use symlinks to the build.sh files.
This will allow you to keep 1 copy of the rzg_stuff repository on your PC, but use the build files in multiple places.
Then if you update your rzg\_stuff repository (git pull), all your build scripts will be also updated (because they all point back to the same place).<br>
For example:
<pre>
$ mkdir rzg2l_code
$ cd rzg2l_code
$ for i in /home/renesas/rzg/rzg_stuff/build_scripts_new/build*.sh ; do ln -vs $i ; done
$ ls -l
</pre>

## Board Settings File (board.ini)

All the configuration settings for your board will be saved in a board.ini file.

This file will be automatically created for you.

You should not need to modify any of the build_xxx.sh files.

## Output Directory

After each build, the files you need will be copied to an output directory named output_xxxx where xxxx is the name of your board.

<pre>
├── build_scripts_new
│   ├── rzg_trusted-firmware-a/
│   ├── renesas-u-boot-cip/
│   ├── output_xxxx/        <<<< HERE <<<<
│   ├── build.sh
│   └── README.md
</pre>

## Getting Started

1) Install a toolchain as per **Toolchain Installs.txt**

2) Download(clone) the source code repositories as per **Repository Installs.txt** and apply any patches that are needed.

3) Use this command first to select your board.
<pre>
$ ./build.sh s
</pre>

4) Run the **build.sh** script with no arguments to get a list of options. **Do not run the other build_xxx.sh file directly.** Always call only build.sh.
<pre>
$ ./build.sh
</pre>
