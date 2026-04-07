#!/usr/bin/env python3

import sys


def get_inventory() -> None:

    if len(sys.argv) < 2:
        print("Not arguments recieved: <item_name>:<quantity>...")
        return

    inventory: dict[str, int] = {}

    for arg in sys.argv[1:]:
        if ":" not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue

        parts = arg.split(':')
        item = parts[0]
        if item in inventory:
            print(f"Redundant item '{item}' - discarding")
            continue

        try:
            number = int(parts[1])
            inventory[item] = number
        except ValueError as e:
            print(f"Quantity error for {item}: {e}")

    if not inventory:
        return

    print(f"Got inventory: {inventory}")
    item_list = list(inventory.keys())
    print(f"Item list: {item_list}")

    total_quantity = sum(inventory.values())
    number_items = len(sys.argv) - 1
    print(f"Total quantity of the {number_items} items: {total_quantity}")

    most_abundant = item_list[0]
    least_abundant = item_list[0]

    for item, number in inventory.items():
        percentage = (number / total_quantity) * 100
        print(f"Item {item} represents {round(percentage, 1)}%")

        if number > inventory[most_abundant]:
            most_abundant = item
        if number < inventory[least_abundant]:
            least_abundant = item

    print(f"Item most abundant: {most_abundant}", end="")
    print(f" with quantity {inventory[most_abundant]}")
    print(f"Item least abundant. {least_abundant}", end="")
    print(f" with quantity {inventory[least_abundant]}")

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    get_inventory()
