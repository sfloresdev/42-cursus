#!/usr/bin/env python3
"""
Introduccion al concepto de herencia con Python
"""


class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def get_info(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


class Flower(Plant):
    def __init__(self, name: str, height: int, age: int, color: str):
        super().__init__(name, height, age)
        self.color = color

    def bloom(self):
        print(f"{self.name} is blooming beautifully")

    def info(self):
        print(f"{self.name} (Flower): {self.height}cm, ", end="")
        print(f"{self.age} days old, {self.color} color")


class Tree(Plant):
    def __init__(self, name: str, height: int, age: int, trunk_diameter: int):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        square_meters: int = self.height * self.trunk_diameter
        print(f"{self.name} provides {square_meters} of shade")

    def info(self) -> None:
        print(f"{self.name} (Tree): {self.height}cm, ", end="")
        print(f"{self.age} days old, {self.trunk_diameter}cm diameter")


class Vegetable(Plant):
    def __init__(self, name: str, height: int, age: int,
                 harvest_season: str, nutritional_value: str):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def info(self):
        print(f"{self.name} (Vegetable): {self.height}cm, ", end="")
        print(f"{self.age} days old, {self.harvest_season} harvest")
        print(f"{self.name} is rich in {self.nutritional_value}")


def plant_types():
    print("=== Garden Plant Types ===\n")
    f = Flower("Rose", 25, 30, "red")
    t = Tree("Oak", 500, 1825, 50)
    v = Vegetable("Tomato", 80, 90, "summer", "vitamin C")
    f.info()
    f.bloom()
    print("")
    t.info()
    t.produce_shade()
    print("")
    v.info()


plant_types()
