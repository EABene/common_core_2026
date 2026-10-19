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

static int	ft_convert(char sign, va_list *args)
{
	if (sign == '%')
		return (ft_putchar('%'));
	else if (sign == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (sign == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (sign == 'd' || sign == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (sign == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int)));
	else if (sign == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789abcdef"));
	else if (sign == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	else if (sign == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	return (ft_putchar('%') + ft_putchar(sign));
}

int	ft_printf(const char *format, ...)
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
