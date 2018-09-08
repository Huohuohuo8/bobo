#!/bin/bash

function changeName(){
    echo $1
    sed -i "s/vos_memset_safe/memset_s/g" $1
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
dir=./uk_test
echo $dir
travFolder $dir
