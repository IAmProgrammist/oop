from abc import ABC
from io import UnsupportedOperation

from src.lab14.ver2.core.food.food import Food, Plant


class Animal(ABC):
    def __unsupported(*args, **kwargs):
        raise UnsupportedOperation('Method doesn\'t exists')

    def __init__(self, eat_func=__unsupported, scratch_func=__unsupported, roar_func=__unsupported, satiety_since=5, satiety_default=5):
        self.satiety = satiety_default
        self.satiety_since = satiety_since
        self.eat_func = eat_func
        self.scratch_func = scratch_func
        self.roar_func = roar_func

    def roar(self):
        return self.roar_func(self)

    def eat(self, food: Food):
        return self.eat_func(self, food)

    def scratch(self):
        return self.scratch_func(self)

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


class Lion(Animal):
    def __init__(self):
        super().__init__(roar_func=Lion.__roar_func, eat_func=Lion.__eat_func, scratch_func=Lion.__scratch_func,
                         satiety_default=5, satiety_since=5)

    def __roar_func(self):
        result = "Слишком лень!" if self.is_satisfied() else "Рррры!"
        self.satiety -= 1
        return result

    def __eat_func(self, food: Food):
        if food.edible():
            food.eat()
            self.satiety += 1

    def __scratch_func(self):
        result = "Ккрырырыы" if self.is_satisfied() else "Я слишком голоден для этого!"
        self.satiety -= 1
        return result


class LionVegetarian(Lion):
    def __init__(self):
        super().__init__()
        self.eat_func = LionVegetarian.__eat_func

    def __eat_func(self, food: Food):
        if food.edible() and isinstance(food, Plant):
            food.eat()
            self.satiety += 1


class DingoDog(Animal):
    def __init__(self):
        super().__init__(roar_func=DingoDog.__roar_func, eat_func=DingoDog.__eat_func,
                         satiety_default=5, satiety_since=3)

    def __roar_func(self):
        result = "Тяф)" if self.is_satisfied() else "Гав гав гав!!!"
        self.satiety -= 1
        return result

    def __eat_func(self, food: Food):
        if food.edible():
            food.eat()
            self.satiety += 1


class Hyena(Animal):
    def __init__(self):
        super().__init__(scratch_func=Hyena.__scratch_func, eat_func=Hyena.__eat_func,
                         satiety_default=5, satiety_since=2)

    def __scratch_func(self):
        result = "Копаем-копаем!!!" if self.is_satisfied() else "Ой устал :("
        self.satiety -= 1
        return result

    def __eat_func(self, food: Food):
        if food.edible():
            food.eat()
            self.satiety += 1
