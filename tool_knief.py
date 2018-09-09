#!/usr/bin/python
import os
import sys

def replaceFileKeywords(dir, oldstr, newstr):
    newDir = dir
    if os.path.isfile(dir):
        with open(dir,"r") as f:
            f.seek(0,0)
            lines = f.readlines()
        with open(dir,"w") as f_w:
            f_w.seek(0,0)
            for line in lines:
                if oldstr in line:
                    line = line.replace(oldstr, newstr)
                f_w.write(line)
        f.close()
        f_w.close()
    elif os.path.isdir(dir):
        for s in os.listdir(dir):
            newDir = os.path.join(dir, s)
            replaceFileKeywords(newDir,oldstr,newstr)
    return

dirpath = raw_input("pls input the dir path to be replaced,eg: C:/dir\n")
print("the dirpath you input is: ",dirpath)
oldstr = raw_input("\npls input the old str to be replaced\n")
print("the old str to be replaced you input is: ",oldstr)
newstr = raw_input("\npls input the new str\n")
print("the new str you input is: ",newstr)
replaceFileKeywords(dirpath, oldstr, newstr)
print("\ndone successfully!\n")