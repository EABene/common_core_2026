
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	main(void)
{
	char x[100] = "Bullfrog";
	char *y = "NEW STRING MAN";
	char a[100] = "Bullfrog";
	char *b = "NEW STRING MAN";



	ft_strlcpy(x, y, 0);
	strlcpy(a, b, 0);

	printf("%s | %s\n", x, a);
}
