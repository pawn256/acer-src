#!/bin/bash

plymouthd --debug --debug-file=/tmp/plymouth-debug-out 
plymouth --show-splash
for((I=0;I<10;I++)); do
sleep 1
plymouth --update=event$I
done;
plymouth --quit
