
#include "ft_printf.h"

int	main(void)
{
	void	*ptr;

	ptr = NULL;
	ft_printf("%c\n", 80);
	ft_printf("%%\n", 80);
	ft_printf("assdfasdfasdf%sasdfdffwfd\n", "String");
	ft_printf("%d\n", -2147483647);
	ft_printf("%i\n", 7483647);
	ft_printf("%u\n%", 4294967295);
	ft_printf("%x\n", 97295);
	ft_printf("%X\n", 429496);
	ft_printf("%p\n", "Pointer");
	ft_printf("%p\n", ptr);
}
