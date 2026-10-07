
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(void)
{
	char *x = "Bullifrog";
	char *y = "Bullzfrog";
	printf("%d | %d\n", ft_strncmp(x, y, 5), strncmp(x, y, 5));
}
