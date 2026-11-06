
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(void)
{
	printf("%zu\n", ft_strlen("East"));
	printf("%zu\n", ft_strlen("Texas"));
	printf("%zu\n", ft_strlen(""));
	printf("%zu\n", ft_strlen("Bullfrogs are so majestic"));
}
