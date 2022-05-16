# fsync

fsync is a syscall provided on POSIX based systems. This program allows you to
perform the syscall on a file through the shell for whatever reason the user wishes to.

For more information on what `fsync` does check the manual pages

```sh
$ man 2 fsync # Linux Programmer's Manual
$ man 3 fsync # POSIX Programmer's Manual
```

## Usage

```sh
$ fsync FILENAME

# Viewing help

$ fsync
```

## Return Values

The binary returns `0` on success otherwise `1` on failure along with an error description.
