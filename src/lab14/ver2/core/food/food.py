from abc import ABC


class Food(ABC):
    def __init__(self):
        self.__edible = True

    def eat(self):
        self.__edible = False

    def edible(self):
        return self.__edible


class Meat(Food):
    pass


class Plant(Food):
    pass
