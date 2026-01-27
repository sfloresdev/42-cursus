#!/usr/bin/env python3
"""
module02.ex5.ft_garden_management
"""


class GardenError(Exception):
    pass


class PlantError(GardenError):
    def __init__(self, name: str, message: str):
        self.name = name
        super().__init__(f"Error -> {name} is having trouble - {message}")


class WaterError(GardenError):
    def __init__(self, message: str):
        super().__init__(f"Water Error -> {message}")


class GardenManager:

    def __init__(self, owner: str):
        self.owner = owner
        self.plants = []

    def validate_inputs(self, name: str, water: int, sun: int):
        if name == "":
            raise PlantError("Plant", "- Name cannot be empty")
        if water < 1 or water > 10:
            raise WaterError("Water level is out of range")
        if sun < 2 or sun > 12:
            raise PlantError(name, "Sunlight time is invalid")

    def add_plant(self, name: str, water: int, sun: int):
        try:
            self.validate_inputs(name, water, sun)
            self.plants.append(Plant(name, water, sun))
            print(f"Added {name} successfully")
        except GardenError as e:
            print(f"Error adding plant: {e}")

    def water_plants(self):
        print("Watering plants...")
        print("Opening watering system")
        try:
            for plant in self.plants:
                try:
                    if plant.water >= 10:
                        raise WaterError(f"Water level {plant.water} high")
                    plant.water += 1
                    print(f"Watering {plant.name} - success")
                except WaterError as e:
                    print(f"Error watering {plant.name}: {e}")
        finally:
            print("Closing watering system (cleanup)\n")

    def plant_status(self):
        for plant in self.plants:
            try:
                if plant.water >= 10:
                    raise WaterError(f"{plant.name} || Water level high")
                if plant.water <= 1:
                    raise WaterError("Not enough water in the tank")
                if plant.sun > 12:
                    raise PlantError(plant.name, "too much sun time")
                if plant.sun < 2:
                    raise PlantError(plant.name, "very low sun time")
                print(f"{plant.name} seems healthy!", end="")
                print(f"(water: {plant.water}, sun {plant.sun})")
            except GardenError as e:
                print(f"Caught GardenError: {e}")
        print("System recovered and continuing...\n")


class Plant:
    def __init__(self, name: str, water: int, sun: int):
        self.name = name
        self.water = water
        self.sun = sun


def garden_tester():
    garden = GardenManager("Sergio")
    print("=== Garden Management System ===\n")
    print("Adding plants to the garden")
    garden.add_plant("Tomato", 5, 6)
    garden.add_plant("Oak", 0, 6)
    garden.add_plant("Banana", 5, 15)
    garden.add_plant("lettuce", 9, 9)
    print("\n")
    garden.water_plants()
    print("\nChecking plant health")
    garden.plant_status()
    print("\nGarden management system test complete!")


garden_tester()
