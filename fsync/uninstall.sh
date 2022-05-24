#!/bin/sh

sudo rm $HOME/.local/bin/fsync
make clean

printf "\e[32mUninstalled fsync user program\n\e[m"
