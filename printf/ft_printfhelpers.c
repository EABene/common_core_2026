
#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	if (str == NULL)
		return (1);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_putnbr(int n)
{
	char	temp;
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = nb * - 1;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		temp = nb % 10 + '0';
		count += write(1, &temp, 1);
	}
	else if (nb < 10)
	{
		temp = nb + '0';
		write(1, &temp, 1);
		count++;
	}
	return (count);
}

//TODO
int	ft_putnbr_base(unsigned long n, char *base)
{ // redo it, so it can handle base
	char	temp;
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = nb * - 1;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		temp = nb % 10 + '0';
		count += write(1, &temp, 1);
	}
	else if (nb < 10)
	{
		temp = nb + '0';
		write(1, &temp, 1);
		count++;
	}
	return (count);
}
