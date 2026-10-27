
#include <stdio.h>
#include <stddef.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(void)
{
	char	*x = "";
	char	*y = "Hallo";
	printf("%d | %d ", ft_strncmp(x, y, 7), strncmp(x, y, 7));
}
