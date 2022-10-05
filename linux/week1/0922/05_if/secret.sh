#!/bin/bash

arg1=$1
arg2=$2

if [ $arg1 == "KFC" ] && [ $arg2 == 1234 ] ;then
  echo "i love my eyes" > kfc.txt
  clear
  cat kfc.txt
  sleep 1
  clear
  echo "keep secret, BYE"
  rm kfc.txt
fi
