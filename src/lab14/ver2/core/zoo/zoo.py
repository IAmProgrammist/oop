from typing import List

from src.lab14.ver2.core.animals.animals import Animal


class Zoo:
    def __init__(self, animals: List[Animal]):
        self.__animals = animals

    def add_animal(self, animal: Animal):
        self.__animals.append(animal)

    def set_animal(self, index: int, animal: Animal):
        self.__animals[index] = animal

    def remove_animal(self, index: int):
        self.__animals.pop(index)

    def get_animals(self):
        return tuple(self.__animals)
