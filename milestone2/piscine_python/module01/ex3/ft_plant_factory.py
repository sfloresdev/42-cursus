#!/usr/bin/env python3

"""
Creacion de plantas de manera automatica
Optimizacion del proceso de creacion e inicializacion
"""


class Plant:
    def __init__(self, name: str, height: float, plant_age: int) -> None:
        self.name = name
        self.height = height
        self.plant_age = plant_age

    def grow(self, size: float = 1) -> None:
        self.height += size

    def age(self, days: int = 1) -> None:
        self.plant_age += days

    def show(self) -> None:
        print(f"{self.name}: {round(self.height, 1)}cm", end="")
        print(f", {self.plant_age} days old")


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    plants_data = [
        ("Rose", 25.0, 30),
        ("Oak", 200.0, 365),
        ("Cactus", 5.0, 90),
        ("Sunflower", 80.0, 45),
        ("Fern", 15.0, 120)
    ]

    plants = [Plant(name, h, a) for name, h, a in plants_data]

    for plant in plants:
        print("Created: ", end="")
        plant.show()
