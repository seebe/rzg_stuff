# renesas-u-boot-cip Build Script

This script lets you build the kernel for RZ/G2 **outside** of the Yocto environment.

I would suggest that you keep your linux-cip directory at the same directory level as this rzg_stuff repository.
For example:
```
├── home
│   └── chris
│       └── rzg2
│           ├── linux-cip
│           ├── rzg2_flash_writer
│           └── rzg_stuff

```


## Build Instructions
### Clone and check out the linux-cip.repository
```
$ git clone git://git.kernel.org/pub/scm/linux/kernel/git/cip/linux-cip.git
$ cd linux-cip
$ git checkout linux-4.19.y-cip
```

### Copy in our custom build.sh script
```
$ cp ../rzg_stuff/build_scripts/linux-cip/build.sh  .
```

### Then run:
```
$ ./build.sh make_patches
```
(then copy and paste and execute the git am command the make_patches commands outputs)
```
$ ./build.sh make_config
$ ./build.sh _all
$ ./build.sh deploy
```

### Output Files
The files you need to boot your board with will be under .deploy
