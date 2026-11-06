
#include <stdio.h>
#include <stdarg.h>

int	print_ints(int count, ...)
{
	va_list	args;
	int		sum;
	int		i;

	va_start(args, count);
	sum = 0;
	i = 0;
	while (i < count)
	{
		sum = sum + va_arg(args, int);
		i++;
	}
	va_end(args);
	return (sum);
}

int	main(void)
{
	int sum = print_ints(5, 8, 5, 7, 1, 4);
	printf("%d\n", sum);
	return (0);
}
