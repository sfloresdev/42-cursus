#!/usr/bin/env python3

import sys

print("=== Command Quest ===")
arguments = sys.argv[1:]
if len(sys.argv) < 2:
    print("No arguments provided!")
    print(f"Program name: {sys.argv[0]}")
else:
    print(f"Program name: {sys.argv[0]}")
    print(f"Arguments received: {len(sys.argv) - 1}")
    i = 1
    for arg in arguments:
        print(f"Argument: {i} : {arg}")
        i += 1

print(f"Total arguments: {len(sys.argv)}")
