# c-lab

C projects, bottom-up. Each one teaches the layer below the last. Plain
Makefiles, no cmake — you should be able to read every line of the build.

## Projects

| # | Project | What it teaches |
|---|---------|-----------------|
| 1 | `wordcount` — file stats CLI | stdio, malloc, file I/O |
| 2 | `unit-convert` — conversions + tests | functions, arrays, strings |
| 3 | `student-db` — linked list persisted to file | pointers, structs, malloc/free |
| 4 | `mini-shell` — fork/exec/pipes | processes, syscalls |

Ship them in order. Project 3 is where C actually clicks.

## How to run

Each project has its own directory with a Makefile:

    cd wordcount
    make
    ./build/wordcount < file.txt

Run with sanitizers while developing:

    make clean && make CFLAGS="-g -fsanitize=address,undefined"

## Toolchain (this machine)

    gcc 16.2.1
    make 4.4.1

## Rules

- `-Wall -Wextra -Werror` from day one.
- No memory leaks: `valgrind ./build/<bin>` (or ASan) must be clean.
- If it segfaults, do not commit.
