*This project has been created as part of the 42 curriculum by bsandler.*

# Libft

**DESCRIPTION**
Libft is a C library (libft.a) that re-implements selected libc functions
and adds utility functions for strings, output and linked lists.
It is the first project of the Common Core curriculum of 42 and is supposed
to serve as a base library for future 42 projects.

The library consists of three parts:
    - Part 1: re-implementation of libc functions with identical prototypes
    and behaviours, but prefixed with ft_
    - Part 2: additional string manipulation and file descriptor functions
    not available in libc in this form.
    - Part 3: functions creating and manipulating linked lists.

**INSTRUCTIONS**
Build:
make: compiles all sources and creates libft.a
make clean: removes object files
make fclean: removes object files and libft.a
make re: runs fclean, then make

Compilation happens with cc -Wall -Wextra -Werror.
The archive is created with ar rcs.
Object files depend on their source file and on libft.h, so only changed
files are recompiled and no unecessary relinking occurs. 

Usage:
Include libft.h in your source file and link against the library.
For example with cc -Wall -Wextra -Werror main.c libft.a.

**RESOURCES**
- Manual Pages for each function also available in libc.
  called in the terminal with: man 3 <function_name>
- Websites as listed:
  - stackoverflow.com
  - w3schools.com
  - geeksforgeeks.org
  - scribd.com 
  - makefiletutorial.com
  - gnu.org/software/make/manual/

Use of AI:
Claude (Anthropic) was used for 


