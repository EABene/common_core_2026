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
// %csd fertig, piuxX left

int	ft_printf(const char* format, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				ft_putchar(va_arg(args, int));
				i = i + 2;
			}
			if (format[i + 1] == '%')
			{
				ft_putchar('%');
				i = i + 2;
			}
			if (format[i + 1] == 's')
			{
				ft_putstr(va_arg(args, char *));
				i = i + 2;
			}
			if (format[i + 1] == 'd')
			{
				ft_putnbr(va_arg(args, int));
				i = i + 2;
			}
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (1);
}

int	main(void)
{
	char a = 'A';
	char b = 'B';
	char *str = "really beautiful";

	ft_printf("Initials: %c. %c., 100%%, that is %s.\n", a, b, str);
	ft_printf("Numbers are %d, %d, %d, %d and %d", 1, 2, 3, 4, 5);
	return (0);
}
