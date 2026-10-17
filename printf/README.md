*This project has been created as part of the 42 curriculum by bsandler.*

# ft_printf

## Description
A reimplementation of `printf()`, built as the library `libftprintf.a`.

```c
int	ft_printf(const char *format, ...);
```
Supported conversions: `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`.
Returns the number of characters printed. Output goes directly through `write(2)`, without buffering.

## Instructions
git clone the Repository
make - builds libftprintf.a
Include the header:
```c
#include "ft_printf.h"
```
Link the library:
```bash
cc main.c libftprintf.a
```
Makefile rules: `all`, `clean`, `fclean`, `re`.

## Algorithm and data structure
explanation on how the code executes TODO

## Resources
- `man 3 printf`, `man 3 stdarg`
- cppreference.com - "Variadic Functions"
- Own code from the Piscine and libft (`putnbr`, `putstr`, `strlen`), adapted to return character counts (int)

### Use of AI
just general questions. No generated code.
Mostly help in understanding stdarg and its usage, only asking questions.
No generated code. TODO
