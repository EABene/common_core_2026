
#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_length;

	src_length = ft_strlen(src);
	if (dstsize == 0)
		return (src_length);
	i = 0;
	while (i < dstsize - 1 && i < src_length)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_length);
}
