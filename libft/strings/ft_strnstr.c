
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;
	
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && needle[j] != '\0' && haystack[i + j] == needle[j])
		{
			j++;
			if (j == needle_len)
				return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}
