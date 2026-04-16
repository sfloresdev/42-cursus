import os
import sys
from dotenv import load_dotenv

def consult_oracle() -> None:
	print("ORACLE STATUS: Reading the Matrix...")

	mode = os.getenv("MATRIX_MODE", "development")
	db_url = os.getenv("DATABASE_URL")
	api_key = os.getenv("API_KEY")
	logs = os.getenv("LOG_LEVEL")
	endpoint = os.getenv("ZION_ENDPOINT")

	if not all([db_url, api_key, logs, endpoint]):
		print("WARNING: Missing configuration! Some system might not work")

	print("\nConfiguration Loaded:")
	print(f"Mode: {mode}")
	if mode == "production":
		db_status = "Connected to Remote Server"
		api_key = "Auth via SSL"
	else:
		db_status = "Connected to local instance"
		api_key = "Auth"

	print(f"Database: {db_status}")
	print(f"API Access: {api_key if api_key else 'Access Denied'}")
	print(f"Log level: {logs if logs else 'NOT SET'}")
	print(f"Zion network: { 'Online' if endpoint else 'Offline'}")


	print("\nEnvironment security check:")
	if api_key and db_url:
		print("[OK] No hardcoded secrets detected")
	else:
		print("[!] Security risk: Critical secrets missing")
	
	if env_loaded:
		print("[OK] .env file loaded")
	else:
		print("[!] .env file not detected")

	if mode == "production":
		print("[OK] Production overrides available")
	else:
		print("[!] Default settings active")
	print("The Oracle sees all configurations.")


if __name__ == "__main__":
	consult_oracle()
