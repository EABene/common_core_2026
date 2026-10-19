
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

static int	g_ko = 0;

#define TEST(...)                                                    \
	do {                                                             \
		int r1, r2;                                                  \
		write(1, "ft:   [", 7);                                      \
		r1 = ft_printf(__VA_ARGS__);                                 \
		write(1, "]\norig: [", 9);                                   \
		fflush(stdout);                                              \
		r2 = printf(__VA_ARGS__);                                    \
		fflush(stdout);                                              \
		printf("]\n%s ret ft=%d orig=%d\n\n",                        \
			(r1 == r2) ? "OK " : "KO!", r1, r2);                     \
		fflush(stdout);                                              \
		if (r1 != r2)                                                \
			g_ko++;                                                  \
	} while (0)

int	main(void)
{
	char	*null_str = NULL;
	void	*null_ptr = NULL;
	int		x = 42;

	/* %c */
	TEST("%c", 'A');
	TEST("%c%c%c", 'a', '\t', 'z');
	TEST("%c", '0');
	TEST("%c", 0);

	/* %s */
	TEST("%s", "This is a string");
	TEST("%s", "");
	TEST("%s", null_str);
	TEST("%s|%s", "a", "bc");

	/* %d / %i */
	TEST("%d", 0);
	TEST("%d %d", -1, 1);
	TEST("%d", INT_MAX);
	TEST("%d", INT_MIN);
	TEST("%i %i", 42, -42);

	/* %u */
	TEST("%u", 0u);
	TEST("%u", UINT_MAX);
	TEST("%u", (unsigned int)-1);

	/* %x / %X */
	TEST("%x %X", 0u, 0u);
	TEST("%x %X", 255u, 255u);
	TEST("%x %X", UINT_MAX, UINT_MAX);
	TEST("%x", 0xDEADBEEFu);

	/* %p */
	TEST("%p", (void *)&x);
	TEST("%p", (void *)1);
	TEST("%p", (void *)ULONG_MAX);
	TEST("%p", null_ptr);

	/* %% */
	TEST("%%");
	TEST("100%% sicher");
	TEST("%%%c%%", 'x');

	/* gemischt */
	TEST("nur Text\n");
	TEST("%c|%s|%d|%i|%u|%x|%X|%p|%%", 'B', "str", -7, 7, 7u, 171u, 171u, (void *)&x);

	printf("==> %d KO\n", g_ko);
	return (0);
}
