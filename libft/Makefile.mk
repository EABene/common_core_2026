# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/03 15:44:51 by bsandler          #+#    #+#              #
#    Updated: 2026/10/03 15:50:11 by bsandler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = 



$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c %.o %.c

all:

clean:
	rm -f $(OBJ)

fclean:

re:




.PHONY = ?

// ar to create library
// 
