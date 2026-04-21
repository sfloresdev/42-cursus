
from collections.abc import Callable


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combined_spell(target: str, power: int) -> tuple[str, str]:
        result1 = spell1(target, power)
        result2 = spell2(target, power)
        return (result1, result2)
    return combined_spell


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplified_spell(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)
    return amplified_spell


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def conditional_spell(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"
    return conditional_spell


def spell_sequence(spells: list[Callable]) -> Callable:
    def sequence_spell(target: str, power: int) -> list[str]:
        results = [spell(target, power) for spell in spells]
        return results
    return sequence_spell


if __name__ == "__main__":
    def fireball(target: str, power: int) -> str:
        return f"Fireball hits {target} for {power} damage"

    def heal(target: str, power: int) -> str:
        return f"Heal restores {power} HP to {target}"

    combined = spell_combiner(fireball, heal)
    print(combined("Dragon", 50))

    # 1
    mega_fireball = power_amplifier(fireball, 2)
    print(f"\nOriginal {fireball('Sergio', 2)}")
    print(f"Original {mega_fireball('Sergio', 2)}")

    # 2
    def is_strong(target: str, power: int) -> bool:
        return power > 50

    check_fireball = conditional_caster(is_strong, fireball)
    print("\n" + check_fireball("Sergio", 30))
    print(check_fireball("Sergio", 51))

    # 3
    def fireball2(target: str, power: int) -> str:
        return f"Fireball hits {power} damage to {target}"

    def weak(target: str, power: int) -> str:
        return f"{target} is weakened by {power} points"

    def shock(target: str, power: int) -> str:
        return f"{target} gets shocked for {power} secods"

    combo_attack = spell_sequence([fireball2, weak, shock])
    results = combo_attack("Sergio", 75)
    for i in results:
        print(f"- {i}")
