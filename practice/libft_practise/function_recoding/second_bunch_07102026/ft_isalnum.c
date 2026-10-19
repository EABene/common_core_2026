
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}


int	main(void)
{
	printf("%d\n", ft_isalnum('6'));
	printf("%d\n", ft_isalnum('k'));
	printf("%d\n", ft_isalnum('Q'));
	printf("%d\n", ft_isalnum('&'));
	printf("%d\n", ft_isalnum('\r'));
}
