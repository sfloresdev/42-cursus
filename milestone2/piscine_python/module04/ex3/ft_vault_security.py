def secure_archive(file: str, act: int, string: str = "") -> tuple[bool, str]:
    try:
        if act == 1:
            with open(file, 'r') as f:
                content = f.read()
            return (True, content)
        elif act == 2:
            with open(file, 'w') as f:
                f.write(string)
            return (True, "Content successfully written to file")
        return (False, "Invalid action requested")
    except (FileNotFoundError, PermissionError) as e:
        return (False, f"{e}")


if __name__ == "__main__":
    print("=== Cyber Archives Security ===")
    file_name: str = "test.txt"
    print(f"Using {file_name} to read from a nonexistent file:")
    print(secure_archive("/not/existing/file", 1))

    print(f"Using {file_name} to read from an inaccessible file:")
    print(secure_archive("/etc/shadow", 1))

    print(f"Using {file_name} to read from a regular file:")
    res = secure_archive("test.txt", 1)
    print(res)

    print(f"Using {file_name} to write previous content to a new file:")
    print(secure_archive("backup.txt", 2, "Backup test content"))
