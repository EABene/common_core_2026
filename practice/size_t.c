
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char x = -72;

	printf("%zu\n", (size_t)-1);
	write(1, &x, 1);

}
