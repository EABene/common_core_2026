
def main() -> None:
    class Plant:
        def __init__(self, name: str, height: int, age: int):
            self.name = name
            self.height = height
            self.age = age

        def show(self) -> None:
            print(f"{self.name}: {self.height}cm, {self.age} days old")

    plant1 = Plant("Tomato", "30", "4")
    plant2 = Plant("Lettuce", "4", "40")
    plant3 = Plant("Carrot", "8", "1")

    plant1.show()
    plant2.show()
    plant3.show()


if __name__ == "__main__":
    main()
