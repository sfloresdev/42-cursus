import sys
import typing


def recover_data(file_name: str) -> None:
    print("=== Cyber Archives Recovery ===")
    print(f"Accesing file '{file_name}'")
    file_handle: typing.IO

    try:
        file_handle = open(file_name, 'r')
        content = file_handle.read()
        print(content, end="")
        file_handle.close()
        print(f"File '{file_name}' closed.")
        print("Transform data:")
        transformed_content = content.replace('\n', '#\n')
        print(transformed_content, end="")
        new_name = input("\nEnter new file name (or empty):")
        if not new_name:
            print("Not saving data.")
            return
        print(f"Saving data to '{new_name}'")
        write_handle = open(new_name, 'w')
        write_handle.write(transformed_content)
        write_handle.close()
        print(f"Data saved in file '{new_name}'.")

    except (FileNotFoundError, PermissionError) as e:
        print(f"Error opening file '{file_name}': {e}")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
    else:
        recover_data(sys.argv[1])
