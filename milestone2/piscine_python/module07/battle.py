
import ex0 as creature
from ex0.base import CreatureFactory


def test_factory(factory: CreatureFactory, name: str, name2: str):
    print("\nTesting Factory")
    base = factory.create_base(name)
    evolved = factory.create_evolved(name2)
    print(base.describe())
    print(base.attack())
    print(evolved.describe())
    print(evolved.attack())


def test_battle(f1: CreatureFactory, f2: CreatureFactory):
    print("\nTesting battle")
    c1 = f1.create_base("Flameling")
    c2 = f2.create_evolved("Aquabub")
    print(c1.describe())
    print("vs")
    print(c2.describe())
    print("Fight!")
    print(c1.attack())
    print(c2.attack())


if __name__ == "__main__":
    flame = creature.FlameFactory()
    aqua = creature.AquaFactory()

    test_factory(flame, "Flameling", "Pyrodon")
    test_factory(aqua, "Aquabub", "Torragon")
    test_battle(flame, aqua)
