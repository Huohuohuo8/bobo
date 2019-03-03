#!/bin/bash


#bash

function changeName(){
    echo $1
    sed -i "s/old/new/g" $1
}

function travFolder(){ 
    echo "travFolder"
    flist=`ls $1`
    cd $1
    for f in $flist
    do
        if test -d $f
        then
            travFolder $f
        else
            changeName $f
        fi

    done
    cd ../ 
}


#read dir
dir=./test
echo $dir
travFolder $dir
