
#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
