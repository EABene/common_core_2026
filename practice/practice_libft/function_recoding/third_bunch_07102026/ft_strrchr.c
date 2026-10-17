
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char *str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (i > 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

int	main(void)
{
	char	*x= "South East Asian Bullfrogs man";

	printf("%s\n", ft_strrchr(x, 'A'));
	printf("%s\n", ft_strrchr(x, 'S'));
	printf("%s\n", ft_strrchr(x, ' '));
	printf("%s\n", ft_strrchr(x, 0));
	printf("%s\n", ft_strrchr(x, 'x'));
}
