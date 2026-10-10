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

Listing of all functions:

Part 1:
- Character classification: ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii,
  ft_isprint
- Character conversion: ft_toupper, ft_tolower
- Memory: ft_memset, ft_bzero, ft_memcmp, ft_memmove, ft_memchr, ft_memcmp
- Strings: ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strncmp,
  ft_strnstr

Part 2:
- ft_substr returns a substring of s start with a maximum length of len
- ft_strjoin returns a concatenated string of s1 and s2
- ft_strtrim returns a copy of s1 with characters from set removed from
  the front and the end
- ft_split returns a NULL-terminated array of substrings ofs, split at c
- ft_itoa returns the string representation of an int
- ft_strmapi returns a new string built by applying function f to each character
ft_striteri applies function f to each character in place
- ft_putchar_fd, ft_putstr_fd, ft_putendl_fd and ft_putnbr_fd write a character,
  a string, a string with a newline or an interger to the file descriptor fd

Part 3:
Each node is a t_list with two members: void * content and void * next which points
to the following node or NULL for the last one.

- ft_lstnew allocates a node with content and next set to NULL
- ftlstadd_front inserts a node at the head of the list
- ft_lstadd_back appends a node at the end of the list
- ft_lstsize returns the number of nodes
- ft_lstlast returns the last node
- ft_lstdelone frees a node's content with del, then frees the node
- ft_lstclear frees all nodes from the given one onward and sets the list pointer
  to NULL
- ft_lstiter applies function f to the content of each node
- ft_lstmap returns a new list built from function f, aaplied to each node's
  content and frees everything on allocation failure

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
In line with the subjects AI guidelines, AI (Claude by Anthropic) was used as a
learning aid, not as a ssubstitute for writing code.

- Code review: self-written functions were reviewed for bugs, edge cases and
  memory errors, all fixes were applied manually.
- Testing: generating test programs that compare the functions against libc,
  and running them with AdressSanitizer and Valgrind 


