#!/usr/bin/env python3
class Plant: 
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age
    
    def info(self):
        print(f"{self.name}: {self.height}cm, {self.age} days old")

p = Plant("Rose", 25, 30)
p1 = Plant("Sunflower", 80, 45)
p2 = Plant("Cactus", 15, 120)

p.info()
p1.info()
p2.info()
