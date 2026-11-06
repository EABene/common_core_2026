
#include <stdio.h>

void	set_5(int *x)
{
	*x = 5;
}

int	main(void)
{
	int x = 3;
	int	y = 9;
	int z = 0;

	set_5(&x);
	set_5(&y);
	set_5(&z);
	printf("%i %i %i \n", x, y, z);
}
