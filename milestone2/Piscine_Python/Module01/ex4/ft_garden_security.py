class SecurePlant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age

    def get_height(self):
        return self.height

    def get_age(self):
        return self.age

    def set_height(self, value):
        if value < 0:
            print(f"\nInvalid operation attempted: height {value} [REJECTED]")
            print("Security: Negative value")
            return
        self.height = value
        print(f"Height updated: {self.height}cm [OK]")

    def set_age(self, value):
        if value < 0:
            print(f"\nInvalid operation attempted: age {value} [REJECTED]")
            print("Security: Negative value")
            return
        self.age = value
        print(f"Age updated: {self.height} days [OK]")

    def get_info(self):
        return f"{self.name} ({self.height}cm | {self.age} days)"


print("=== Garden Security System ===")

p = SecurePlant("Rosa", 20, 20)
print(f"Plant created: {p.name}")

p.set_height(25)
p.set_age(30)

p.set_age(-45)
p.set_height(-67)

print(f"Current plant: {p.get_info()}")
