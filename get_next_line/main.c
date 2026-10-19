#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

int	main(int argc, char **argv)
{
	char	buffer[BUFFER_SIZE];
	int		fd;
	int		bytes;

	if (argc != 2)
	{
		write(1, "Invalid amount of arguments.\n", 29);
		return (0);
	}
	bytes = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			write(1, "[", 1);
			write(1, buffer, bytes);
			write(1, "]", 1);
		}
	}
	close(fd);
	return (0);
}
