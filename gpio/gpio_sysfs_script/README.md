
# GPIO Script
**gpio.sh**
This script makes it easier to access GPIOs on and RZ/G board using the sysfs (/sys) interface.
Simple execute the script without any parameters (./gpio.sh) in order to view the help text.


## Example on EK874 RZ/G2E board
This will turn the LED on and Off which is on port pin  3-14

    $ ./gpio.sh set 3 14 1
    $ ./gpio.sh set 3 14 0
    $ ./gpio.sh set 3 14 1
    $ ./gpio.sh set 3 14 0
    $ ./gpio.sh free 3 14

