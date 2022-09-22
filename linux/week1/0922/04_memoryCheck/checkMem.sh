#!/bin/bash

echo "meminfo 1: $(cat /proc/meminfo | grep MemTotal)"
echo "meminfo 2: $(cat /proc/meminfo | grep MemFree)"


