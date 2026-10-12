
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int n)
{
	char	temp;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * - 1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		temp = nb & 10 + '0';
		write(1, &temp, 1);
	}
	else if (nb < 10)
	{
		temp = nb + '0';
		write(1, &temp, 1);
	}
}
