#!/usr/bin/env python3
"""
module03.ex0.ft_command_quest - Misión de comandos
En este ejercicio descubirmos como construir un simple interprete
de comandos.

La magia esta en:
- Descubrir como los programas pueden recibir información por linea de comandos
- Aprender a procesar distintos tipos de datos de entrada
- Gestionar casos en los que no se indica nada
- Mostrar la informacion de manera clara para el que lo necesite
"""


def command_quest():
    import sys

    print("=== Command Quest ===")
    total_count = len(sys.argv)
    if total_count > 1:
        i = 1
        print(f"Program name: {sys.argv[0]}")
        print(f"Arguments recieved: {total_count - 1}")
        for arg in sys.argv[1:]:
            print(f"Argument {i}: {arg}")
            i += 1
        print(f"Total arguments: {total_count}")
    else:
        print("No arguments provided!")
        print(f"Program name: {sys.argv[0]}")
        print(f"Total arguments: {total_count}")


if __name__ == "__main__":
    command_quest()
