#!/usr/bin/env python3
"""
module02.ex0.ft_first_exception - Pipeline de Validación de Datos Agrícolas
Nuestra pipeline de datos recibe lecturas de temperaturas y sensores del campo.
A veces, estos nos transmiten datos corruptos, valores no validos, etc...

Nuestra capa de validacion de datos debe filtrar todos los datos erroneos
"""


def check_temperature(temp_str):
    print(f"Testing temperature: {temp_str}")
    try:
        temp = int(temp_str)
        if temp > 0 and temp <= 40:
            print(f"Temperature {temp}º is perfect for plants!")
            return temp
        elif temp < 0:
            print(f"Error: {temp} is too cold for plants (max 0º)")
        else:
            print(f"Error: {temp} is too hot for plants (max 40º)")
    except Exception:
        print(f"Error: '{temp_str}' is not a valid number")


def test_temperature_input():
    print("=== Garden Temperature Checker ===\n")
    check_temperature(25)
    check_temperature("abc")
    check_temperature(100)
    check_temperature(-50)
    print("All test completed - program didn't crash!")


test_temperature_input()
