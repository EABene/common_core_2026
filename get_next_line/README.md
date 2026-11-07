*This project has been created as part of the 42 curriculum by bsandler.*

# get_next_line

## Description

`char *get_next_line(int fd)` returns one line at a time from a file descriptor. Each call returns the next line, including the terminating `\n`, or `NULL` if there is nothing left to read or an error occurs. It works with regular files and standard input, with any `BUFFER_SIZE`.

The goal of the project is to learn how to keep state between function calls with a `static` variable, and how to manage dynamic memory without leaks.

## Instructions

Compile the two source files together with your own `main`:

```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

`-D BUFFER_SIZE=n` is optional (default: 10). Every returned line must be freed by the caller.

## Algorithm

A `static char *stash` holds text that was already read but not yet returned. Each call:

1. **`read_to_stash`**: reads `BUFFER_SIZE` bytes at a time and appends them to the stash, until the stash contains a `\n` or the end of the file is reached.
2. **`get_line`**: copies the stash up to and including the first `\n`. This is the returned line.
3. **`get_rest`**: keeps only what comes after the `\n` as the new stash and frees the old one.

**Justification:**
- `read` returns blocks, not lines. A block can already contain the start of the next line. These bytes cannot be read again, so they must survive until the next call, hence a `static` variable is used.
- Reading only until the next `\n` follows the subject's rule to read as little as possible, and works for stdin and files of any size.
- The returned line belongs to the caller; the stash belongs to `get_next_line`. Separate allocations keep this ownership clear, and on any error everything allocated is freed before returning `NULL`.
- The read buffer is allocated with `malloc`, because a large `BUFFER_SIZE` on the stack would cause a stack overflow.

## Resources

- `man 2 read`, `man 3 malloc`
- cppreference: Storage duration (static)

**Usage of AI:** AI was used as a tutor to explain concepts (`read()`, `static` variables, memory ownership), to review my code and point out bugs and to generate test programs. 
All project code was written by me.
