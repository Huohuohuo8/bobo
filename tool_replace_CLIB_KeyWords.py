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
            for line in lines:
                for oldstrEach in oldstr:
                    if oldstrEach in line:
                        print line
                        line = line.replace(oldstrEach, newstr[oldstr.index(oldstrEach)])
                f_w.write(line)
        f.close()
        f_w.close()
    elif os.path.isdir(dir):
        for s in os.listdir(dir):
            newDir = os.path.join(dir, s)
            replaceFileKeywords(newDir,oldstr,newstr)
    return

dirpath = raw_input("pls input file or dir to process\n")
#dirpath = "D:/Code_Code_Code\WorkAssitor/testSample.c"
oldstr = ["SEF", "OK" , "FAIL"]
newstr = ["SEFLIB", "OKLIB" , "FAILLIB"]
replaceFileKeywords(dirpath, oldstr, newstr)
print("\ndone successfully!\n")
