
#include <stdio.h>

int	ft_isprime(int n)
{
	int	i;

	if (n == 0 || n == 1)
		return (0);
	if (n == 2 || n == 3)
		return (1);
	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_nextprime(int n)
{
	n++;
	while (ft_isprime(n) == 0)
		n++;
	return (n);
}

void	ft_printprimes(void)
{
	int	i;

	i = 0;
	while (i <= 300)
	{
		if (ft_isprime(i) == 1)
			printf("%i ", i);
		i++;
	}
}

int	main(void)
{
	ft_printprimes();
}
