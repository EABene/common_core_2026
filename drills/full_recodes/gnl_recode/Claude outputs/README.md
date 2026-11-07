*This project has been created as part of the 42 curriculum by bsandler.*

# get_next_line

## Description

`char *get_next_line(int fd)` is a C function that returns one line at a time from a file descriptor. Each call returns the next line, including the terminating `\n`, or `NULL` if there is nothing left to read or an error occurs. The last line of a file is returned without `\n` if the file does not end with one.

It works with regular files as well as standard input, and with any buffer size set at compile time via `BUFFER_SIZE`.

The main purpose of this project is to learn how to keep state between function calls using a `static` variable, and how to manage dynamically allocated memory across several functions without leaks.

## Instructions

Compile the two source files together with your own program:

```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

`-D BUFFER_SIZE=n` is optional. Without it, the default value defined in `get_next_line.h` (10) is used.

Example usage:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

Every returned line is allocated with `malloc` and must be freed by the caller. To read from standard input, call `get_next_line(0)`.

## Algorithm

### Overview

The function keeps a `static char *stash` that holds text which has already been read from the file descriptor but not yet returned. Each call goes through three steps:

1. **`read_to_stash`**: If the stash does not contain a `\n` yet, read `BUFFER_SIZE` bytes into a temporary buffer, terminate it with `\0` and append it to the stash with `ft_strjoin`. Repeat until the stash contains a `\n` or `read` returns `0` (end of file). If the stash already contains a `\n` from the previous call, nothing is read.
2. **`get_line`**: Copy everything from the start of the stash up to and including the first `\n` (or up to the end, if there is no `\n`) into a new string. This is the line that gets returned.
3. **`get_rest`**: Copy everything after the `\n` into a new string, free the old stash and store the copy as the new stash. If nothing is left, the stash is freed and set to `NULL`.

Example with `BUFFER_SIZE = 4` and a file containing `"Hello\nWorld\n"`:

```
call 1: read "Hell", read "o\nWo"  ->  stash = "Hello\nWo"
        return "Hello\n", stash = "Wo"
call 2: read "rld\n"               ->  stash = "World\n"
        return "World\n", stash = NULL
call 3: read returns 0             ->  return NULL
```

### Justification

- **Why a `static` variable?** `read` does not know about lines. A block can end in the middle of a line or already contain the beginning of the next one. Those extra bytes are already consumed from the file descriptor and cannot be read again (`lseek` is forbidden), so they must survive until the next call. A local variable would be lost when the function returns, and global variables are not allowed. A `static` local variable keeps its value between calls and is only visible inside `get_next_line`.
- **Why read in blocks until a `\n`?** The subject requires reading as little as possible per call instead of loading the whole file. This also makes the function work with standard input and with files of any size, where reading everything up front would be impossible or wasteful.
- **Why copy the line and the rest into new strings?** The returned line belongs to the caller, who frees it. The rest belongs to `get_next_line`. Keeping them in separate allocations makes ownership clear: whatever is returned is the caller's responsibility, whatever stays in the stash is freed by `get_next_line` itself.
- **Why is the buffer allocated with `malloc`?** A local array `char buffer[BUFFER_SIZE]` lives on the stack, which is only a few megabytes in size. With a large `BUFFER_SIZE` such as 10000000, this causes a stack overflow. The heap does not have this limit.
- **Error handling:** On a failed `read` or `malloc`, every allocated block (buffer and stash) is freed before returning `NULL`, so no memory is lost.

### Known limitation

Every append copies the whole stash into a new string. With a very small `BUFFER_SIZE` (for example `1`) and very long lines, this means a lot of copying, so the function becomes slow. It still returns correct results.

## Resources

- `man 2 read`
- `man 3 malloc`, `man 3 free`
- [cppreference: Storage duration (static)](https://en.cppreference.com/w/c/language/storage_duration)

### Usage of AI

AI was used as a tutor throughout the project:

- to explain concepts such as `read()`, file descriptors, `static` variables and memory ownership,
- to review my code and point out bugs and memory leaks,
- to generate test programs and test files,
- to help structure and write this README.

All project code was written by me.
