
def ft_count_harvest_recursive():
    max_days = int(input("Days until harvest: "))
    if max_days < 1:
        print("Harvest time!")
        return
    day = 1

    def ft_recursion(max_days, day):
        if day != max_days:
            print(f"Day {day}")
            day += 1
            ft_recursion(max_days, day)
        else:
            print(f"Day {day}")
            print("Harvest time!")
    ft_recursion(max_days, day)
