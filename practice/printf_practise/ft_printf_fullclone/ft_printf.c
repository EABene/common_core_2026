
#include "ft_printf.h"
#include <stdio.h>

int	ft_convert(char c, va_list *args)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	return (ft_putchar('%') + ft_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_convert(format[i + 1], &args);
			i += 2;
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return(count);
}
