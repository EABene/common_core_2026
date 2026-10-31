/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:53:36 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/12 11:54:37 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_strlen(const char *s);
int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_putnbr(long n);
int	ft_putnbr_base(unsigned long n, char *base);
int	ft_putptr(void *ptr);

#endif
