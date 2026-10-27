
#include <unistd.h>
#include <string.h>

static void	swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

static void	bubble_sort(char **wordlist)
{
	int 	i;
	int 	j;
//	char	*temp;

	i = 1;
	while (wordlist[i])
	{
		j = 1;
		while (wordlist[j + 1] != NULL)
		{
			if (strcmp(wordlist[j], wordlist [j + 1]) > 0)
			{
				swap(&wordlist[j], &wordlist[j + 1]);
				/*
				temp = wordlist[j];
				wordlist[j] = wordlist[j + 1];
				wordlist[j + 1] = temp;
				*/
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i; // counter *argv
	int	j; // counter argv

	if (argc < 2)
	{
		write(1, "Provide args!", 13);
		return (1);
	}
	bubble_sort(argv);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write (1, &argv[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
