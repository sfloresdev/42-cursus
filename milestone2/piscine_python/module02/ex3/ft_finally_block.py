#!/usr/bin/env python3
"""
module02.ex3.ft_finally_block - Bloque Finally = Siempre Limpia
"""


def water_plants(plant_list):
    print("Preparing sprinklers...")

    try:
        print("Watering plants\n")
        for plant in plant_list:
            print(f"Watering {plant['name']}")
        print("Watering completed succesfully!")
    except Exception:
        print("Error: Cannot water None - invalid plant!")
    finally:
        print("Closing Watering system (cleanup)\n")


def test_watering_system():
    garden = {"name": "oak"}, {"name": "tomatoes"}, {"name": "apples"}
    garden2 = {"name": "oak"}, None, {"name": "apples"}
    print("=== Garden Watering System ===\n")
    water_plants(garden)
    water_plants(garden2)
    print("Cleanup always happens, even with errors!")


test_watering_system()
