
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", ft_toupper('4'));
	printf("%c\n", ft_toupper('&'));
	printf("%c\n", ft_toupper('h'));
	printf("%c\n", ft_toupper('z'));
	printf("%c\n", ft_toupper('w'));
}
