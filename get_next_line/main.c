
#include <unistd.h>
#include <fcntl.h>

static char BUFFER[4];

int	main(int argc, char **argv)
{
	int	fd;
	int	bytes;

	bytes = 5;
	(void) argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while (bytes != 0)
	{
		write(1, "[", 1);
		write(1, &BUFFER, 4);
		write(1, "]", 1);
		bytes = read(fd, BUFFER, 5);
	}

	close(fd);
	return (0);
}

/*
	Ein main, das eine Datei öffnet und in einer Schleife read mit
	BUFFER_SIZE=4 aufruft. Jeden Block gibst du in Klammern aus, z. B.
	[Hall][o\nWe].... Dann siehst du mit eigenen Augen, wie die Zeilen
	auseinandergerissen werden.
	Danach den static-Zähler oben selbst nachbauen und mehrmals aufrufen.*/
