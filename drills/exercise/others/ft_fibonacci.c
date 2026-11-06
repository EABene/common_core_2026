
#include <stdio.h>

size_t	ft_fibonacci(int n) // returns fibonacci number at index n
{
	if (n == 1)
		return (0);
	else if (n == 2)
		return (1);
	else
		return (ft_fibonacci(n - 1) + ft_fibonacci(n - 2));
}

void	ft_print_fib(int lim)
{
	int	i;

	i = 0;
	while (i++ < lim)
		printf("%zu ", ft_fibonacci(i));
}

int	main(void)
{
	ft_print_fib(40);
}
// 0 1 1 2 3 5 8 13 21
