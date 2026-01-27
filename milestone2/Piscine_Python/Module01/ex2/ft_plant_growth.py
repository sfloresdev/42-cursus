#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: int, plant_age: int) -> None:
        self.name = name
        self.height = height
        self.plant_age = plant_age
        self.week_day = 0

    def grow(self):
        if (self.week_day >= 7):
            self.week_day = 0
        self.height += 1
        self.week_day += 1

    def age(self):
        if (self.week_day >= 7):
            self.week_day = 0
        self.plant_age += 1
        self.week_day += 1

    def get_info(self):
        print(f"{self.name}: {self.height}cm, {self.plant_age} days old")
        if (self.week_day >= 7):
            print(f"Growth this week +{self.week_day}cm")


p = Plant("Rose", 25, 30)

for i in range(1, 7 + 1):
    print(f"=== Day {i} ===")
    p.get_info()
    p.age()
    p.grow()
