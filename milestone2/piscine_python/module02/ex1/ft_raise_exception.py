#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    num = int(temp_str)
    if num < 0:
        raise Exception(f"{num}ºC is too cold for plants (min 0º)")
    if num > 40:
        raise Exception(f"{num}ºC is too hot for plants (max 40º)")
    return int(temp_str)


def test_temperature() -> None:
    print("=== Garden Temperature Checker===\n")

    test_cases = ["25", "abc", "100", "-50"]

    for data in test_cases:
        print(f"Input data is '{data}'")
        try:
            temp = input_temperature(data)
            print(f"Temperature is now {temp}ºC\n")
        except Exception as e:
            print(f"Caught input_temperature error: {e}\n")

    print("All test completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
