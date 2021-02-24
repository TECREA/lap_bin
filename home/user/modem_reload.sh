#!/bin/sh
#
#
#
#FOUND=`grep "ppp0" /proc/net/dev`
FOUND=`ip link show ppp0 | grep ,UP`
FL_MRST=/sys/class/gpio/gpio24/value


if [ -f "$FILE" ]; then
    echo "$FILE exist"
else 
    echo 24 > /sys/class/gpio/export
    sleep 1
    echo out > /sys/class/gpio/gpio24/direction
    sleep 1
    echo 0 > /sys/class/gpio/gpio24/value
    sleep 1
fi

if  [ -n "$FOUND" ] ; then
    echo PPP0 is up
else
    echo PPP0 is down
    echo 1 > /sys/class/gpio/gpio24/value
    sleep 2
    echo 0 > /sys/class/gpio/gpio24/value
fi
