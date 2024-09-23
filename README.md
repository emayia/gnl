# get_next_line (gnl)

## Description

`get_next_line` is a project aimed at reading a line from a file descriptor, one line at a time. This project was developed as part of École 42’s curriculum to practice memory management and dynamic allocation in C. The `get_next_line` function can handle multiple file descriptors and return each line read until the end of the file.

## Features

- The function `get_next_line` reads from a file descriptor and returns a line ending with a newline character `\n`.
- It can manage multiple file descriptors simultaneously using static variables.
- Returns `NULL` when reaching the end of a file or upon an error.
- Handles large files, different buffer sizes, and ensures memory is properly freed after usage.

## Compilation and Usage

You can compile the library using the provided `Makefile`. To generate the necessary object files, simply run:

```bash
make
```

## Project Structure

- `get_next_line.c`: Main function for reading from a file descriptor.
- `get_next_line_utils.c`: Utility functions used in the get_next_line implementation.
- `get_next_line_bonus.c`: Supports multiple file descriptors at the same time (bonus).
- `get_next_line_utils_bonus.c`: Utility functions for the bonus implementation.
- `get_next_line.h`: Header file containing function prototypes and includes.
- `Makefile`: Used for compiling both the regular and bonus parts of the project.

## How to Use

Include the header file in your project:
```c
#include "get_next_line.h"
```

Compile with your program by linking the necessary object files or a static library:
```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c my_program.c -o my_program
```

For the bonus part (multiple file descriptor support), you can compile like this:
```bash
gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c my_program.c -o my_program
```

## Author

Project developed by [Emin A.](https://github.com/emayia) as part of the École 42 curriculum.