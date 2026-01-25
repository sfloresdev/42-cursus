#!/usr/bin/env python3
"""
Represents a plant entity in our garden
"""


class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def info(self):
        print(f"{self.name}: {self.height}cm, {self.age} days old")


if __name__ == "__main__":
    p = Plant("Rose", 25, 30)
    p1 = Plant("Sunflower", 80, 45)
    p2 = Plant("Cactus", 15, 120)

    print("Garden Plant Registry")
    p.info()
    p1.info()
    p2.info()
