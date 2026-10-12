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


#include "header.h"

// has to handle the following conversions: cspiuxX%


int	ft_printf(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	switch (format)
	{
		case ("%%"):
			ft_putchar('%');
		case ("%c"):
			ft_putchar(va_arg);
	}
}

int	main(void)
{
	ft_printf("%c", 'A');
}
