
#ifndef FT_PRINTF_H
# define LIBFT_H

# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_strlen(char *str);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long n);
int	ft_putnbr_base(unsigned long n, char *base);
int	ft_putptr(void *ptr);

#endif
