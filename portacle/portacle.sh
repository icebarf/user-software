#!/bin/bash

VER="1.4"
TAR="lin-portacle.tar.xz"
PORTACLE="https://github.com/portacle/portacle/releases/download/$VER/$TAR"

USRLOCAL="$HOME/.local"
USRBIN="$HOME/.local/bin"
USRPROG="$HOME/.local/programs"
USRSHARE="$HOME/.local/share"
USRAPPS="$HOME/.local/share/applications"

if command -v wget ; then
    wget -c $PORTACLE
else
	echo "wget not available"
fi

mkdir -p $USRLOCAL
mkdir -p $USRBIN
mkdir -p $USRPROG
mkdir -p $USRSHARE
mkdir -p $USRAPPS

printf "\n\e[32mExtracting xz archive...\e[m\n"
tar -xvf $TAR > /dev/null

mv portacle $USRPROG/
ln -s $USRPROG/portacle/portacle.run $USRBIN/portacle
ln -s $USRPROG/portacle/portacle.desktop $USRAPPS/portacle.desktop

printf "\n\e[1m\e[32mInstall Successful!!\e[m\n"


export PATH=$HOME/.local/bin:$PATH
