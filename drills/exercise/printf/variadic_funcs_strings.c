
#include <unistd.h>
#include <stdarg.h>
/* --- Tools of stdarg ---
 * va_list args; deklariert den Lesezeiger
 * va_start(args, count); stellt Zeiger direkt auf erstes namenlose Element
 * va_arg(args, int); liest aktuelles Element als "int" und rückt eins weiter
 *						Datatype muss selbst richtig übergeben werden
 * va_end(args); Aufräumen am Ende. Pflicht wie free zu malloc */

void	print_strings(int count, ...)
{
	va_list	args;
	char	*str;
	int		i;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		str = va_arg(args, char *);
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
		i++;
	}
	va_end(args);
}

int	main(void)
{
	print_strings(4, "Dallas", "Houston", "Austin", "El Paso");
	return (0);
}

