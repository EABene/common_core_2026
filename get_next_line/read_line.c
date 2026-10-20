
#include "get_next_line.h"

static char	*ft_get_line(char *stash)
{
	size_t	len;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	len = 0;
	while (stash[len] != '\n' && stash[len] != '\0')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	ft_strlcat(line, stash, len + 1);
	return (line);
}
static char	*ft_get_rest(char *stash)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0' || stash[i + 1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	rest = ft_strjoin(NULL, &stash[i + 1]);
	free(stash);
	return (rest);
}

int	main(int argc, char *argv)
{
	if (argc != 2)
		return (1);


}
