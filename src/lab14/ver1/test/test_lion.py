import src.lab14.ver1.test.conftest

import pytest


def test_lion(dingodog, many_plant_food):
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

    assert dingodog.roar() == "Слишком лень!"
    while dingodog.is_satisfied():
        dingodog.roar()

    assert dingodog.roar() == "Рррры!"

    while not dingodog.is_satisfied():
        food = next(many_plant_food)
        dingodog.eat(food)

    assert dingodog.scratch() == "Ккрырырыы"
    while dingodog.is_satisfied():
        dingodog.scratch()

    assert dingodog.scratch() == "Я слишком голоден для этого!"
