
#include <stdio.h>

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{

	printf("%s\n", ft_strnstr("Hello World", "World", 11));   /* World */
	printf("%s\n", ft_strnstr("Hello World", "World", 8));    /* (null) */
	printf("%s\n", ft_strnstr("Hello", "", 5));               /* Hello */
}
