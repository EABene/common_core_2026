
#include <stdarg.h>
#include <stdio.h>

void	variadic_func(int count, ...)
{
	va_list args;

	va_start(args, count);
	while(count-- > 0)
	{
		printf("%s\n", va_arg(args, char *));
	}
	va_end(args);
}

int	main(void)
{
	variadic_func(4, "Houston", "Dallas", "Austin", "El Paso");

}
