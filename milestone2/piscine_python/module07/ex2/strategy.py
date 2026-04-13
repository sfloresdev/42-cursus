
from .battle import BattleStrategy
from ex0.base import Creature
from ex1.transform import TransformCapability
from ex1.heal import HealCapability


class StrategyError(Exception):
    pass


class NormalStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return True

    def act(self, creature: Creature) -> None:
        print(creature.attack())


class AggressiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise StrategyError(
                f"Invalid Creature '{creature.name}'"
                f"for this aggressive strategy"
                )
        if isinstance(creature, TransformCapability):
            print(creature.transform())
            print(creature.attack())
            print(creature.revert())


class DefensiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature):
        return isinstance(creature, HealCapability)

    def act(self, creature):
        if not self.is_valid(creature):
            raise StrategyError(
                f"Invalid Creature '{creature.name}'"
                f"for this defensive strategy"
                )
        print(creature.attack())
        if isinstance(creature, HealCapability):
            print(creature.heal())
