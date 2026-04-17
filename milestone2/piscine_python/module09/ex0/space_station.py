
from typing import Optional
from pydantic import BaseModel, Field, ValidationError
from datetime import datetime


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = Field(default=True)
    notes: Optional[str] = Field(default=None, max_length=200)


def main() -> None:
    print("Space Station Data Validation\n")
    print("========================================")

    valid_data = {
        'station_id': 'LGW125',
        'name': 'Titan Mining Outpost',
        'crew_size': 6,
        'power_level': 76.4,
        'oxygen_level': 95.5,
        'last_maintenance': '2023-07-11T00:00:00',
        'is_operational': True,
        'notes': None
    }

    try:
        station = SpaceStation.model_validate(valid_data)
        print("Valid station created:")
        print(f"ID: {station.station_id}")
        print(f"Name: {station.name}")
        print(f"Crew: {station.crew_size}")
        print(f"Power: {station.power_level}")
        print(f"Oxygen: {station.oxygen_level}")
        print(f"Last maintenance: {station.last_maintenance}")
        print(f"Status: {station.is_operational}")

    except ValidationError as e:
        print(f"ValidationError -> {e}")

    print("\n========================================")
    print("Expected validation error:")
    invalid_data = valid_data.copy()
    invalid_data["crew_size"] = 25

    try:
        SpaceStation.model_validate(invalid_data)
    except ValidationError as e:
        print(f"ValidationError -> {e.errors()[0]['msg']}")


if __name__ == "__main__":
    main()
