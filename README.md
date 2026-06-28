# my_ls

An experimental, hand-written reimplementation of the Unix `ls` command in C.
It has no external dependencies and is written directly against the raw POSIX
APIs: `opendir`/`readdir` for directory traversal, `stat` for file metadata,
and `getpwuid`/`getgrgid` for user and group names.

It is a small tool for learning and experimentation, not a replacement for the
system `ls`.

## Build

```
make
```

This builds the `my_ls` binary with `cc -Wall -Wextra -Werror -std=c11`. The
build is warning-free on both clang and gcc.

Other targets:

- `make clean` removes object files.
- `make fclean` removes object files and the binary.
- `make re` rebuilds from scratch.

## Usage

```
./my_ls [-l] [-r] [path ...]
```

Flags:

- `-l` long format: permissions, link count, user, group, size, modification
  date, and name.
- `-r` reverse alphabetical order.

With no path, it lists the current directory. One or more paths can be passed.

### Examples

Plain listing:

```
$ ./my_ls
alpha.txt
beta.log
docs
```

Reverse order:

```
$ ./my_ls -r
docs
beta.log
alpha.txt
```

Long format:

```
$ ./my_ls -l
drwxr-xr-x 5 user wheel  160 Jun 28 18:20 .
drwxrwxrwx 204 root wheel 6528 Jun 28 18:20 ..
-rw-r--r-- 1 user wheel    1 Jun 28 18:20 alpha.txt
-rw-r--r-- 1 user wheel    5 Jun 28 18:20 beta.log
drwxr-xr-x 2 user wheel   64 Jun 28 18:20 docs
```

## Memory safety

The tool builds warning-free under `-Wall -Wextra -Werror` and is verified
clean under AddressSanitizer, UndefinedBehaviorSanitizer, and Valgrind across
these inputs: no arguments, a single directory, multiple paths, `-l`, `-r`,
`-l` on a directory with subdirectories, and a nonexistent path.

One honest caveat: on a fatal input error, such as a path that does not exist,
the program prints the error and exits without unwinding. Buffers that were
live at that point show as "still reachable" in Valgrind, not as leaked, since
they are still referenced from the stack and the OS reclaims them on exit.

## What this does not implement

This is an experimental reimplementation, not a drop-in `ls`. Compared to the
real `ls` it does not:

- Support most flags. Only `-l` and `-r` are implemented. There is no `-a`,
  `-R`, `-t`, `-h`, combined short flags like `-lr`, or long options.
- Hide dotfiles consistently. The plain and `-r` listings skip names that start
  with a dot, but `-l` shows them, including `.` and `..`.
- Sort or align output exactly like `ls`. Column widths and ordering are
  approximate.
- Handle absolute paths in `-l`. The long-format path handling assumes paths
  relative to the current directory.
- Color output, follow symlinks specially, or report total block counts.
