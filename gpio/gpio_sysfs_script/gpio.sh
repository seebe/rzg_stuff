# Read in passed command line parameters

CMD=$1
PORT=$2
PIN=$3
VALUE=$4


if [ "$CMD" == "" ] ; then
  echo "usage: <command> <port> <pin> <value>"
  echo "List of commands:"
  echo "  set: Set pin to output and set to <value>"
  echo "  get: Set pin to input and read current value"
  echo "  free: free up (unexport) the GPIO"
  echo "  info: Just print out the Index ID"
  exit
fi

# Ports are indexed counting down from 512. So the highest number will be Port 0.
if [ ! -e /tmp/gpio.txt ] ; then
  find /sys/class/gpio/ -name "gpiochip*" | sed "s:/sys/class/gpio/gpiochip::g" | sort -r > /tmp/gpio.txt
fi


LINE=`expr ${PORT} + 1`

BASEINDEX=`sed "${LINE}q;d" /tmp/gpio.txt`

PININDEX=`expr $BASEINDEX + $PIN`

if [ "$CMD" == "info" ] ; then
  echo $PININDEX
  exit
fi

# Check if already exported
if [ ! -e /sys/class/gpio/gpio${PININDEX} ] ; then
  echo $PININDEX > /sys/class/gpio/export
fi

if [ "$CMD" == "get" ] ; then
  echo in > /sys/class/gpio/gpio${PININDEX}/direction
  cat /sys/class/gpio/gpio${PININDEX}/value
  exit
fi


if [ "$CMD" == "set" ] ; then
  echo out  > /sys/class/gpio/gpio${PININDEX}/direction
  echo $VALUE > /sys/class/gpio/gpio${PININDEX}/value
  exit
fi

if [ "$CMD" == "free" ] ; then
  echo $PININDEX > /sys/class/gpio/unexport
  exit
fi
