from io import UnsupportedOperation

import src.lab14.ver2.test.conftest

import pytest


def test_hyena(hyena, many_plant_food):
    satiety_before = hyena.satiety
    food = next(many_plant_food)
    hyena.eat(food)

    assert hyena.satiety > satiety_before
    assert not food.edible()
    satiety_before = hyena.satiety
    hyena.eat(food)
    assert hyena.satiety == satiety_before

    while not hyena.is_satisfied():
        food = next(many_plant_food)
        hyena.eat(food)

    assert hyena.scratch() == "Копаем-копаем!!!"
    while hyena.is_satisfied():
        hyena.scratch()

    assert hyena.scratch() == "Ой устал :("

    with pytest.raises(UnsupportedOperation):
        hyena.roar()
