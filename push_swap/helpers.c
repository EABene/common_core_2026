
#include "push_swap.h"

void	ft_puts(const char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		is_negative;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	is_negative = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (is_negative == 1)
		result = result * -1;
	return ((int)result);
}

void	*ft_calloc(size_t count, size_t size)
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
