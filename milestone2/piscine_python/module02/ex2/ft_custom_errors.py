#!/usr/bin/env python3
"""
module02.ex2.ft_custom_errors - Crear tus propios tipos de error
"""


class GardenError(Exception):
    pass


class PlantError(GardenError):
    def __init__(self, name: str):
        self.name = name
        super().__init__(f"The {name} is wilting!")


class WaterError(GardenError):
    def __init__(self):
        super().__init__("Not enough water in the tank")


def check_plant(plant_name: str, plant_age: int):
    if plant_age > 6:
        raise PlantError(plant_name)


def check_water_tank(water_level: int):
    if water_level < 5:
        raise WaterError()


def check_garden():
    print("Checking Garden Status...")
    plant = {"name": "tomato", "age": 9}
    water_tank = 3

    try:
        check_plant(plant["name"], plant["age"])
    except PlantError as e:
        print(f"Caught Plant error: {e}")

    try:
        check_water_tank(water_tank)
    except WaterError as e:
        print(f"Caught Water error: {e}")

    print("\nTesting catching all garden errors...")
    try:
        check_plant(plant["name"], plant["age"])
    except GardenError as e:
        print(f"Caught a garden error: {e}")

    try:
        check_water_tank(water_tank)
    except GardenError as e:
        print(f"Caught a garden error: {e}")


def test_custom_errors_types():
    print("=== Garden Custom Exceptions Test ===\n")
    check_garden()
    print("\nAll custom errors types work correctly!")
    print("And the program didn't crash :)")


test_custom_errors_types()
