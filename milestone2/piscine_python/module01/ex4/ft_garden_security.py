#!/usr/bin/env python3

"""
Encapsulacion de propiedades de un objeto y proteccion ante
mala ingesta de datos (Validación)
"""


class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = 0.0
        self._age = 0

        self.set_age(age)
        self.set_height(height)
        print("Plant created: ", end="")
        self.get_info()

    def set_age(self, days: int) -> None:
        if days < 0:
            print(f"{self.name}: Error, Can't set days less than 0 ")
            print("Age update rejected")
        else:
            self._age = days
            print(f"Age updated {self._age} days")

    def set_height(self, size: float) -> None:
        if size < 0:
            print(f"{self.name}: Error, Can't set height less than 0 ")
            print("Height update rejected")
        else:
            self._height = size
            print(f"Height updated {self._height}cm")

    def get_age(self) -> float:
        return self._age

    def get_height(self) -> float:
        return self._height

    def get_info(self) -> None:
        print(f"{self.name}: {round(self._height, 1)}cm, {self._age} days")


if __name__ == "__main__":
    print("=== Garden Security System")
    rose = Plant("Rose", 15.0, 10)

    print("\n")
    rose.set_height(25.0)
    rose.set_age(30)
    print("\n")
    rose.set_height(-10.0)
    rose.set_age(-5)

    print("\nCurrent state: ", end="")
    rose.get_info()
