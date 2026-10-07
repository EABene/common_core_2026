
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char *str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (NULL);
}

int	main(void)
{
	char *x = "East Texas Bullfrog is nice";

	printf("%s\n", ft_strchr(x, 's'));
	printf("%s\n", ft_strchr(x, 'i'));
	printf("%s\n", ft_strchr(x, 0));
	printf("%s\n", ft_strchr(x, '&'));
}
