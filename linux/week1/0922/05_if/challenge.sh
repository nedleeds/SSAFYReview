#!/bin/bash

var=$1

if [ $var -gt 10 ] && [ $var -lt 30 ] ;then
  echo "good"
elif [ $var -gt 40 ] && [ $var -lt 50 ] ;then
  echo "omg"
else
  echo "wow"
fi
