
def ft_count_harvest_recursive():
    def count(day: int, max_days: int):
        if day > max_days:
            print("Harvest time!")
            return
        print(f"Day {day}")
        count(day + 1, max_days)
    max_days = int(input("Days until harvest: "))
    count(1, max_days)
