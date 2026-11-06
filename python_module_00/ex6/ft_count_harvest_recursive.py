# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_recursive.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 19:06:43 by bsandler          #+#    #+#              #
#    Updated: 2026/11/06 19:06:59 by bsandler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_count_harvest_recursive():
    def count(day: int, max_days: int):
        if day > max_days:
            print("Harvest time!")
            return
        print(f"Day {day}")
        count(day + 1, max_days)
    max_days = int(input("Days until harvest: "))
    count(1, max_days)
