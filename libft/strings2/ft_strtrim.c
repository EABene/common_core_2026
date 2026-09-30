
#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (in_set(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && in_set(s1[j - 1], set))
		j--;
	return (ft_substr(s1, i, j - i));
}
