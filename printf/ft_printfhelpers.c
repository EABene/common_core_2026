
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

int	ft_putnbr(long n)
{
	char	temp;
	int		count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = n * - 1;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		temp = n % 10 + '0';
		count += write(1, &temp, 1);
	}
	else if (n < 10)
	{
		temp = n + '0';
		write(1, &temp, 1);
		count++;
	}
	return (count);
}
