
import random

NAMES = [
    'Alice', 'bob', 'Charlie',
    'dylan', 'Emma', 'Gregory',
    'john', 'kevin', 'Liam'
    ]


if __name__ == "__main__":
    print("=== Game Data Alchemist ===")
    print(f"\nInitial list of players: {NAMES}")
    new_list = [name.capitalize() for name in NAMES]
    print(f"New list with all names capitalized {new_list}")
    list_cap_only = [name for name in NAMES if name == name.capitalize()]
    print(f"New list of capitalized names only: {list_cap_only}")

    print("")
    scores = {name: random.randint(1, 1000) for name in new_list}
    print(f"Score dict: {scores}")
    avg = sum(scores.values()) / len(new_list)
    print(f"Score average is {round(avg, 2)}")

    high_scores = {n: s for n, s in scores.items() if s > avg}
    print(f"High scores: {high_scores}")
