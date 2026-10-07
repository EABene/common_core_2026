
#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int	main(void)
{
	char	a;
	char	b;
	char	c;

	a = 'h';
	b = 'O';
	c = 'L';

	printf("%c %c %c | %c %c %c", ft_tolower(a), ft_tolower(b), ft_tolower(c), tolower(a), tolower(b), tolower(c));
}
