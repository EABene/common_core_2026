
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	printf("%sZ", line);
	line = get_next_line(fd);
	printf("%sZ", line);
	line = get_next_line(fd);
	printf("%s", line);
	/*
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	*/
	close(fd);
	return (0);
}
