#!/usr/bin/python
# -*- coding:utf-8 -*-

import subprocess
import os,sys
import binascii
import time

f=open('vid.psp','rb')
d=f.read()
f.close()
DEVNULL=open(os.devnull,'wb')
for i in range(1000):
    d2=d[0:i]+'\xff'+d[i+1:]
    f=open('psp'+str(i)+'.psp','wb')
    f.write(d2)
    f.close()
    p=subprocess.Popen(['vlc','psp'+str(i)+'.psp'],stdout=DEVNULL,stderr=DEVNULL)
    time.sleep(2)
    p.terminate()
    p.wait()
    if p.returncode != 0:
        print "offset num:%d, returncode:%d"%(i,p.returncode)
