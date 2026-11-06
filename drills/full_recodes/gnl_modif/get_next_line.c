/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 16:34:00 by bsandler          #+#    #+#             */
/*   Updated: 2026/11/06 16:35:56 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*add_z(char *line)
{
	int		len;
	int		i;
	char	*line_z;
	int		nl;

	i = 0;
	len = ft_strlen(line);
	nl = line[len-1] == '\n' ? 1 : 0;
	if (!len)
		nl = 0;
	line_z = malloc(len + 1 + nl);
	if (!line_z)
		return (NULL);
	while (line[i] != '\0')
	{
		line_z[i] = line[i];
		i++;
	}
	free(line);
	if (nl)
	{
		line_z[len + 1] = '\0';
		line_z[len] = '\n';
		line_z[len-1] = 'Z';
	}
	else
	{
		line_z[len + 1] = '\0';
		line_z[len] = 'Z';
	}
	return (line_z);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*line_z;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(stash, fd);
	if (stash == NULL)
		return (NULL);
	line = get_line(stash);
	line_z = add_z(line);
	stash = get_rest(stash);
	return (line_z);
}
