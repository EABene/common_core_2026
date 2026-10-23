/*
** Testprogramm fuer get_next_line (wird NICHT abgegeben)
**
** Kompilieren (aus dem Projektordner, in dem get_next_line.c liegt):
**   cc -Wall -Wextra -Werror -g -fsanitize=address -D BUFFER_SIZE=42 \
**      get_next_line.c get_next_line_utils.c gnl_tests/main.c -I . -o gnl_test
**
** Modi:
**   ./gnl_test datei.txt          Zeilen sichtbar ausgeben: \n wird als "\n" angezeigt
**   ./gnl_test                    dasselbe, aber von stdin (Tastatur, Ctrl+D beendet)
**   ./gnl_test --raw datei.txt    Zeilen 1:1 ausgeben (zum Vergleich mit dem Original)
**   ./gnl_test --raw              dasselbe von stdin
**   ./gnl_test --badfd            ungueltige fds testen (muss jeweils NULL liefern)
**   ./gnl_test --two a.txt b.txt  zwei Dateien abwechselnd lesen (nur Info, das
**                                 ist Bonus-Verhalten und im Mandatory nicht gefordert)
*/

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

static void	print_visible(int nr, char *line)
{
	int	i;

	printf("%3d: \"", nr);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			printf("\\n");
		else if (line[i] == '\t')
			printf("\\t");
		else
			printf("%c", line[i]);
		i++;
	}
	printf("\"\n");
}

static int	open_or_stdin(char *path)
{
	int	fd;

	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		perror(path);
	return (fd);
}

static int	mode_visible(char *path)
{
	int		fd;
	int		nr;
	char	*line;

	fd = open_or_stdin(path);
	if (fd == -1)
		return (1);
	nr = 0;
	line = get_next_line(fd);
	while (line)
	{
		print_visible(++nr, line);
		free(line);
		line = get_next_line(fd);
	}
	printf("--- Ende: %d Zeile(n), danach NULL\n", nr);
	line = get_next_line(fd);
	if (line)
	{
		printf("FEHLER: weiterer Aufruf nach dem Ende liefert nicht NULL\n");
		free(line);
	}
	else
		printf("OK: weiterer Aufruf nach dem Ende liefert wieder NULL\n");
	if (fd > 0)
		close(fd);
	return (0);
}

static int	mode_raw(char *path)
{
	int		fd;
	char	*line;

	fd = open_or_stdin(path);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		write(1, line, strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	if (fd > 0)
		close(fd);
	return (0);
}

static int	mode_badfd(void)
{
	int		fails;
	char	*line;
	int		fds[3];
	int		i;

	fds[0] = -1;
	fds[1] = 42;
	fds[2] = 1000;
	fails = 0;
	i = 0;
	while (i < 3)
	{
		line = get_next_line(fds[i]);
		if (line)
		{
			printf("FEHLER: get_next_line(%d) liefert nicht NULL\n", fds[i]);
			free(line);
			fails++;
		}
		else
			printf("OK: get_next_line(%d) liefert NULL\n", fds[i]);
		i++;
	}
	return (fails != 0);
}

static int	mode_two(char *a, char *b)
{
	int		fd_a;
	int		fd_b;
	char	*la;
	char	*lb;

	fd_a = open_or_stdin(a);
	fd_b = open_or_stdin(b);
	if (fd_a == -1 || fd_b == -1)
		return (1);
	la = get_next_line(fd_a);
	lb = get_next_line(fd_b);
	while (la || lb)
	{
		if (la)
			print_visible(fd_a, la);
		if (lb)
			print_visible(fd_b, lb);
		free(la);
		free(lb);
		la = get_next_line(fd_a);
		lb = get_next_line(fd_b);
	}
	close(fd_a);
	close(fd_b);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc >= 2 && strcmp(argv[1], "--badfd") == 0)
		return (mode_badfd());
	if (argc >= 2 && strcmp(argv[1], "--raw") == 0)
		return (mode_raw(argc >= 3 ? argv[2] : NULL));
	if (argc >= 4 && strcmp(argv[1], "--two") == 0)
		return (mode_two(argv[2], argv[3]));
	return (mode_visible(argc >= 2 ? argv[1] : NULL));
}
