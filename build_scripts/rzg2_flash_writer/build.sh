#!/bin/bash

# Whiptail colors
export NEWT_COLORS='
root=,blue
'

#make clean

################################
#    HiHope RZ/G2M, RZ/G2N, RZ/G2H
################################
#BOARD=HIHOPE

################################
# RZG2E
################################
#BOARD=EK874

################################
# Makefile options
################################

#BOOT=WRITER_WITH_CERT
#BOOT=WRITER

#SERIAL_FLASH=ENABLE
#SERIAL_FLASH=DISABLE

#EMMC=ENABLE
#EMMC=DISABLE

#USB=ENABLE
#USB=DISABLE

do_board_menu() {
  SELECT=$(whiptail --title "Board Selection" --menu "You may use ESC+ESC to cancel." 0 0 0 \
	"1  HIHOPE" "HiHope RZ/G2M, RZ/G2N, RZ/G2H" \
	"2  EK874" "Silicon Linux RZ/G2E" \
	3>&1 1>&2 2>&3)
  RET=$?
  if [ $RET -eq 0 ] ; then
    case "$SELECT" in
      1\ *) BOARD=HIHOPE ; OUTFILE=AArch64_Flash_writer_SCIF_DUMMY_CERT_E6300400_hihope.mot ;;
      2\ *) BOARD=EK874 ; OUTFILE=AArch64_Flash_writer_SCIF_DUMMY_CERT_E6300400_ek874.mot ;;
      *) whiptail --msgbox "Programmer error: unrecognized option" 20 60 1 ;;
    esac || whiptail --msgbox "There was an error running option $SELECT" 20 60 1
  fi
}
do_boot_menu() {
  SELECT=$(whiptail --title "Boot Certificate Selection" --menu "You may use ESC+ESC to cancel.\n\nA Blank entry means use default board settings." 0 0 0 \
	"1  WRITER_WITH_CERT" "Include Dummy Cert (recommended)" \
	"2  WRITER" "Writer only (no cert)" \
	"3  (default)" "Use Makefile default" \
	3>&1 1>&2 2>&3)
  RET=$?
  if [ $RET -eq 0 ] ; then
    case "$SELECT" in
      1\ *) BOOT=WRITER_WITH_CERT ;;
      2\ *) BOOT=WRITER ;;
      3\ *) BOOT= ;;
      *) whiptail --msgbox "Programmer error: unrecognized option" 20 60 1 ;;
    esac || whiptail --msgbox "There was an error running option $SELECT" 20 60 1
  fi
}
do_serial_menu() {
  SELECT=$(whiptail --title "SPI Flash Programming Support" --menu "You may use ESC+ESC to cancel.\n\nA Blank entry means use default board settings." 0 0 0 \
	"1  ENABLE" "" \
	"2  DISABLE" "" \
	"3  (default)" "Use Makefile default" \
	3>&1 1>&2 2>&3)
  RET=$?
  if [ $RET -eq 0 ] ; then
    case "$SELECT" in
      1\ *) SERIAL_FLASH=ENABLE ;;
      2\ *) SERIAL_FLASH=DISABLE ;;
      3\ *) SERIAL_FLASH= ;;
      *) whiptail --msgbox "Programmer error: unrecognized option" 20 60 1 ;;
    esac || whiptail --msgbox "There was an error running option $SELECT" 20 60 1
  fi
}
do_emmc_menu() {
  SELECT=$(whiptail --title "eMMC Flash Programming Support" --menu "You may use ESC+ESC to cancel.\n\nA Blank entry means use default board settings." 0 0 0 \
	"1  ENABLE" "" \
	"2  DISABLE" "" \
	"3  (default)" "Use Makefile default" \
	3>&1 1>&2 2>&3)
  RET=$?
  if [ $RET -eq 0 ] ; then
    case "$SELECT" in
      1\ *) EMMC=ENABLE ;;
      2\ *) EMMC=DISABLE ;;
      3\ *) EMMC= ;;
      *) whiptail --msgbox "Programmer error: unrecognized option" 20 60 1 ;;
    esac || whiptail --msgbox "There was an error running option $SELECT" 20 60 1
  fi
}
do_usb_menu() {
  SELECT=$(whiptail --title "USB Download Mode Support" --menu "You may use ESC+ESC to cancel.\n\nA Blank entry means use default board settings.\n\nNOTE: This feature not supported on all boards." 0 0 0 \
	"1  ENABLE" "" \
	"2  DISABLE" "" \
	"3  (default)" "Use Makefile default" \
	3>&1 1>&2 2>&3)
  RET=$?
  if [ $RET -eq 0 ] ; then
    case "$SELECT" in
      1\ *) USB=ENABLE ;;
      2\ *) USB=DISABLE ;;
      3\ *) USB= ;;
      *) whiptail --msgbox "Programmer error: unrecognized option" 20 60 1 ;;
    esac || whiptail --msgbox "There was an error running option $SELECT" 20 60 1
  fi
}

do_toolchain_menu() {
  SELECT=$(whiptail --title "Toolchain setup" --menu "You may use ESC+ESC to cancel.\nEnter the command line you want to run before build.\n" 0 0 0 \
	"1  SDK Toolchain" "  /opt/poky/2.4.3/environment-setup-aarch64-poky-linux" \
	"2  Linaro gcc-linaro-7.5.0-2019.12" "  /opt/linaro/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu" \
	"3  (none)" "  No setup" \
	3>&1 1>&2 2>&3)
  RET=$?
  if [ $RET -eq 0 ] ; then
    case "$SELECT" in
      1\ *) TOOLCHAIN_SETUP_NAME="SDK Toolchain" ; TOOLCHAIN_SETUP="source /opt/poky/2.4.3/environment-setup-aarch64-poky-linux" ;;
      2\ *) TOOLCHAIN_SETUP_NAME="Linaro Toolchain" ; TOOLCHAIN_SETUP="PATH=/opt/linaro/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin:\$PATH ; export CROSS_COMPILE=aarch64-linux-gnu-" ;;
      3\ *) TOOLCHAIN_SETUP_NAME="(none)" ; TOOLCHAIN_SETUP= ;;
      *) whiptail --msgbox "Programmer error: unrecognized option" 20 60 1 ;;
    esac || whiptail --msgbox "There was an error running option $SELECT" 20 60 1
  fi
}

if [ "$BOARD" == "" ] ; then
  echo "Set BOARD first to avoid GUI menu"

  # Read what we programmed last time
  if [ -e "board.ini" ] ; then
    source "board.ini"
  else
    # Some default entries
    BOARD=HIHOPE
    OUTFILE=AArch64_Flash_writer_SCIF_DUMMY_CERT_E6300400_hihope.mot
    TOOLCHAIN_SETUP="source /opt/poky/2.4.3/environment-setup-aarch64-poky-linux"
    TOOLCHAIN_SETUP_NAME="SDK Toolchain"
  fi

  while true ; do
    SELECT=$(whiptail --title "RZ/G2 Flash Writer Configuration" --menu "Select your build options.\nYou may use [ESC]+[ESC] to cancel.\nUse [Tab] key to select buttons.\n\nA Blank entry means use default board settings.\n\nUse the <Change> button (or enter) to make changes.\nUse the <Build> button to start the build." 0 0 0 --cancel-button Build --ok-button Change \
	"1.              Select your board:" "  $BOARD"  \
	"2.             Include Dummy cert:" "  $BOOT" \
	"3.  SPI Flash programming support:" "  $SERIAL_FLASH"  \
	"4. eMMC Flash programming support:" "  $EMMC" \
	"5.      USB Download Mode support:" "  $USB" \
	"6.                Toolchain setup:" "  $TOOLCHAIN_SETUP_NAME" \
	3>&1 1>&2 2>&3)
    RET=$?
    if [ $RET -eq 1 ] ; then
      # save source "board.ini"
      echo "BOARD=$BOARD" > board.ini
      echo "BOOT=$BOOT" >> board.ini
      echo "SERIAL_FLASH=$SERIAL_FLASH" >> board.ini
      echo "EMMC=$EMMC" >> board.ini
      echo "USB=$USB" >> board.ini
      echo "TOOLCHAIN_SETUP_NAME=\"$TOOLCHAIN_SETUP_NAME\"" >> board.ini
      echo "TOOLCHAIN_SETUP=\"$TOOLCHAIN_SETUP\"" >> board.ini
      echo "Building..."
      echo "$TOOLCHAIN_SETUP"
      eval $TOOLCHAIN_SETUP
      if [ "$TARGET_PREFIX" == "" ] ; then
        # Not using SDK (poky) toolchain (assuming Linaro)
        # We need to set these before calling make (that's why makefile.linaro exists, but we don't need to use it)
        export CC=${CROSS_COMPILE}gcc
        export AS=${CROSS_COMPILE}as
        export LD=${CROSS_COMPILE}ld
        export AR=${CROSS_COMPILE}ar
        export OBJDUMP=${CROSS_COMPILE}objdump
        export OBJCOPY=${CROSS_COMPILE}objcopy
      fi
      echo "make clean"
      make clean
      echo "make BOARD=$BOARD"
      make BOARD=$BOARD
      break;
    elif [ $RET -eq 0 ] ; then
      case "$SELECT" in
        1.\ *) do_board_menu ;;
        2.\ *) do_boot_menu ;;
        3.\ *) do_serial_menu ;;
        4.\ *) do_emmc_menu ;;
        5.\ *) do_usb_menu ;;
        6.\ *) do_toolchain_menu ;;
        *) whiptail --msgbox "Programmer error: unrecognized option" 20 60 1 ;;
      esac || whiptail --msgbox "There was an error running option $SELECT" 20 60 1
    else
      exit 1
    fi
  done
  exit
fi

if [ "$CROSS_COMPILE" == "" ] ; then
  echo "Cross Compiler (CROSS_COMPILE) not set."
  echo ""
  echo "Yocto SDK environment set up:"
  echo "   source /opt/poky/2.4.3/environment-setup-aarch64-poky-linux"
  echo ""
  echo "Linaro environment set up:"
  echo "   PATH=/opt/linaro/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin:\$PATH ; export CROSS_COMPILE=aarch64-linux-gnu-"
  echo ""
  exit
fi

if [ "$CC" == "" ] ; then
  # We need to set these before calling make (that's why makefile.linaro exists, but we don't need to use it)
  export CC=${CROSS_COMPILE}gcc
  export AS=${CROSS_COMPILE}as
  export LD=${CROSS_COMPILE}ld
  export AR=${CROSS_COMPILE}ar
  export OBJDUMP=${CROSS_COMPILE}objdump
  export OBJCOPY=${CROSS_COMPILE}objcopy
fi

make BOARD=$BOARD $1 $2 $3

