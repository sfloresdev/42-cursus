def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))

    def count_days(current_day):
        if (current_day > days):
            return
        print(f"Day {current_day}")
        count_days(days + 1)
    count_days(1)
    print("Harvest time!")
