
from ex0.base import Creature, CreatureFactory
from .capability import TransformCapability


class Shiftling(Creature, TransformCapability):
    def __init__(self, name: str) -> None:
        TransformCapability.__init__(self)
        Creature.__init__(self, name, "Normal")

    def transform(self) -> str:
        self._is_transformed = True
        return f"{self.name} shifts into a sharper form!"

    def revert(self) -> str:
        self._is_transformed = False
        return f"{self.name} returns to normal"

    def attack(self) -> str:
        if self._is_transformed:
            return f"{self.name} performs a boosted strike!"
        return f"{self.name} attacks normally"


class Morphagon(Creature, TransformCapability):
    def __init__(self, name: str) -> None:
        TransformCapability.__init__(self)
        Creature.__init__(self, name, "Normal/Dragon")

    def transform(self) -> str:
        self._is_transformed = True
        return f"{self.name} morphs into a dragonic battle form!"

    def revert(self) -> str:
        self._is_transformed = False
        return f"{self.name} stabilizes its form."

    def attack(self) -> str:
        if self._is_transformed:
            return f"{self.name} unleashes a devastating morph strike!"
        return f"{self.name} attacks normally"


class TransformCreatureFactory(CreatureFactory):
    def create_base(self, name: str) -> Creature:
        return Shiftling(name)

    def create_evolved(self, name: str) -> Creature:
        return Morphagon(name)
