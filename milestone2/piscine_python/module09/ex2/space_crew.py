
from enum import Enum
from datetime import datetime
from pydantic import BaseModel, Field, model_validator, ValidationError


class Rank(str, Enum):
    cadet = "cadet"
    officer = "officer"
    lieutenant = "lieutenant"
    captain = "captain"
    commander = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default="planned")
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def validate_mission(self) -> 'SpaceMission':
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")

        needed_ranks = {Rank.commander, Rank.captain}
        if not any(member.rank in needed_ranks for member in self.crew):
            raise ValueError("Mission must have one Commander or Captain")

        if self.duration_days > 365:
            veterans = [m for m in self.crew if m.years_experience >= 5]
            if len(veterans) < (len(self.crew) / 2):
                raise ValueError("Long missions need 50% experienced crew")

        if not all(member.is_active for member in self.crew):
            raise ValueError("All crew member must be active")
        return self


def main() -> None:
    print("Space Mission Crew Validation")
    print("=========================================")

    valid_mission = {
        'mission_id': 'M2024_TITAN',
        'mission_name': 'Solar Observatory Research Mission',
        'destination': 'Solar Observatory',
        'launch_date': '2024-03-30T00:00:00',
        'duration_days': 451,
        'crew': [
            {
                'member_id': 'CM001',
                'name': 'Sarah Williams',
                'rank': 'captain',
                'age': 43,
                'specialization': 'Mission Command',
                'years_experience': 19,
                'is_active': True
            },
            {
                'member_id': 'CM002',
                'name': 'James Hernandez',
                'rank': 'captain',
                'age': 43,
                'specialization': 'Pilot',
                'years_experience': 30,
                'is_active': True
            },
            {
                'member_id': 'CM003',
                'name': 'Anna Jones',
                'rank': 'cadet',
                'age': 35,
                'specialization': 'Communications',
                'years_experience': 15,
                'is_active': True
            },
            {
                'member_id': 'CM004',
                'name': 'David Smith',
                'rank': 'commander',
                'age': 27,
                'specialization': 'Security',
                'years_experience': 15,
                'is_active': True
            },
            {
                'member_id': 'CM005',
                'name': 'Maria Jones',
                'rank': 'cadet',
                'age': 55,
                'specialization': 'Research',
                'years_experience': 30,
                'is_active': True
            }
        ],
        'mission_status': 'planned',
        'budget_millions': 2208.1
    }

    try:
        mission = SpaceMission.model_validate(valid_mission)
        print("\nValid mission created")
        print(f"Mission: {mission.mission_name}")
        print(f"ID: {mission.mission_id}")
        print(f"Destination: {mission.destination}")
        print(f"Duration: {mission.duration_days}")
        print(f"Budget: {mission.budget_millions}")
        print(f"Crew Size: {len(mission.crew)}")
        print(f"Crew Member: {mission.crew}")
    except ValidationError as e:
        print(f"Exception -> {e.errors()}")

    print("=========================================")
    print("\nInvalid Data")
    invalid_mission = valid_mission.copy()
    invalid_mission["crew"] = [
        {
            'member_id': 'CM001', 'name': 'John Doe',
            'rank': 'cadet', 'age': 20,
            'specialization': 'Cleaning', 'years_experience': 0
        }
    ]

    try:
        SpaceMission.model_validate(invalid_mission)
    except ValidationError as e:
        print(f"Exception -> {e.errors()[0]['msg']}")


if __name__ == "__main__":
    main()
