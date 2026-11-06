
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dupe;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1);
	dupe = malloc(size * sizeof(char) + 1);
	if (dupe == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dupe[i] = s1[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

int	main(void)
{
	char	*x = "West Texas Bullfrog";
	char	*y;

	y = ft_strdup(x);
	printf("%s\n", y);
	free(y);
}
