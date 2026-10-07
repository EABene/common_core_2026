
#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	int		bytes;
	size_t len_dst;

	i = 0;
	len_dst = ft_strlen(dst);
	bytes = dstsize - ft_strlen(dst) - 1;
	if (bytes < 1)
		return (len_dst);
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (j < (size_t)bytes && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + len_dst);
}

int	main(void)
{
	char x[500] = "Hakuna ";
	char *y = "Matata";
	char a[500] = "Hakuna ";
	char *b = "Matata";
	int	n1;
	int n2;
	n1 = ft_strlcat(x, y, 1);
	n2 = strlcat(a, b, 1);

	printf("%s | %s", x, a);
	printf("%d | %d", n1, n2);
}
