
#include <stdio.h>
#include <stdarg.h>

void simple_print(int n, ...)
{
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++)
		printf("%d ", va_args(args, int));
	printf("\n");
	va_end(args);
}

int	main(void)
{
	simple_print(1, 2, 3);
	simple_print(1, 2, 3, 4, 5);

	return (0);
}
