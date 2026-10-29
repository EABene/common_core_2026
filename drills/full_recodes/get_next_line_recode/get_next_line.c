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

char	*ft_get_line(char *stash)
{

}

char	*ft_get_rest(char *stash)
{

}

char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes;
	
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buffer[bytes] = '\0';
		// continue here!
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
