*This project has been created as part of the 42 curriculum by bsandler*

# Description
Texthere presenting the project, including it's goal and brief overview.
`char *get_next_line(int fd)`is a function coded in C, that returns one line at a time from a file descriptor. Each call returns the next line, including the terminating `\n`, or `NULL`if there is nothing left to read or an error occurs.
It works with regular files and the standard input. The buffer size can be set by compiling with `-D BUFFER_SIZE=`.
The main purpose of this project is to understand how to keep the state of a variable using the `static`keyword, as well as managing multiple functions and preventing memory leaks.

# Instructions
Texthere info about compilation, installation, and/or execution
Just add the function to your library or program.
When compiling, you can use `-D BUFFER_SIZE=` to manually set the size of the buffer.
`BUFFER_SIZE`is a macro in the header file of the program, value set to 10 by default.

# Algorithm
The function reads `BUFFER_SIZE`bytes from the `fd` into variable `stash`.
If a `\n` is found or the end of the file is reached, the reading stops.
`stash`will now be examined and split up if necessary:
- `get_line` gets the line that will be returned, including the newline `\n`.
- `get_rest` gets everything after the newline, this remainder will be set to `stash`to make sure it won't be lost for the next (potential) iteration.
Inbetween, the function frees variables when necessary, checks for `NULL`returns inside and allocates memory dinamically using `ft_strjoin` and `malloc`.

# Resources
Texthere documentation, articles, tutorials
- man 2 read
- man 3 malloc
- online reports about static variables
- ...

# Usage of AI
AI used as search engine and explanatory tool to find resources about static variables.
