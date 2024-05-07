from io import UnsupportedOperation

import src.lab14.ver2.test.conftest

import pytest


def test_dingo_dog(dingodog, many_plant_food):
    satiety_before = dingodog.satiety
    food = next(many_plant_food)
    dingodog.eat(food)

    assert dingodog.satiety > satiety_before
    assert not food.edible()
    satiety_before = dingodog.satiety
    dingodog.eat(food)
    assert dingodog.satiety == satiety_before

    while not dingodog.is_satisfied():
        food = next(many_plant_food)
        dingodog.eat(food)

    assert dingodog.roar() == "Тяф)"
    while dingodog.is_satisfied():
        dingodog.roar()

    assert dingodog.roar() == "Гав гав гав!!!"

    while not dingodog.is_satisfied():
        food = next(many_plant_food)
        dingodog.eat(food)

    with pytest.raises(UnsupportedOperation):
        dingodog.scratch()