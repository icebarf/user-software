# PKG Scripts

These are some scripts for installation of properietary packages that aren't directly available in my distributions' repositories.

Relevant desktop entries have been provided for each package in-case that the user is on a desktop environment.

## Visual Studio Code

This script installs Microsoft's Visual Studio Code text editor in the user's directory.

Usage: 
```sh
# In a terminal
$ code
```

Dependencies:

```md
- wget
- tar
```

**Desktop Entry**

If you wish to have a desktop launcher for Visual Studio Code then edit the provided `'Visual Studio Code.desktop'` entry.

Change the `/home/ice` part of the `Exec` and `Icon` variables to your home directory.

Then place the desktop entry in a directory relevant to your desktop environment or launcher program.

**Shell Variable**

```sh
export PATH=$HOME/.local/bin:$PATH
```

Place above line in your shell's rc file so that you are able to execute
`code` without specifying the full path everytime in the terminal.


*Cheers,*

*Happy Hacking!*
