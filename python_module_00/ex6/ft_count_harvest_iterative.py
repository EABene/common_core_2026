# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_iterative.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 19:06:16 by bsandler          #+#    #+#              #
#    Updated: 2026/11/06 19:06:33 by bsandler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_count_harvest_iterative():
    max_days = int(input("Days until harvest: "))
    count = 1
    while count <= max_days:
        print(f"Day {count}")
        count += 1
    print("Harvest time!")
