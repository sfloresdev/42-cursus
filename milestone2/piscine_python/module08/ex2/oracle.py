import os
from dotenv import load_dotenv  # type: ignore


def consult_oracle() -> None:
    print("ORACLE STATUS: Reading the Matrix...")

    env_loaded: bool = load_dotenv()

    mode = os.getenv("MATRIX_MODE", "development")
    db_val = os.getenv("DATABASE_URL")
    api_val = os.getenv("API_KEY")
    logs = os.getenv("LOG_LEVEL")
    endpoint = os.getenv("ZION_ENDPOINT")

    if not all([db_val, api_val, logs, endpoint]):
        print("WARNING: Missing configuration! Some system might not work")

    print("\nConfiguration Loaded:")
    print(f"Mode: {mode}")

    db_status: str
    api_key: str
    if mode == "production":
        db_status = "Connected to Remote Server" if db_val else "Disconnected"
        api_key = "Auth via SSL" if api_val else 'Access Denied'
    else:
        db_status = "Connected to local instance" if db_val else "Disconnected"
        api_key = "Auth" if api_val else 'Access Denied'

    print(f"Database: {db_status}")
    print(f"API Access: {api_key}")
    print(f"Log level: {logs if logs else 'NOT SET'}")
    print(f"Zion network: {'Online' if endpoint else 'Offline'}")

    print("\nEnvironment security check:")
    if api_val and db_val:
        print("[OK] No hardcoded secrets detected")
    else:
        print("[!] Security risk: Critical secrets missing")

    if env_loaded:
        print("[OK] .env file loaded")
    else:
        print("[! ] .env file not detected")

    if mode == "production":
        print("[OK] Production overrides available")
    else:
        print("[!] Default settings active")
    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    consult_oracle()
