
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	main(void)
{
	printf("%d\n", ft_isalpha('Z'));
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('F'));
	printf("%d\n", ft_isalpha('t'));
	printf("%d\n", ft_isalpha('%'));
	printf("%d\n", ft_isalpha('\n'));
}
