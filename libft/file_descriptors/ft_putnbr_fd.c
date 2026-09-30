
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	temp;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		temp = nb % 10 + '0';
		write(fd, &temp, 1);
	}
	else if (nb < 10)
	{
		temp = nb % 10 + '0';
		write(fd, &temp, 1);
	}
}
