# Portacle

Portacle is preconfigured IDE for Lisp programming. It ships with Emacs, sbcl and quicklisp.

It also installs magit, company and slime emacs packages.

Here is the official website [https://portacle.github.io/](https://portacle.github.io/)

## Usage

```sh
$ sh -c ./portacle.sh
```

The above script will install portacle in the current user's `.local` directory.

It will setup necessary symlinks for running of this program and export an environment variable for that instance. To be able to execute `portacle` from the command line, put the following line in your shellrc file - `.bashrc`, `.zshrc`

```sh
export PATH="$HOME/.local/bin:$PATH"
```

