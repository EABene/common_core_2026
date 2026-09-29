
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	d;
	size_t	i;

	ptr = (char *) s;
	d = (char) c;
	i = 0;
	while (ptr[i] != '\0')
		i++;
	while (i != 0)
	{
		if (ptr[i] == d)
			return (&ptr[i]);
		i--;
	}
	if (d == ptr[i])
		return (&ptr[i]);
	return (NULL);
}
