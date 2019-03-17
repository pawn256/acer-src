#!/usr/bin/python
# -*- coding:utf-8 -*-


import os
import random
import struct
import time
import subprocess

DEVNULL = open(os.devnull,'wb')
for i in range(1000):
    f=open('m3u8.m3u8','wb')
    for j in range(50):
        f.write(struct.pack('<B',int(random.random()*1000)%255))
    f.write('m3u8')
    f.close()
    
    #if os.system('vlc m3u8.m3u8 >/dev/null 2>&1 &') != 0:
    #    print "Error: %d"%(i)
    #    break
    time.sleep(2)
    p=subprocess.Popen(['vlc','m3u8.m3u8'],stdout=DEVNULL,stderr=DEVNULL)
    time.sleep(2)
    p.terminate()
    p.wait()
    if p.returncode != 0:
        print "offset num:%d, returncode:%d"%(i,p.returncode)
        break
