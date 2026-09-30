
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dupe;
	size_t	size;

	size = ft_strlen(s1) + 1;
	dupe = malloc(size * sizeof(char));
	if (dupe == NULL)
		return (NULL);
	ft_memcpy(dupe, s1, size);
	return (dupe);
}
