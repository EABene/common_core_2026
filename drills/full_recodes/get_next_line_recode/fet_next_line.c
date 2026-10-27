/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fet_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:10:37 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/27 21:15:07 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	// ungültige Eingabe -> NULL
	// Lese und an stash anhängen, solange kein \n gekommen is
	// und read noch etwas liefert != 0 = kein Dateiende
	// stash leer? nichts mehr da -> NULL
	// line = alles bis incl. \n (oder bis zum Ende)
	// stash = nur noch der Rest danach
	// return line
}
