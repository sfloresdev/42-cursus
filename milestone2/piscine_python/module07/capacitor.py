
import ex1 as creature


def main() -> None:
    print("Testing Creature with healing capability")
    print("Base:")
    h_factory = creature.HealingCreatureFactory()
    healing = h_factory.create_base("Sproutling")
    print(healing.describe())
    print(healing.attack())
    print(healing.heal())  # type: ignore

    print("Evolved:")
    h_evolved = h_factory.create_evolved("Bloomelle")
    print(h_evolved.describe())
    print(h_evolved.attack())
    print(h_evolved.heal())  # type: ignore

    print("\nTesting Creature with transform capability")
    print("Base")
    t_factory = creature.TransformCreatureFactory()
    t_base = t_factory.create_base("Shiftling")
    print(t_base.describe())
    print(t_base.attack())
    print(t_base.transform())  # type: ignore
    print(t_base.attack())
    print(t_base.revert())  # type: ignore

    print("Evolved:")
    t_evolved = t_factory.create_evolved("Morphagon")
    print(t_evolved.describe())
    print(t_evolved.attack())
    print(t_evolved.transform())  # type: ignore
    print(t_evolved.attack())
    print(t_evolved.revert())  # type: ignore


if __name__ == "__main__":
    main()
