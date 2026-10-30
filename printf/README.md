*This project has been created as part of the 42 curriculum by bsandler.*

# ft_printf

## Description
A reimplementation of `printf`, built as the library `libftprintf.a`.

```c
int	ft_printf(const char *format, ...);
```
Supported conversions: `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`.
Returns the number of characters printed. Output goes directly through `write`, without buffering.

## Instructions
- `git clone` the Repository
- `make` - builds `libftprintf.a`
- Include the header:
```c
#include "ft_printf.h"
```
- Link the library:
```bash
cc main.c libftprintf.a
```
Makefile rules: `all`, `clean`, `fclean`, `re`.

## Algorithm and data structure
`ft_printf` iterates through the format string once. Plain characters are written
directly to stdout. When a `%` is detected, the next character (the conversion) is
passed to the static function `ft_convert`, which reads the next argument with
`va_arg` and calls the matching helper from `ft_printf_text.c` and `ft_printf_nbrs.c`.

The only data needed is an index into the format string, a `va_list` for the
arguments and an `int` counter for the return value, so no struct is used.

Design choices:
- `va_list` is passed to `ft_convert` by address, so the one read position in
  `ft_printf` advances. Passing it by value is not portable.
- `ft_putchar` and `ft_putstr` are kept separate: `%c` must also print `'\0'`,
  which a string function would treat as the end of the string.
- One `putnbr(long)` handles `%d %i %u`; one `putnbr_base` handles `%x %X %p`.
- Every helper function returns the number of characters written, which sums up to the return value.
- Edge cases follow Linux/glibc, e.g. a NULL pointer prints `(nil)`.
- Libft is not used: the helpers were rewritten to return the number of
  characters printed, which the libft versions do not.

## Resources
- `man 3 printf`, `man 3 stdarg`
- cppreference.com - "Variadic Functions"
- Own code from the Piscine and libft (`putnbr`, `putstr`, `strlen`), adapted to return character counts (int)

### Use of AI
AI was used as a tutor to explain `stdarg` and `va_list`, as well as the Markdown syntax. 
Additionally it was used to review my code and to generate test programs.
No generated code was used in the submission.
