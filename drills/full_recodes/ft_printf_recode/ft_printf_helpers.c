
#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbr(long n)
{
	char	c;
	int		count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = n *-1;
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

	len = ft_strlen(base);
	count = 0;
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
	if (ptr == NULL)
		return (ft_putstr("0x0"));
	count += ft_putstr("0x");
	count += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
