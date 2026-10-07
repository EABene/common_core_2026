
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char d;
	unsigned char *ptr;

	d = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (len--)
	{
		ptr[len] = d;
	}
	return (b);
}

int	main(void)
{
	char x[100] = "Hello, this is a string where the Bullfrog is mentioned";

	ft_memset(x, 'K', 16);
	printf("%s\n", x);
}
