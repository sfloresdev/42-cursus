
import json
import csv
from pydantic import BaseModel, ValidationError
from typing import Type, TypeVar, Dict, List, Any

from ex0.space_station import SpaceStation
from ex1.alien_contact import AlienContact
from ex2.space_crew import SpaceMission

T = TypeVar('T', bound=BaseModel)


def validate_data_file(model: Type[T], file: str) -> None:

    data: List[Dict[str, Any]] = []

    try:
        if file.endswith(".json"):
            with open(file, 'r') as f:
                data = json.load(f)
        elif file.endswith(".csv"):
            with open(file, 'r') as f:
                data = list(csv.DictReader(f))
        else:
            print("File not supported")
            return

        for i, record in enumerate(data):
            try:
                model.model_validate(record)
            except ValidationError as e:
                print(f"Entry {i}, Invalid: {e.errors()[0]['msg']}")
    except FileNotFoundError as e:
        print(f"Missing File -> {file}: {e}")
    except Exception as e:
        print(f"Failure: {e}")


def main() -> None:
    base_path = "generated_data"
    print("Space Station ->")
    # JSON test
    print("JSON")
    validate_data_file(SpaceStation, f"{base_path}/space_stations.json")
    # CSV test
    print("CSV")
    validate_data_file(SpaceStation, f"{base_path}/space_stations.csv")
    # Invalid data
    print("Corrupted Data")
    validate_data_file(SpaceStation, f"{base_path}/invalid_stations.json")

    print("\nAlien Contact ->")
    print("JSON")
    validate_data_file(AlienContact, f"{base_path}/alien_contacts.json")
    print("CSV")
    validate_data_file(AlienContact, f"{base_path}/alien_contacts.csv")
    print("Corrupted Data")
    validate_data_file(AlienContact, f"{base_path}/invalid_contacts.json")

    print("\nSpace Mission (Crew Members) ->")
    validate_data_file(SpaceMission, f"{base_path}/space_missions.json")


if __name__ == "__main__":
    main()
