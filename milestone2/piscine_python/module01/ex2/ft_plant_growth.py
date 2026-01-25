#!/usr/bin/env python3

"""
Data transformation over time
"""


class Plant:
    def __init__(self, name: str, height: int, plant_age: int) -> None:
        self.name = name
        self.height = height
        self.plant_age = plant_age

    def grow(self, size: int = 1):
        self.height += size

    def age(self, days: int = 1):
        self.plant_age += days

    def get_info(self):
        print(f"{self.name}: {self.height}cm, {self.plant_age} days old")


p = Plant("Rose", 25, 30)

initial_height: int = p.plant_age

for i in range(1, 8):
    print(f"=== Day {i} ===")
    p.get_info()
    p.age()
    p.grow()

total_growth: int = p.plant_age - initial_height
print(f"Growth this week: {total_growth}")
