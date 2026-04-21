
from collections.abc import Callable
from typing import Any


def mage_counter() -> Callable:
    count = 0

    def counter() -> int:
        nonlocal count
        count += 1
        return count
    return counter


def spell_accumulator(initial_power: int) -> Callable:
    total_power: int = initial_power

    def accumulator(power: int) -> int:
        nonlocal total_power
        total_power += power
        return total_power
    return accumulator


def enchantment_factory(enchantment_type: str) -> Callable:

    def enchantment(item: str) -> str:
        return f"{enchantment_type} {item}"
    return enchantment


def memory_vault() -> dict[str, Callable]:
    vault_data: dict[str, Any] = {}

    def store(key: str, value: Any) -> None:
        vault_data[key] = value

    def recall(key: str) -> str:
        return vault_data.get(key, "Memory not found")

    return {
        "store": store,
        "recall": recall
    }


if __name__ == "__main__":
    print("Testing mage counter...")
    test_a = mage_counter()
    print(f"counter_a call 1: {test_a()}")
    print(f"counter_a call 2: {test_a()}")
    test_b = mage_counter()
    print(f"counter_b call 1: {test_b()}")

    print("\n---Acumulator---")
    pool = spell_accumulator(100)
    print(pool(50))
    print(pool(100))

    print("\n---Factory---")
    fire = enchantment_factory("Flaming")
    print(fire("Sword"))

    print("\n---Memory Manager---")
    vault = memory_vault()
    vault['store']("password", "secret text")
    print(f"Test 1: {vault['recall']("password")}")
    print(f"Test 2: {vault['recall']("not_found")}")
