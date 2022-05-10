# Visual Studio Code
                                                           This script installs Microsoft's Visual Studio Code text editor in the user's directory.
                                                           Usage:                                                     ```sh
$ chmod +x visual-studio-code.sh
$ ./visual-studio-code.sh
# Specify a some other install dir for Visual studio
$ ./visual-studio-code.sh $HOME/Applications
```

Dependencies:
```md
- wget
- tar
```
                                                           **Desktop Entry**                                                                                                     If you wish to have a desktop launcher for Visual Studio Code then edit the provided `'Visual Studio Code.desktop'` en
try.
Change the `/home/ice` part of the `Exec` and `Icon` variab
les to your home directory.
Then place the desktop entry in a directory relevant to you
r desktop environment or launcher program.

**Shell Variable**

```sh
export PATH=$HOME/.local/bin:$PATH
```

Place above line in your shell's rc file so that you are ab
le to execute
`code` without specifying the full path everytime in the te
rminal.


*Cheers,*

*Happy Hacking!*
