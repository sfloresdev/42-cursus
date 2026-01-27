class Plant:
    def __init__(self, name: str, height: int, age):
        self.name = name
        self.init_height = height
        self.init_age = age

    def get_info(self):
        return f"{self.name} ({self.height}cm | {self.age} days)"


print("=== Plant Factory Output ===")
p1 = Plant("Rose", 25, 30)
print(f"Created: {p1.get_info()}")
p2 = Plant("Oak", 200, 365)
print(f"Created: {p2.get_info()}")
p3 = Plant("Rose", 5, 90)
print(f"Created: {p3.get_info()}")
p4 = Plant("Sunflower", 80, 45)
print(f"Created: {p4.get_info()}")
p5 = Plant("Fern", 15, 120)
print(f"Created: {p5.get_info()}")
