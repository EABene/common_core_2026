
#include <stdlib.h>

void	*calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	bytes;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > (size_t)-1 / size)
		return (NULL);
	bytes = count * size;
	ptr = malloc(bytes);
	if (ptr == NULL)
		return (NULL);
	while (bytes--)
		ptr[bytes] = 0;
	return (ptr);
}
