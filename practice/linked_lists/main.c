
/*
** Spielwiese fuer die Listenfunktionen.
**
** Kompilieren (im Ordner mit libft.h und deinen ft_lst*.c):
**   cc -Wall -Wextra -Werror -g playground.c ft_lst*.c && ./a.out
**
** Auf Leaks pruefen (Mac):   leaks --atExit -- ./a.out
** Auf Leaks pruefen (Linux): valgrind --leak-check=full ./a.out
**
** Ueberall, wo EXPERIMENT steht, kannst du etwas aendern und schauen,
** was passiert.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

/* ---------- Hilfsfunktionen zum Anzeigen ---------- */

static void	section(const char *title)
{
	printf("\n========== %s ==========\n", title);
}

/* Gibt die Liste als Kette aus: [Adresse "Inhalt"] -> ... -> NULL */
static void	print_list(const char *name, t_list *lst)
{
	printf("%-9s = %p\n", name, (void *)lst);
	printf("            ");
	while (lst != NULL)
	{
		printf("[%p \"%s\"] -> ", (void *)lst, (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

/* Zeigt, was lst, *lst, **lst usw. bei einem Doppelzeiger sind */
static void	explain_double_pointer(t_list **lst)
{
	printf("lst              = %p   (Adresse der Variable im main)\n",
		(void *)lst);
	printf("*lst             = %p   (Inhalt dieser Variable = erster Knoten)\n",
		(void *)*lst);
	if (*lst == NULL)
		return ;
	printf("(*lst)->content  = \"%s\"\n", (char *)(*lst)->content);
	printf("(*lst)->next     = %p   (zweiter Knoten)\n",
		(void *)(*lst)->next);
	printf("sizeof(**lst)    = %zu Bytes (ein ganzer Knoten)\n", sizeof(**lst));
}

/* ---------- Funktionen fuer del, f und lstiter ---------- */

static int	g_del_calls = 0;

/* Wie free, zaehlt aber mit, wie oft del aufgerufen wurde */
static void	del_counting(void *content)
{
	printf("    del(\"%s\") wird aufgerufen\n", (char *)content);
	g_del_calls++;
	free(content);
}

/* Fuer lstiter: aendert den Inhalt direkt, in Grossbuchstaben */
static void	to_upper_in_place(void *content)
{
	char	*s;

	s = content;
	while (*s)
	{
		*s = toupper((unsigned char)*s);
		s++;
	}
}

/* Fuer lstmap: erzeugt eine NEUE Kopie mit Sternchen drumherum */
static void	*decorate_copy(void *content)
{
	char	*old;
	char	*copy;
	size_t	len;

	old = content;
	len = strlen(old);
	copy = malloc(len + 3);
	if (copy == NULL)
		return (NULL);
	copy[0] = '*';
	memcpy(copy + 1, old, len);
	copy[len + 1] = '*';
	copy[len + 2] = '\0';
	return (copy);
}

/* ---------- Absichtlich falsche Varianten zum Vergleich ---------- */

/* Wie ft_lstadd_front, aber nur mit einfachem Zeiger */
static void	bad_add_front(t_list *lst, t_list *new)
{
	new->next = lst;
	lst = new;
	printf("    innerhalb von bad_add_front zeigt lst auf %p\n", (void *)lst);
}

/* ---------- Hauptprogramm ---------- */

int	main(void)
{
	t_list	*list;
	t_list	*mapped;
	t_list	*node;
	t_list	*middle;

	section("1. ft_lstnew");
	node = ft_lstnew(strdup("Fluss"));
	print_list("node", node);
	printf("node->next ist %s\n", node->next == NULL ? "NULL" : "nicht NULL");

	section("2. ft_lstadd_front");
	list = NULL;
	print_list("list", list);
	ft_lstadd_front(&list, node);
	print_list("list", list);
	ft_lstadd_front(&list, ft_lstnew(strdup("West")));
	print_list("list", list);
	printf("-> Der Anfang hat sich geaendert, list zeigt auf den neuen Knoten.\n");

	section("3. ft_lstadd_back");
	ft_lstadd_back(&list, ft_lstnew(strdup("krebs")));
	ft_lstadd_back(&list, ft_lstnew(strdup("Texas")));
	print_list("list", list);
	printf("-> Der Anfang ist gleich geblieben, nur das Ende ist neu.\n");
	/* EXPERIMENT: Haenge hier noch einen Knoten mit ft_lstadd_front an
	   und schau, an welcher Stelle er landet. */
	ft_lstadd_front(&list, ft_lstnew(strdup("Newnode")));
	print_list("list", list);

	section("4. Doppelzeiger unter der Lupe");
	printf("Im main liegt die Variable list bei %p\n", (void *)&list);
	explain_double_pointer(&list);
	printf("-> lst im Doppelzeiger ist genau &list aus dem main.\n");

	section("5. ft_lstsize und ft_lstlast");
	printf("ft_lstsize(list) = %u\n", ft_lstsize(list));
	printf("ft_lstlast(list) = %p \"%s\"\n", (void *)ft_lstlast(list),
		(char *)ft_lstlast(list)->content);
	printf("ft_lstsize(NULL) = %u\n", ft_lstsize(NULL));
	printf("ft_lstlast(NULL) = %p\n", (void *)ft_lstlast(NULL));
	printf("list zeigt danach immer noch auf %p\n", (void *)list);
	printf("-> Einfacher Zeiger: die Funktionen wandern, der Anfang bleibt.\n");

	section("6. Warum der Doppelzeiger noetig ist");
	node = ft_lstnew(strdup("Neu"));
	printf("Vorher: list = %p\n", (void *)list);
	bad_add_front(list, node);
	printf("Nachher: list = %p   <- unveraendert!\n", (void *)list);
	print_list("list", list);
	printf("-> Der Knoten \"Neu\" ist nicht in der Liste angekommen.\n");
	free(node->content);
	free(node);
	/* EXPERIMENT: Ersetze bad_add_front durch ft_lstadd_front(&list, ...)
	   und vergleiche die Ausgabe. Was passiert, wenn du in deinem
	   ft_lstadd_front die zwei Zeilen vertauschst? */

	section("7. ft_lstiter");
	ft_lstiter(list, to_upper_in_place);
	print_list("list", list);
	printf("-> Gleiche Adressen, aber die Inhalte wurden direkt veraendert.\n");

	section("8. ft_lstmap");
	mapped = ft_lstmap(list, decorate_copy, free);
	print_list("list", list);
	print_list("mapped", mapped);
	printf("-> Neue Knoten, neue Adressen, neue Inhalte. Das Original bleibt.\n");

	section("9. ft_lstdelone: einen Knoten aus der Mitte entfernen");
	middle = list->next;
	printf("Wir entfernen \"%s\" bei %p\n", (char *)middle->content,
		(void *)middle);
	list->next = middle->next;
	printf("Erst umhaengen: der Vorgaenger zeigt jetzt am Knoten vorbei.\n");
	ft_lstdelone(middle, del_counting);
	print_list("list", list);
	printf("-> ft_lstdelone verbindet keine Nachbarn. Das Umhaengen war\n");
	printf("   unsere Aufgabe, bevor wir geloescht haben.\n");
	/* EXPERIMENT: Was wuerde passieren, wenn du ft_lstdelone aufrufst,
	   OHNE vorher list->next umzuhaengen? Probier es mit
	   cc ... -fsanitize=address aus. */

	section("10. ft_lstclear");
	g_del_calls = 0;
	printf("Vorher: list = %p\n", (void *)list);
	ft_lstclear(&list, del_counting);
	printf("Nachher: list = %p, del wurde %d mal aufgerufen\n",
		(void *)list, g_del_calls);
	ft_lstclear(&mapped, free);
	printf("mapped = %p\n", (void *)mapped);
	printf("-> Beide Zeiger sind NULL, aller Speicher ist freigegeben.\n");
	return (0);
}

