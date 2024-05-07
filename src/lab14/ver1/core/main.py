from typing import List


class Food:
    def __init__(self):
        self.__edible = True

    def eat(self):
        self.__edible = False

    def edible(self):
        return self.__edible


class Lion:
    def __init__(self):
        self.satiety = 5

    def roar(self):
        result = "Слишком лень!" if self.is_satisfied() else "Рррры!"
        self.satiety -= 1
        return result

    def eat(self, food: Food):
        if food.edible():
            food.eat()
            self.satiety += 1

    def scratch(self):
        result = "Ккрырырыы" if self.is_satisfied() else "Я слишком голоден для этого!"
        self.satiety -= 1
        return result

    @property
    def satiety(self):
        return self.__satiety

    @satiety.setter
    def satiety(self, value):
        if value > 10:
            self.__satiety = 10
        elif value < 0:
            self.__satiety = 0
        else:
            self.__satiety = value

    def is_satisfied(self):
        return self.satiety >= 5


class Zoo:
    def __init__(self, animals: List[Lion]):
        self.__animals = animals

    def add_animal(self, animal: Lion):
        self.__animals.append(animal)

    def set_animal(self, index: int, animal: Lion):
        self.__animals[index] = animal

    def remove_animal(self, index: int):
        self.__animals.pop(index)

    def get_animals(self):
        return tuple(self.__animals)


if __name__ == "__main__":
    pass