import src.lab14.ver2.test.conftest

import pytest


def test_lion(lion, many_plant_food):
    satiety_before = lion.satiety
    food = next(many_plant_food)
    lion.eat(food)

    assert lion.satiety > satiety_before
    assert not food.edible()
    satiety_before = lion.satiety
    lion.eat(food)
    assert lion.satiety == satiety_before

    while not lion.is_satisfied():
        food = next(many_plant_food)
        lion.eat(food)

    assert lion.roar() == "Слишком лень!"
    while lion.is_satisfied():
        lion.roar()

    assert lion.roar() == "Рррры!"

    while not lion.is_satisfied():
        food = next(many_plant_food)
        lion.eat(food)

    assert lion.scratch() == "Ккрырырыы"
    while lion.is_satisfied():
        lion.scratch()

    assert lion.scratch() == "Я слишком голоден для этого!"
