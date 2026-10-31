
#include "get_next_line.h"

static char	*get_rest(char *stash)
{
	char	*rest;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0' || stash[i + 1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	else
	{
		rest = ft_strjoin(NULL, &stash[i + 1]);
		free(stash);
		return (rest);
	}
}

static char	*get_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash[0])
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	ft_strlcat(line, stash, i + 1);
	return (line);
}

static char	*read_to_stash(char *stash, int fd)
{
	char	*buffer;
	char	*tmp;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(stash), NULL);
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
		if (stash == NULL)
			return (free(buffer), NULL);
	}
	return (free(buffer), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(stash, fd);
	if (stash == NULL)
		return (NULL);
	line = get_line(stash);
	stash = get_rest(stash);
	return (line);
}
