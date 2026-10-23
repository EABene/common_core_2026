
def ft_recursion(max_days, day):
    if day != max_days:
        print(f"Day {day}")
        day += 1
        ft_recursion(max_days, day)
    else:
        print(f"Day {day}")
        print("Harvest time!")

def ft_count_harvest_recursive():
    max_days = int(input("Days until harvest: "))
    day = 1
    ft_recursion(max_days, day)
