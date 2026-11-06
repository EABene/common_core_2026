
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_putnbr_base(unsigned long n, char *base);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return(i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	if (i == dstsize)
		return (i + ft_strlen(src));
	j = 0;
	while (i + j < dstsize - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dupe;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dupe = malloc(size * sizeof(char));
	if (dupe == NULL)
		return (NULL);
	dupe[0] = '\0';
	ft_strlcat(dupe, s1, size);
	ft_strlcat(dupe, s2, size);
	return (dupe);
}

char	*ft_putnbr_base(unsigned long n, char *base)
{
	char	c[2];
	char	*rest;
	char	*res;
	size_t	len;

	len = ft_strlen(base);
	c[0] = base[n % len];
	c[1] = '\0';
	if (n < len)
		return (ft_strjoin("", c));
	rest = ft_putnbr_base(n / len, base);
	if (rest == NULL)
		return (NULL);
	res = ft_strjoin(rest, c);
	free(rest);
	return (res);
}

int	main(int argc, char **argv)
{
	size_t	i;
	char	*alphabet;
	char	*s;
//	int		len;

	(void) argc;
	(void) argv;
	i = 0;

	alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (1)
	{
		s = ft_putnbr_base(i, alphabet);
		if (ft_strncmp(s, "XYZ", 3) == 0)
		{
			i++;
			free(s);
			break ;
		}
		free(s);
		i++;
	}
	printf("%zu\n", i);
}
