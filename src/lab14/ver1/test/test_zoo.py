import src.lab14.ver1.test.conftest

import pytest


def test_zoo(empty_zoo, filled_zoo, many_plant_food):
    zoo = filled_zoo

    lion = zoo.get_animals()[0]
    satiety_before = lion.satiety
    while lion.satiety == satiety_before:
        lion.eat(next(many_plant_food))

    satiety_after = lion.satiety
    assert zoo.get_animals()[0].satiety == satiety_after

    len_before = len(zoo.get_animals())
    zoo.remove_animal(0)
    assert len(zoo.get_animals()) == len_before - 1
    zoo.add_animal(lion)
    assert zoo.get_animals()[-1] == lion
