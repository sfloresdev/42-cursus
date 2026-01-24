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

    def create_garden_network():
        print("Creating network...")

	class GardenStats:
		def __init__(self):




class Garden:
    def __init__(self, user:str, n_plants: int):
        self.user = user
        self._n_plants = n_plants
    
	def add_plant(name: str,):
             





class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age


class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color


class PrizeFlower(FloweringPlant):
    def __init__(self, name:str, height:int, age:int, color:str, prize:int):
        super().__init__(name, height, age, color)
        self.prize = prize
