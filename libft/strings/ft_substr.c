
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	length_s;

	length_s = ft_strlen(s);
	if (start >= length_s)
		return (ft_strdup(""));
	if (len > (length_s - start))
		len = length_s - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}
