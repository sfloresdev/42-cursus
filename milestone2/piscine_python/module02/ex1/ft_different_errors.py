#!/usr/bin/env python3
"""
module02.ex1.ft_different_errors - Diferentes tipos de errores

"""


# La función 'garden_operations()' tiene como objetivo demostrar tipos
# de errores comunes: ValueError, ZeroDivisionError, KeyError


def garden_operations():
    try:
        number = 4 / 0
        print(f"Number is: {number}")
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero\n")

    try:
        temp = int("abc")
        print(f"Temp: {temp}")
    except ValueError:
        print("Caught ValueError: invalid literal for int()\n")

    try:
        open("missing.txt", "r")
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'missing.txt'\n")

    try:
        garden = {"test": "faef"}
        plant = "missing_plant"
        print(garden[plant])
    except KeyError:
        print(f"Caught KeyError: '{plant}'\n")

    print("Testing multiple errors!")
    try:
        int("Nene")
    except (ValueError, FileNotFoundError, KeyError, ZeroDivisionError):
        print("Caught an error, but program continues!\n")


def test_errors_types():
    print("=== Garden Errors Types ===\n")
    garden_operations()
    print("All error types test succesfully!")


test_errors_types()
