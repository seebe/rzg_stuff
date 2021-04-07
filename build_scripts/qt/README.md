# Script to compile Qt for RZ/G2

First you need to have the sdk for RZ/G2. 
The SDK on yocto is built with the following command: 

`bitbake core-image-weston -c populate_sdk` 

or 

`bitbake core-image-qt -c populate_sdk`

In the latter case the Qt 5.6.3 version is also included in the SDK. This is fine, the new version will be installed in a separate folder (default: [SYSROOT]/usr/local/Qt-5.14.2). You can then choose which version use when building applications.

## TODO / limitations:

- At the moment the script does not build qtwebengine. By default the standard images do not include gperf so qtwebengine is excluded by the configuration anyway.
- Qt version 5.14.2 and 5.12.10 are the only versions tested, other versions may work as well.
- gstreamers applications may be unstable.

## Usage

Install and enter the sdk environment
`./build-qt.sh <platform-name>`

E.g.
`./build-qt.sh rzg2m` 


