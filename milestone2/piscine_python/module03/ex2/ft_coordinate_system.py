#!/usr/bin/env python3
"""
module03.ex2.ft_coordinate_system - Rastredor de Posición
Nuestra mision es construir un sistema de coordenadas 3D
usando 'tuples'. Estas 'tuples' no pueden cambiarse por
accidente: perfectas para definir posiciones en un juego

Vamos a:
- Crear posiciones 3D, como por ejemplo spawnpoints (x, y, z)
- Calcular distancias usando la formula euclidiana 3D:
  sqrt((x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2)
"""
import sys
import math

# a malas hacemos un x= sys.argv[1], y = sys.argv[2], etc...
# porque nuestro programa no va a recbir mas de 3 argumentos


def coordinate_system():
    print("=== Game Coordinate System ===")
    coordinates = command_data()
    print(f"Position created {coordinates}")
    position = tuple(coordinates)
    x, y, z = position
    distance = float(math.sqrt(x**2 + y**2 + z**2))
    print(f"Distance between (0, 0, 0) and ({x}, {y}, {z}): {distance}")


def command_data() -> list:
    arguments = len(sys.argv) - 1
    if arguments == 3:
        raw_data = []
        print("Parsing coordinates:", end="")
        for data in sys.argv[1:]:
            try:
                points = int(data)
                print(f" {points}", end="")
                raw_data.append(points)
            except ValueError:
                print("Parsing Error: invalid literal for int()")
    else:
        raise ValueError("Not enough arguments provided")
    print("")
    return raw_data


if __name__ == "__main__":
    coordinate_system()
