#!/usr/bin/env python3


class Plant:

    class Stats:
        def __init__(self) -> None:
            self._grow_calls: int = 0
            self._age_calls: int = 0
            self._show_calls: int = 0

        def display(self) -> None:
            print(f"Stats: {self._grow_calls} grow, "
                  f"{self._age_calls} age, {self._show_calls} show")

    def __init__(self, name: str, height: float, age: int) -> None:
        self.name: str = name
        self._height: float = height
        self._age: int = age
        self._stats: Plant.Stats = self.Stats()
        self.set_height(height)
        self.set_age(age)

    @staticmethod
    def is_older_than_year(age: int) -> bool:
        return age > 365

    @classmethod
    def create_anonymus(plant) -> "Plant":
        return plant("Unknown plant", 0.0, 0)

    def set_height(self, height: float) -> None:
        if height < 0:
            print(f"{self.name}: Error, Can't set height less than 0 ")
        else:
            self._height = height

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"{self.name}: Error, Can't set age less than 0 ")
        else:
            self._age = age

    def grow(self, size: float = 1) -> None:
        self._height += size
        self._stats._grow_calls += 1

    def age_up(self, days: int = 1) -> None:
        self._age += days
        self._stats._age_calls += 1

    def show(self) -> None:
        self._stats._show_calls += 1
        print(f"{self.name}: {round(self._height, 1)}cm, {self._age} days old")

    def display_extra_stats(self) -> None:
        pass


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str):
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


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str):
        super().__init__(name, height, age, color)
        self._seeds: int = 0

    def seed(self) -> None:
        self._seeds += 1

    def show(self) -> None:
        super().show()
        print(f"Seeds: {self._seeds}")


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter: float = trunk_diameter
        self._shade_calls: int = 0

    def produce_shade(self) -> None:
        print(f"Tree {self.name} now produces a shade of ", end="")
        print(f"{round(self._height, 1)} cm long and ", end="")
        print(f"{round(self.trunk_diameter, 1)}cm wide")
        self._shade_calls += 1

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter {round(self.trunk_diameter, 1)}cm")

    def display_extra_stats(self) -> None:
        print(f"{self._shade_calls} shade")


def display_plant_stats(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant._stats.display()
    plant.display_extra_stats()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("\n=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_older_than_year(400)}")

    print("\n=== Flower")
    rose = Flower("Rose", 23.0, 10, "red")
    rose.show()
    display_plant_stats(rose)
    print("[asking the rose to grow and bloom]")
    rose.bloom()
    rose.grow()
    rose.show()
    display_plant_stats(rose)

    print("\n=== Tree")
    tree = Tree("Oak", 200.0, 365, 5.0)
    tree.show()
    display_plant_stats(tree)
    print("[asking the oak to produce shade]")
    tree.produce_shade()
    display_plant_stats(tree)

    print("\n=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow(30.0)
    sunflower.age_up(20)
    for i in range(1, 43):
        sunflower.seed()
    sunflower.bloom()
    sunflower.show()
    display_plant_stats(sunflower)

    print("\n=== Anonymus")
    anon = Plant.create_anonymus()
    anon.show()
    display_plant_stats(anon)
