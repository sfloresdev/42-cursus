
from typing import Callable
import functools
import time


def spell_timer(func: Callable) -> Callable:
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Casting {func.__name__}...")
        start_time = time.perf_counter()
        result = func(*args, **kwargs)
        end_time = time.perf_counter()
        print(f"Spell completed in {end_time - start_time:.3f} seconds")
        return result
    return wrapper


def power_validator(min_power: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            try:
                power = int(args[-1])
                if power >= min_power:
                    return func(*args, **kwargs)
            except (ValueError, TypeError, IndexError):
                pass
            return "Insufficient power for this spell"
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    print(
                        f"Spell failed, retrying..."
                        f"(attempt {attempt}/{max_attempts})"
                        )
                    time.sleep(0.5)
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) >= 3:
            if all(c.isalpha() or c.isspace() for c in name):
                return True
        return False

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


if __name__ == "__main__":
    print("Testing spell timer...")

    @spell_timer
    def fireball():
        time.sleep(0.2)
        return "Fireball cast!"

    print(f"Result {fireball()}")

    print("\nTesting retrying spell...")

    @retry_spell(3)
    def fail():
        raise Exception("Fail")
    print(f"{fail()}")

    print("\nTesting MageGuild...")
    guild = MageGuild()
    print(guild.validate_mage_name("Sergio   "))
    print(guild.validate_mage_name("Se"))

    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Fireball", 5))
