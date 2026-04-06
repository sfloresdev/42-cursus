#!/usr/bin/env python3

"""
Encapsulacion de propiedades de un objeto y proteccion ante
mala ingesta de datos (Validación)
"""


class SecurePlant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self._height = 0
        self._age = 0
        self.set_age(age)
        self.set_height(height)

    def set_age(self, days: int) -> None:
        if days < 0:
            print("ERROR: Cannot set days less than 0 ", end="")
            print("[REJECTED]")
        else:
            self._age = days
            print(f"Age updated {self._age} [OK]")

    def set_height(self, size: int) -> None:
        if size < 0:
            print("ERROR: Cannot set a height less than 0 ", end="")
            print("[REJECTED]")
        else:
            self._height = size
            print(f"Height updated {self._height} [OK]")

    def get_age(self) -> int:
        return self._age

    def get_height(self) -> int:
        return self._height

    def get_info(self) -> None:
        print(f"{self.name}: {self._height}cm, {self._age} days")


if __name__ == "__main__":
    print("=== Garden Security System")

    # 1
    print("\nCreando planta con datos validos")
    rose = SecurePlant("Rose", 25, 30)
    print(f"Plant created: {rose.name}")
    print("\n--- Estado inicial ---")
    rose.get_info()

    # 2
    print("\n--- Actualización ---")
    rose.set_height(35)
    print("\nIntento datos erroneos")
    rose.set_height(-10)
    rose.set_age(-5)

    # 3
    print("\n--- Estado final ---")
    rose.get_info()
