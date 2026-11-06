
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	dup = NULL;
	i = 0;
	while (s1[i])
		i++;
	dup = malloc(i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(void)
{
	char *x = "Hello my guy";
	char *y;

	y = ft_strdup(x);
	printf("%s", y);
	free(y);
}
