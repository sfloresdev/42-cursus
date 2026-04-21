
from typing import Callable, Any
import functools
import operator


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    ops = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": lambda x, y: max(x, y),
        "min": lambda x, y: min(x, y),
    }
    op_func = ops.get(operation)
    if not op_func:
        raise ValueError(f"Unknown operation/not supported: {operation}")
    return functools.reduce(op_func, spells)


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:

    fire_spell = functools.partial(base_enchantment, 50, "fire")
    ice_spell = functools.partial(base_enchantment, 50, "ice")
    wind_spell = functools.partial(base_enchantment, 50, "wind")

    return {
        "fire": fire_spell,
        "ice": ice_spell,
        "wind": wind_spell
    }


@functools.lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @functools.singledispatch
    def dispatcher(spell_data: Any) -> str:
        return "Unknown spell type"

    @dispatcher.register
    def _(spell_data: int) -> str:
        return f"Damage spell: {spell_data} damage"

    @dispatcher.register
    def _(spell_data: str) -> str:
        return f"Enchantment: {spell_data}"

    @dispatcher.register
    def _(spell_data: list) -> str:
        return f"Multi-cast: {len(spell_data)} spells"
    return dispatcher


if __name__ == "__main__":

    print("Testing spell reducer...")
    spell_powers = [46, 19, 48, 33, 12, 25]
    n = spell_reducer(spell_powers, 'add')
    n2 = spell_reducer(spell_powers, 'multiply')
    n3 = spell_reducer(spell_powers, 'max')
    print(n)
    print(n2)
    print(n3)

    print("\nTesting Partial Enchanter")

    def casting_formula(power: int, element: str, target: str) -> str:
        return f"Casting {element} spell: {power} on {target}"

    enchanters = partial_enchanter(casting_formula)
    print(enchanters['fire']("sergio"))
    print(enchanters['ice']("sergio"))

    print("\nTesting Fibonacci")
    print(f"F(10) {memoized_fibonacci(10)}")
    info = memoized_fibonacci.cache_info()
    print(f"Hits: {info.hits}")
    print(f"Misses: {info.misses}")

    print(f"F(10) {memoized_fibonacci(10)}")
    print(f"Hits: {memoized_fibonacci.cache_info().hits}")

    cast = spell_dispatcher()
    print(cast(42))
    print(cast("Fireball"))
    print(cast([1, 2, 3]))
    print(cast(3.1415))
