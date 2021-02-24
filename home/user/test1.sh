#!/bin/bash
dmesg | grep rtc
lsusb
ifconfig
sudo kill -`pidof lap_monitord` >/dev/null 2>&1
pppd call gprs > /dev/null  & 
