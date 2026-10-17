
#include <stddef.h>
#include <stdio.h>
#include <bsd/string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));

	i = 0;
	size = size - 1;
	while (src[i] != '\0' && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	main(void)
{
	char	*x = "";
	char	y[800];
	char	*z = "";
	char	a[800];

	ft_strlcpy(y, x, 17);
	strlcpy(a, z, 17);
	printf("%s | %s\n", y, a);
}
