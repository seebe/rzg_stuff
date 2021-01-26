#!/bin/bash

if [ "$TARGET_PREFIX" == "" ] ; then

  echo "Yocto SDK environment not set up"
  echo "source /opt/poky/2.4.3/environment-setup-aarch64-poky-linux"
  exit
fi

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

if [ "$BOARD" == "" ] ; then
  echo "Set BOARD first to avoid GUI menu"

  # Read what we programmed last time
  if [ -e "board.ini" ] ; then
    source "board.ini"
  else
    # Some default entries
    BOARD=HIHOPE
    OUTFILE=AArch64_Flash_writer_SCIF_DUMMY_CERT_E6300400_hihope.mot
  fi

  while true ; do
    SELECT=$(whiptail --title "RZ/G2 Flash Writer Configuration" --menu "Select your build options.\nYou may use [ESC]+[ESC] to cancel.\nUse [Tab] key to select buttons.\n\nA Blank entry means use default board settings.\n\nUse the <Change> button (or enter) to make changes.\nUse the <Build> button to start the build." 0 0 0 --cancel-button Build --ok-button Change \
	"1.              Select your board:" "  $BOARD"  \
	"2.             Include Dummy cert:" "  $BOOT" \
	"3.  SPI Flash programming support:" "  $SERIAL_FLASH"  \
	"4. eMMC Flash programming support:" "  $EMMC" \
	"5.      USB Download Mode support:" "  $USB" \
	3>&1 1>&2 2>&3)
    RET=$?
    if [ $RET -eq 1 ] ; then
      # save source "board.ini"
      echo "BOARD=$BOARD" > board.ini
      echo "BOOT=$BOOT" >> board.ini
      echo "SERIAL_FLASH=$SERIAL_FLASH" >> board.ini
      echo "EMMC=$EMMC" >> board.ini
      echo "USB=$USB" >> board.ini
      echo "Building..."
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
        *) whiptail --msgbox "Programmer error: unrecognized option" 20 60 1 ;;
      esac || whiptail --msgbox "There was an error running option $SELECT" 20 60 1
    else
      exit 1
    fi
  done
  exit
fi

make BOARD=$BOARD $1 $2 $3

