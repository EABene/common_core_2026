
#include <stdio.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	const char	*s;

	i = 0;
	d = dst;
	s = src;
	if (dst == s || len == 0)
		return (dst);
	if (d > s)
	{
		while (len-- > 0)
		{
//			len--;
			d[len] = s[len];
		}
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

int	main(void)
{
	char buf[20] = "123456789";
	ft_memmove(buf + 2, buf, 5);   /* d > s:  erwartet "121234589" */
	printf("%s\n", buf);

	char buf2[20] = "123456789";
	ft_memmove(buf2, buf2 + 2, 5); /* d < s:  erwartet "345676789" */
	printf("%s\n", buf2);
}
