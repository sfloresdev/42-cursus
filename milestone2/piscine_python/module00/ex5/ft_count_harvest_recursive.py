def ft_count_harvest_recursive(day: int, days: int):
    if days is None:
        days = int(input("Days until harvest: "))
    if day > days:
        return
    print(f"Day {day}")
    ft_count_harvest_recursive(day + 1, days)
