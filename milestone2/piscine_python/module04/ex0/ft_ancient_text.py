import sys
import typing


def read_data(file_name: str) -> None:
    print("=== Cyber Archives Recovery ===")
    print(f"Accesing file '{file_name}'")
    file_handle: typing.IO

    try:
        file_handle = open(file_name, 'r')
        content = file_handle.read()
        print(f"{content}", end="")
        print(f"File '{file_name}' closed.")
    except (FileNotFoundError, PermissionError) as e:
        print(f"Error opening file {file_name}: {e}")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
    else:
        read_data(sys.argv[1])
