
#include <stdio.h>

void	add_five(int *n)
{
	*n = *n + 5;
}

int	main(void)
{
	int x;

	x = 2;
	add_five(&x);
	printf("%i ", x);
}
