#!	/bin/bash

gcc -c ./blue.c
gcc -c ./pink.c
gcc -c ./main.c

gcc ./main.o ./blue.o ./pink.o -o bluepink
rm ./*.o
