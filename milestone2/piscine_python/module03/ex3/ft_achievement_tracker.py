#!/usr/bin/env python3

import random

ACHIEVEMENTS = [
    "Crafting Genius", "World Savior", "Master Explorer", "Collector Supreme",
    "Untouchable", "Boss Slayer", "Strategist", "Unstoppable", "Speed Runner",
    "Survivor", "Treasure Hunter", "First Steps", "Sharp Mind",
    "Hidden Path Finder"
]


def gen_player_achievements() -> set[str]:
    num = random.randint(5, 10)
    selected = random.sample(ACHIEVEMENTS, num)
    return set(selected)


if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    alice: set[str] = gen_player_achievements()
    bob: set[str] = gen_player_achievements()
    charlie: set[str] = gen_player_achievements()
    dylan: set[str] = gen_player_achievements()

    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}")

    all_distinct = alice.union(bob, charlie, dylan)
    print(f"\nAll distinct achievements: {all_distinct}")

    common = alice.intersection(bob, charlie, dylan)
    print(f"\nCommon achievements: '{common}'")

    print(f"\nOnly Alice has: {alice.difference(bob, charlie, dylan)}")
    print(f"Only Bob has: {bob.difference(alice, charlie, dylan)}")
    print(f"Only Charlie has: {charlie.difference(alice, bob, dylan)}")
    print(f"Only Dylas has: {dylan.difference(alice, bob, charlie)}")

    print(f"\nAlice is missing: {all_distinct.difference(alice)}")
    print(f"Bob is missing: {all_distinct.difference(bob)}")
    print(f"Charlie is missing: {all_distinct.difference(charlie)}")
    print(f"Dylan is missing: {all_distinct.difference(dylan)}")
