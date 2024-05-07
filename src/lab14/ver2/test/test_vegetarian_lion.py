import src.lab14.ver2.test.conftest

import pytest


def test_lion(vegetarian_lion, many_plant_food, meat_food):
    satiety_before = vegetarian_lion.satiety
    food = next(many_plant_food)
    vegetarian_lion.eat(food)

    assert vegetarian_lion.satiety > satiety_before
    assert not food.edible()
    satiety_before = vegetarian_lion.satiety
    vegetarian_lion.eat(food)
    assert vegetarian_lion.satiety == satiety_before

    while not vegetarian_lion.is_satisfied():
        food = next(many_plant_food)
        vegetarian_lion.eat(food)

    assert vegetarian_lion.roar() == "Слишком лень!"
    while vegetarian_lion.is_satisfied():
        vegetarian_lion.roar()

    assert vegetarian_lion.roar() == "Рррры!"

    while not vegetarian_lion.is_satisfied():
        food = next(many_plant_food)
        vegetarian_lion.eat(food)

    assert vegetarian_lion.scratch() == "Ккрырырыы"
    while vegetarian_lion.is_satisfied():
        vegetarian_lion.scratch()

    assert vegetarian_lion.scratch() == "Я слишком голоден для этого!"

    while vegetarian_lion.satiety != 0:
        vegetarian_lion.roar()

    vegetarian_lion.eat(meat_food)
    assert vegetarian_lion.satiety == 0
    assert meat_food.edible()
