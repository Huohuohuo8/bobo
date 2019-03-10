#!/usr/bin/python
import os
import sys
import re

def replaceFileKeywords(dir, oldstr, newstr):
    newDir = dir
    if os.path.isfile(dir):
        with open(dir,"r") as f:
            f.seek(0,0)
            lines = f.readlines()
        with open(dir,"w") as f_w:
            f_w.seek(0,0)
            rp_and_skip = 0
            for line in lines:
                if rp_and_skip == 1:
                    rp_and_skip = 0
                    continue
                matchObj = re.match('(.*)VOS(.*)\)$', line, re.M|re.I)
                if matchObj:
                    print line
                    line = line.replace(")",") {")
                    rp_and_skip = 1
                f_w.write(line)
        f.close()
        f_w.close()
    elif os.path.isdir(dir):
        for s in os.listdir(dir):
            newDir = os.path.join(dir, s)
            replaceFileKeywords(newDir,oldstr,newstr)
    return


dirpath = "D:/Code_Code_Code\WorkAssitor/testSample.c"
oldstr = ""
newstr = ""
replaceFileKeywords(dirpath, oldstr, newstr)
print("\ndone successfully!\n")
