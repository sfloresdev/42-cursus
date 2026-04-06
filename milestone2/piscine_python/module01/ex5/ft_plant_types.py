#!/usr/bin/env python3


class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = 0.0
        self._age = 0

        self.set_age(age)
        self.set_height(height)

    def grow(self, size: float = 1.0) -> None:
        self._height += float(size)

    def age(self, days: int = 1) -> None:
        self._age += days

    def set_age(self, days: int) -> None:
        if days < 0:
            print(f"{self.name}: Error, Can't set days less than 0 ")
            print("Age update rejected")
        else:
            self._age = days

    def set_height(self, size: float) -> None:
        if size < 0:
            print(f"{self.name}: Error, Can't set height less than 0 ")
            print("Height update rejected")
        else:
            self._height = float(size)

    def get_age(self) -> int:
        return self._age

    def get_height(self) -> float:
        return self._height

    def show(self) -> None:
        print(f"{self.name}: {round(self._height, 1)}cm, {self._age} days old")


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color: str = color
        self._is_blooming: bool = False

    def bloom(self) -> None:
        self._is_blooming = True

    def show(self) -> None:
        super().show()
        print(f"Color: {self.color}")
        if self._is_blooming:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} has not bloomed yet")


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter: float = trunk_diameter

    def produce_shade(self) -> None:
        print(f"Tree {self.name} now produces a shade of ", end="")
        print(f"{round(self._height, 1)} cm lon and ", end="")
        print(f"{round(self.trunk_diameter, 1)}cm wide")

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter {round(self.trunk_diameter, 1)}cm")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str) -> None:
        super().__init__(name, height, age)
        self.harvest_season: str = harvest_season
        self.nutritional_value: int = 0

    def grow(self, size: float = 1.0) -> None:
        super().grow(size)

    def age_up(self, days: int = 1) -> None:
        super().age(days)
        self.nutritional_value += days

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self.harvest_season}")
        print(f"Nutritional value: {self.nutritional_value}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")

    print("\n=== Flower")
    f = Flower("Rose", 15.0, 10, "red")
    f.show()
    print("[asking the rose to bloom]")
    f.bloom()
    f.show()

    print("\n=== Tree")
    t = Tree("Oak", 200.0, 365, 5.0)
    t.show()
    print("[asking the oak to produce shade]")
    t.produce_shade()

    print("\n=== Vegetable")
    v = Vegetable("Tomato", 5.0, 10, "April")
    v.show()
    print("[make tomato grow and age for 20 days]")
    v.grow(42.0)
    v.age_up(20)
    v.show()
