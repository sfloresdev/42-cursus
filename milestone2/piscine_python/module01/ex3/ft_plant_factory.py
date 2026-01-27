#!/usr/bin/env python3

"""
Creacion de plantas de manera automatica
Optimizacion del proceso de creacion e inicializacion
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


def plant_factory():
    print("=== Plant Factory Output ===")

    plants_data = [
        {"name": "Rose", "height": 25, "age": 30},
        {"name": "Oak", "height": 200, "age": 365},
        {"name": "Cactus", "height": 5, "age": 90},
        {"name": "Sunflower", "height": 80, "age": 45},
        {"name": "Fern", "height": 15, "age": 120}
    ]
    plants_created = []
    plants_count = 0
    for plant in plants_data:
        n_plant = Plant(plant['name'], plant['height'], plant['age'])
        plants_created.append(n_plant)
        print("Created: ", end="")
        print(f"{n_plant.name} ({n_plant.height},{n_plant.plant_age})")
        plants_count += 1
    print(f"\nTotal plants created: {plants_count}")


plant_factory()
