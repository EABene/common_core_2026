/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:53:36 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/12 11:54:37 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
void	ft_putchar(const char c);
void	ft_putstr(const char *str);
void	ft_putnbr(int n);


#endif
