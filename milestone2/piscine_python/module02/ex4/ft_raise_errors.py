#!/usr/bin/env python3

class PlantError(Exception):
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    if plant_name == str.capitalize(plant_name):
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system() -> None:
    print("=== Garden Watering System ===")
    print("\nTesting valid plants...")
    test_data = ["Tomato", "Lettuce", "Carrots"]
    try:
        print("Opening watering system...")
        for plant in test_data:
            water_plant(plant)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending test and returning to main")
        return
    finally:
        print("Closing watering system")
    print("\nTesting invalid plants...")
    test_data2 = ["Tomato", "lettuce", "Carrots"]
    try:
        print("Opening watering system...")
        for plant in test_data2:
            water_plant(plant)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending test and returning to main")
        return
    finally:
        print("Closing watering system")


if __name__ == "__main__":
    test_watering_system()
    print("\nCleanup always happens, even with errors!")
