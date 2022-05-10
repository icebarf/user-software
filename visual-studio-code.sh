#!/bin/bash

/usr/bin/wget -c https://az764295.vo.msecnd.net/stable/57fd6d0195bb9b9d1b49f6da5db789060795de47/code-stable-x64-1651667500.tar.gz

printf "Extracting Visual Studio Code...\n"
tar -xvf code-stable-x64-*.tar.gz > /dev/null
printf "Done!\n"

printf "Creating Directories for local install.\n"
mkdir -p $HOME/.local
mkdir -p $HOME/.local/programs
mkdir -p $HOME/.local/bin

printf "\nMoving Visual Studio to install directory\n"
mv ./VSCode-linux-x64 $HOME/.local/programs

export PATH=$HOME/.local/bin:$PATH

printf "\nCreating symlink\n"
ln -s $HOME/.local/programs/VSCode-linux-x64/bin/code $HOME/.local/bin
printf "\n\nLocal install completed.\n"
printf "\n\nIt is recommended that you put the following line in your shell rc file\nIt adds the ~/.local/bin directory to \$PATH\n"
printf "\n\texport PATH=\$HOME/.local/bin:\$PATH\n\n"
printf "Happy Hacking!\n"
