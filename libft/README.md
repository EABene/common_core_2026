*This project has been created as part of the 42 curriculum by bsandler.*

# Libft

## Description

Libft is a C library (libft.a) that re-implements selected libc functions and adds utility functions for strings, output and linked lists. It is the first project of the 42 Common Core curriculum and serves as a base library for future 42 projects.

The library consists of three parts:

- Part 1: re-implementations of libc functions with identical prototypes and behaviour, prefixed with ft_
- Part 2: additional string manipulation and file descriptor functions that are not available in libc in this form
- Part 3: functions for creating and manipulating linked lists

## Instructions

Build rules:

- make: compiles all sources and creates libft.a
- make clean: removes the object files
- make fclean: removes the object files and libft.a
- make re: runs fclean, then make

All sources are compiled with cc -Wall -Wextra -Werror, and the archive is created with ar rcs. Object files depend on their source file and on libft.h, so only changed files are recompiled and no unnecessary relinking occurs.

Usage: include libft.h in your source file and link against the library, for example with cc -Wall -Wextra -Werror main.c libft.a.

## Library overview

### Part 1

- Character classification: ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint
- Character conversion: ft_toupper, ft_tolower
- Memory: ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp
- Strings: ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr
- Conversion: ft_atoi
- Memory allocation: ft_calloc, ft_strdup

### Part 2

- ft_substr returns a substring of s starting at index start with a maximum length of len
- ft_strjoin returns a new string made of s1 followed by s2
- ft_strtrim returns a copy of s1 with the characters from set removed from the beginning and the end
- ft_split returns a NULL-terminated array of the substrings of s, split at the delimiter c
- ft_itoa returns the string representation of an int, including negative numbers
- ft_strmapi returns a new string built by applying the function f to each character
- ft_striteri applies the function f to each character of a string in place
- ft_putchar_fd, ft_putstr_fd, ft_putendl_fd and ft_putnbr_fd write a character, a string, a string followed by a newline, or an integer to the file descriptor fd

All functions that allocate memory return NULL if the allocation fails.

### Part 3

Each node of a list is a t_list with two members: content, a void pointer to data of any type, and next, a pointer to the following node, which is NULL for the last node.

- ft_lstnew allocates a new node with the given content and next set to NULL
- ft_lstadd_front inserts a node at the beginning of the list
- ft_lstadd_back appends a node at the end of the list
- ft_lstsize returns the number of nodes in the list
- ft_lstlast returns the last node of the list
- ft_lstdelone frees the content of a node with del, then frees the node itself
- ft_lstclear frees every node from the given one onward and sets the list pointer to NULL
- ft_lstiter applies the function f to the content of each node
- ft_lstmap returns a new list built by applying the function f to the content of each node, and frees everything if an allocation fails

## Resources

- Manual pages of the original libc functions, opened in the terminal with man 3 followed by the function name
- Websites:
  - stackoverflow.com
  - w3schools.com
  - geeksforgeeks.org
  - scribd.com
  - makefiletutorial.com
  - gnu.org/software/make/manual/

#### Use of AI

In line with the AI guidelines of the subject, AI (Claude by Anthropic) was used as a learning aid, not as a substitute for writing code:

- Explanations: answering questions that came up while working, for example about technical terms, pointers, size_t, linked lists, function pointers and Makefiles.
- Code review: functions I had written myself were reviewed, aiming for hints where improvements would be possible.
- Testing: generating test programs that compare the functions against libc, and running them.

- All code in this repository was typed and developed by me, and I chose my own approach on how to make it work. 
