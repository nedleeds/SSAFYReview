#!/bin/bash

var=$1

if [ $var = "dd" ] ;then
  date
elif [ $var = "sl" ] ;then
  apt install -y $var
  run $var 
  #apt purge -y $var
fi
