#!/usr/bin/env python3

"""
Data transformation over time
"""


class Plant:
    def __init__(self, name: str, height: int, plant_age: int) -> None:
        self.name = name
        self.height = height
        self.plant_age = plant_age

    def grow(self, size: int = 0.8):
        self.height += size

    def age(self, days: int = 1):
        self.plant_age += days

    def get_info(self):
        print(f"{self.name}: {round(self.height, 1)}cm", end="")
        print(f", {self.plant_age} days old",)


p = Plant("Rose", 25, 30)

initial_height: int = p.height

for i in range(1, 8):
    print(f"=== Day {i} ===")
    p.age()
    p.grow()
    p.get_info()

total_growth: int = p.height - initial_height
print(f"Growth this week: {round(total_growth, 1)}")
