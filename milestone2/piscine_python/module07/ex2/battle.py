
import abc
from ex0.base import Creature


class BattleStrategy(abc.ABC):
    @abc.abstractmethod
    def act(self, creature: Creature) -> None:
        pass

    @abc.abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass
