
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dupe;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;

	dupe = malloc(size * sizeof(char));
	if (dupe == NULL)
		return (NULL);
	dupe[0] = '\0';
	ft_strlcat(dupe, s1, size);
	ft_strlcat(dupe, s2, size);
	return (dupe);
}
