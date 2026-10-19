
#include "ft_printf.h"
#include <stdarg.h>

int	ft_convert(char sign, va_list *args)
{
	if (sign == '%')
		return (ft_putchar('%'));
	if (sign == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (sign == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (sign == 'd' || sign == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	return (ft_putchar('%') + ft_putchar(sign));
}

int	ft_printf_two(const char *format, ...)
{
	va_list args;
	int	i;
	int	count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format [i + 1])
		{
			ft_convert(format[i + 1], &args);
			i += 2;
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	a = 'A';
	char	b = 'B';
	char	*str = "String";
	int	i = -4538;
	ft_printf_two("%s %cx %c%% %i\n", str, a, b, i);
}
