
#include "get_next_line.h"

// TODO: make this function work, by using ft_strlen and ft_strjoin
char	*ft_buffer(char	*piece)
{
	static char	*buffer;

	buffer = ft_strjoin(buffer, piece);
	return (buffer);
}

int	main(void)
{
	char	*res;

	ft_buffer("Hell");
	ft_buffer("o my");
	ft_buffer(" fri");
	ft_buffer("end!");
	res = ft_buffer(" Texas Bullhorns");
	printf("%s\n", res);
	free(res);
}
