
#include <stdlib.h>
#include <stdio.h>

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
	size_t	len;
	char	*dupe;
	size_t	i;

	len = ft_strlen(s1);
	dupe = malloc((len + 1) * sizeof(char));
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
	char	*x = "East Texas or Austin";
	char	*y;

	y = ft_strdup(x);
	printf("%s\n", y);
	free(y);
}
