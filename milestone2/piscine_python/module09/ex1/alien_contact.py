
from enum import Enum
from pydantic import BaseModel, Field, model_validator, ValidationError
from typing import Optional
from datetime import datetime


class ContactType(str, Enum):
    radio = "radio"
    visual = "visual"
    physical = "physical"
    telepathic = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: Optional[str] = Field(default=None, max_length=500)
    is_verified: bool = Field(default=False)

    @model_validator(mode='after')
    def validate_alien_log(self) -> 'AlienContact':
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must start with 'AC'")

        if self.contact_type == ContactType.physical and not self.is_verified:
            raise ValueError("Physical contact must be verified")

        if (
            self.contact_type == ContactType.telepathic
            and self.witness_count < 3
        ):
            raise ValueError("Telepathic contact needs (>= 3) witness")

        if self.signal_strength > 7.0 and self.message_received is None:
            raise ValueError(
                "A recorded message is needed if signal_strenght is (> 7.0)"
                )
        return self


def main() -> None:
    print("Alien Contact Log Validation")
    print("======================================")

    valid_alien_log = {
        'contact_id': 'AC_2024_007',
        'timestamp': '2024-03-25T00:00:00',
        'location': 'Atacama Desert, Chile',
        'contact_type': 'physical',
        'signal_strength': 9.0,
        'duration_minutes': 138,
        'witness_count': 10,
        'message_received': 'Request for peaceful contact',
        'is_verified': True
    }

    try:
        alien_log = AlienContact.model_validate(valid_alien_log)
        print("Valid contact report:")
        print(f"ID: {alien_log.contact_id}")
        print(f"Type: {alien_log.contact_type.value}")
        print(f"Location {alien_log.location}")
        print(f"Signal: {alien_log.signal_strength}")
        print(f"Duration: {alien_log.duration_minutes}")
        print(f"Witness: {alien_log.witness_count}")
        print(f"Message: {alien_log.message_received}")
    except ValidationError as e:
        print(f"Validation error -> {e.errors()[0]['msg']}")

    print("\n======================================")
    print("Excepted validation error:")
    invalid_alien_log = valid_alien_log.copy()
    invalid_alien_log["message_received"] = None

    try:
        AlienContact.model_validate(invalid_alien_log)
    except ValidationError as e:
        print(f"Validation error -> {e.errors()[0]['msg']}")


if __name__ == "__main__":
    main()
