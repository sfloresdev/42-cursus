
import sys
import os
import site


def check_matrix() -> None:

    in_venv = sys.prefix != sys.base_prefix

    if not in_venv:
        print("MATRIX STATUS: You're still plugged in")
        print(f"Current Python: {sys.executable}")
        print("Virtual environment: None detected!")
        print("WARNING: You're in the global environment!")
        print("\nTo enter the construct, run:")
        print("python3 -m venv matrix_env")
        print("source matrix_env/bin/activate")

    else:
        print("MATRIX STATUS: Welcome to the construct")
        print(f"Current Python: {sys.executable}")
        print(f"Virtual environment: {os.path.basename(sys.prefix)}")
        print(f"Environment Path: {sys.prefix}")
        print("\nSUCCES: You're in an isolated environment!")
        print("Safe to install packages without affecting the global system.")
        print(f"\n Package installation path:\n{site.getsitepackages()[0]}")


if __name__ == "__main__":
    check_matrix()
