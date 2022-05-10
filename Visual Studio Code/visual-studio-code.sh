#!/bin/bash

URL="https://az764295.vo.msecnd.net/stable/57fd6d0195bb9b9d1b49f6da5db789060795de47/code-stable-x64-1651667500.tar.gz"


if [[ ${#1} > 0 ]]; then
	DESTDIR=$1
	echo $DESTDIR
else
	DESTDIR="$HOME/.local/programs"
	echo $DESTDIR
fi

$(command -v wget) -c $URL

tar -xvf code-stable-x64-*.tar.gz > /dev/null

mkdir -p $HOME/.local
mkdir -p $HOME/.local/programs
mkdir -p $HOME/.local/bin

mv ./VSCode-linux-x64 $DESTDIR/

export PATH=$HOME/.local/bin:$PATH

ln -s $DESTDIR/VSCode-linux-x64/bin/code $HOME/.local/bin

printf "\n\nLocal install completed.\n"

printf "\n\nIt is recommended that you put the following line in your shell rc file\nIt adds the ~/.local/bin directory to \$PATH\n"
printf "\n\texport PATH=\$HOME/.local/bin:\$PATH\n\n"

printf "Happy Hacking!\n"
