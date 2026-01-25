#!usr/bin/env python3
"""
module02.ex4.ft_raise_errors
"""


def check_plant_health(plant_name: str, water_level: int, sunlight_hours: int):
    print("Testing good values...\n")
    if plant_name == "":
        raise ValueError("Error: Plant name cannot be empty\n")
    if water_level < 1:
        raise ValueError("Error: Water level is to low (min 1)\n")
    if water_level > 10:
        raise ValueError("Error: Water level is to high (max 10\n)")
    if sunlight_hours < 2:
        raise ValueError("Error: Sunlight time is to low (min 2)\n")
    if sunlight_hours > 12:
        raise ValueError("Error: Sunlight time is to high (max 12)\n")
    return f"Plant: '{plant_name}' is healthy!\n"


def test_plant_checks():
    plants = [{"name": "tomato", "water_level": 5, "sunlight_hours": 6},
              {"name": "oak", "water_level": 0, "sunlight_hours": 6},
              {"name": "banana", "water_level": 4, "sunlight_hours": 15}]

    print("=== Garden Health Status Check ===\n")

    for plant in plants:
        try:
            result = check_plant_health(plant['name'], plant['water_level'],
                                        plant['sunlight_hours'])
            print(f"{result}")
        except ValueError as e:
            print(f"{e}")
    print("All error raising tests completed!")


test_plant_checks()
