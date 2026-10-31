
// get_line
// get_rest





char	*read_to_stash(char *stash, int fd)
{
	char	*buffer;
	char	*temp;
	int		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	

}

char	*get_next_line(int fd)
{
	static char	*stash;

	stash = read_to_stash(fd);
}
