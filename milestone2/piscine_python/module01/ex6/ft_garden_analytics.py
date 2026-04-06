#!/usr/bin/env python3
"""
Plataforma analitica de datos para recopilar
los conceptos aprendidos en este módulo

Criterios:
"""




"""
Clase 'GardenManager' -> 'Garden' -> 'GardenStats'
"""

class GardenManager:

    def __init__(self, managed_gardens: int):
        self.managed_gardens = managed_gardens

    def create_garden_network():
        print("Creating network...")
        new_garden = Garden()

    class GardenStats:
        def __init__(self):
            





class Garden:
    def __init__(self, user:str, n_plants: int, total_growth: int):
        self.user = user
        self._n_plants = 0
        self.total_growth = 0
             









class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age
    
    def info(self) -> None:
        print(f"{self.name}: {self.height}")


class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        
    def info(self) -> None:
        print(f"{self.name}: {self.height}, {self.color} flowers (blooming)")


class PrizeFlower(FloweringPlant):
    def __init__(self, name:str, height:int, age:int, color:str, prize:int):
        super().__init__(name, height, age, color)
        self.prize = prize
    
    def info(self):
        print(f"{self.name}: {self.height}, ", end="")
        print(f"{self.color} flowers (blooming), Prize points: {self.prize}")
