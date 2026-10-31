/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:31:13 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/17 11:32:39 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr(long n)
{
	char	c;
	int		count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		c = n % 10 + '0';
		count += write(1, &c, 1);
	}
	else if (n < 10)
	{
		c = n + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	char			c;
	int				count;
	unsigned long	len;

	count = 0;
	len = ft_strlen(base);
	if (n >= len)
	{
		count += ft_putnbr_base(n / len, base);
		c = base[n % len];
		count += write(1, &c, 1);
	}
	else if (n < len)
	{
		c = base[n];
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	}
	return (count);
}
