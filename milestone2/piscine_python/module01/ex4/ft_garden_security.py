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

    # 1. Prueba de inicialización (Debería imprimir
    print("\n--- Paso 1: Creando planta con datos válidos ---")
    rose = SecurePlant("Rose", 25, 30)
    print(f"Plant created: {rose.name}")

    # 2. Prueba de visualización inicial
    print("\n--- Paso 2: Estado inicial ---")
    rose.get_info()

    # 3. Prueba de actualización válida
    print("\n--- Paso 3: Actualización válida ---")
    rose.set_height(35)

    # 4. Prueba de seguridad (Valores negativos)
    print("\nPaso 4: Intento de corrupción de datos (Valores negativos)")
    rose.set_height(-10)  # Debería mostrar ERROR/REJECTED
    rose.set_age(-5)      # Debería mostrar ERROR/REJECTED

    # 5. Verificación final (Los valores no deben haber cambiado )
    print("\n--- Paso 5: Estado final (Verificación de integridad) ---")
    rose.get_info()
