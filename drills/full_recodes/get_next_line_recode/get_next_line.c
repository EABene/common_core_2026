/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:23:30 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/27 21:23:38 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *stash)
{
	size_t		i;
	char	*buffer;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	buffer = malloc(i + 1);
	if (!buffer)
		return (NULL);
	line[0] = '\0';
	ft_strlcat(line, stash, i + 1);
	return (buffer);
}

char	*ft_get_rest(char *stash)
{
	size_t	i;
	char	*rest;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0') || stash [i + 1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	rest = ft_strjoin(NULL, &stash[i + 1];
	free(stash);
	return (rest);	
}

char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
		if (!stash)
			return (free(buffer), NULL);
		free(buffer);
		return (stash);
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_get_rest(stash);
	return (line);
}
