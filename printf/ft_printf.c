/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:54:55 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/12 11:55:13 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

// has to handle the following conversions: cspiuxX%
// DONE -> %c %s %d %i %%
// TO-DO -> %p %u %x %X
// so basically it is about putnbr BASE and different versions of that

static int ft_convert(char sign, va_list *args)
{
	if (sign == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (sign == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (sign == 'd' || sign == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (sign == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%') + ft_putchar(sign));

}

int	ft_printf(const char* format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
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
	return (count);
}

int	main(void)
{
	int	r1 = ft_printf("%cx%d|%s|\n", 'A', -42, "Word");
	int	r2 = printf("%cx%d|%s|\n", 'A', -42, "Word");
	printf("ft: %d, orig: %d\n", r1, r2);
}
