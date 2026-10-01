
#include "libft.h"

static int	count_digits(long n)
{
	int	size;

	size = 1;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	n2;
	int		size;

	n2 = n;
	if (n2 < 0)
		n2 = -n2;
	size = count_digits(n2);
	if (n < 0)
		size++;
	res = malloc(size + 1);
	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	while (size >= 1)
	{
		size--;
		res[size] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
