print("=== Kaboom 1 ===")
print("Access to alchemy/grimoire/dark_spellbook.py directly")
print("Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION")
try:
    from alchemy.grimoire.dark_spellbook import dark_spell_record
    dark_spell_record("Dark test", "Tomato, Potato, and Banana")
except ImportError as e:
    print(f"ImportError: {e}")
