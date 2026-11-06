
#include <stdio.h>

void	set_to_42_copy(int n)
{
	n = 42;		// changes only copy
}

void	set_to_42(int *n)
{
	*n = 42;	// changes original at adress
}

int	main(void)
{
	int	x;

	x = 5;
	set_to_42_copy(x);	// passes value 5
	printf("nach copy:   %d\n", x);

	set_to_42(&x);           // passes adress of x
	printf("nach Adresse: %d\n", x);
	return (0);
}
