
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			bytes;

	if (size != 0 && count > (size_t)-1 / size)
		return (NULL);
	bytes = count * size;
	if (bytes == 0)
		bytes = 1;
	ptr = malloc(bytes);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < bytes)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
