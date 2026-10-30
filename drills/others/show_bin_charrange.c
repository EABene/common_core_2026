
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnbr_base(long nb, char *base)
{
	char	tmp;
	int		base_len;
	int		count;
	
	count = 0;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (-1);
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb >= base_len)
	{
		count += ft_putnbr_base(nb / base_len, base);
		tmp = base[nb % base_len];
		count += write(1, &tmp, 1);
	}
	else if (nb < base_len)
	{
		tmp = base[nb % base_len];
		count += write(1, &tmp, 1);
	}
	return (count);
}

int	main(void)
{
	char *base;
	int	i;

	i = -1;
	base = "01";
	while (i++ < 255)
	{
		ft_putnbr_base(i, base);
		write(1, "\n", 1);
	}
}
