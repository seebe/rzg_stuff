#!/bin/bash

set -e
set -u

DEVICE=${1:?"Use $0 <device>"}
QT_VERSION=5.14.2

if [ ! -d qt5 ]; then 
 git clone https://github.com/qt/qt5.git -b ${QT_VERSION} qt5
fi

pushd qt5
./init-repository -f --module-subset="essential,addon"

 echo "Installing ${DEVICE} configuration"
 install -d qtbase/mkspecs/devices/linux-${DEVICE}-g++
 install -m 0644 ../${DEVICE}/* qtbase/mkspecs/devices/linux-${DEVICE}-g++/

if [ ! -d "qt5-build" ]; then 
	mkdir -p qt5-build
fi
 pushd qt5-build

 ../configure -opensource -confirm-license \
 -sysroot $PKG_CONFIG_SYSROOT_DIR -device linux-${DEVICE}-g++ -device-option CROSS_COMPILE=$CROSS_COMPILE \
 -opengl es2 -qpa wayland-egl -no-linuxfb -no-gbm -make libs -no-feature-printer -no-feature-xcomposite-egl\
 -no-cups -no-glib -no-pulseaudio -no-sql-db2 -no-sql-ibase -no-sql-mysql -no-sql-oci -no-sql-odbc \
 -no-sql-psql -no-sql-sqlite -no-sql-sqlite2 -no-sql-tds -system-xcb -no-tslib\
 -skip qtwebengine

 make -j$(nproc)
 make install
 popd
popd

# Install Qt onto the micro SD
echo -n "Do you want to install Qt ${QT_VERSION} onto the microSD? [y/n]: " ; read ANS
if [ "$ANS" != "y" ] ; then
	exit 0
else
	SD_MOUNT_PATH=/media/$USER/RZ_ext/usr/local/Qt-${QT_VERSION}
	read -p "Installing to ${SD_MOUNT_PATH}" SD_PATH
	echo $SD_MOUNT_PATH
	sudo rsync -avzh $PKG_CONFIG_SYSROOT_DIR/usr/local/Qt-${QT_VERSION} ${SD_MOUNT_PATH}
fi
