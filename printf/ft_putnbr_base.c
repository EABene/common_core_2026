
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	char			temp;
	int				count;
	unsigned long	len;

	count = 0;
	len = ft_strlen(base);
	if (n >= len)
	{
		count += ft_putnbr_base(n / len, base);
		temp = base[n % len];
		count += write(1, &temp, 1);
	}
	else if (n < len)
	{
		temp = base[n];
		write(1, &temp, 1);
		count++;
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
