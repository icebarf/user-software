# fsync

fsync is a syscall provided on POSIX based systems. This program allows you to
perform the syscall on a file through the shell for whatever reason the user wishes to.

For more information on what `fsync` syscall does check the manual pages

```sh
$ man 2 fsync # Linux Programmer's Manual
$ man 3 fsync # POSIX Programmer's Manual
```

## Usage

```sh
$ fsync FILENAME

# Viewing help

$ fsync --help
```

- **View the manpage**

```sh
$ man 1 fsync
```

## Installation

The fsync program can be built and installed in the local user's directory 
with the help of `install.sh` script that is provided with this code.

```sh
$ sh -c ./install.sh
```

## Uninstall

The fsync program can be installed with the uninstall script.

```sh
$ sh -c ./uninstall.sh
```

## Return Values

The binary returns `0` on success otherwise `1` on failure along with an error description.


## Licensing Note

Please note that the `fsync` program here in this repository is distributed
under a different license than the parent Repository.

The parent repository license is not applicable to this folder and you must
agree to the licensing contents of `LICENSE` and the first few lines of 
`fsync.c` which term the license.

> The license also applies to all previous commits on this repository and must
be used under the terms of the LICENSE Specified.
