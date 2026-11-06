# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_harvest_total.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 19:04:58 by bsandler          #+#    #+#              #
#    Updated: 2026/11/06 19:05:13 by bsandler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_harvest_total():
    x = int(input("Day 1 harvest: "))
    y = int(input("Day 2 harvest: "))
    z = int(input("Day 3 harvest: "))
    print(f"Total harvest: {x + y + z}")
