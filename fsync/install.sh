#!/bin/sh

make all
make install

sudo cp man/fsync.1 /usr/share/man/man1/fsync.1

if command -v gzip; then
    sudo gzip /usr/share/man/man1/fsync.1
else
    printf "command: gzip not found\n"
fi

printf "\e[32mInstalled fsync !!\n\e[m"
