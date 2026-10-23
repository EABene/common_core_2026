
def ft_count_harvest_iterative():
    max_days = int(input("Days until harvest: "))
    count = 1
    while count <= max_days:
        print(f"Day {count}")
        count += 1
    print("Harvest time!")
