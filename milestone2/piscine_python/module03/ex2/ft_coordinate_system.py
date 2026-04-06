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
import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        line: str = input("Enter new coordinates as floats in format 'x,y,z':")
        parts = line.split(',')
        if len(parts) != 3:
            print("Invalid syntax")
            continue
        try:
            x = float(parts[0])
            y = float(parts[1])
            z = float(parts[2])
            return (x, y, z)
        except ValueError as e:
            for p in parts:
                try:
                    float(p)
                except ValueError:
                    print(f"Error on parameter {p} : {e}")


def calculate_distance(pos1: tuple[float, float, float],
                       pos2: tuple[float, float, float]) -> float:
    return math.sqrt(
        (pos2[0] - pos1[0])**2 +
        (pos2[1] - pos1[1])**2 +
        (pos2[2] - pos1[2])**2
    )


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print("\nGet a first set of coordinates")
    position1 = get_player_pos()
    print(f"Got a first tuple: {position1}")
    print(f"It includes: X={position1[0]}, Y={position1[1]}, Z={position1[2]}")
    dist_to_center: float = calculate_distance(position1, (0.0, 0.0, 0.0))
    print(f"Distance to center {round(dist_to_center, 4)}")

    print("\nGet a second set of coordinates")
    position2 = get_player_pos()
    dist_to_pos: float = calculate_distance(position1, position2)
    print("Distance between the 2 sets of coordinates: ", end="")
    print(f"{round(dist_to_pos, 4)}")
