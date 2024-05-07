import src.lab14.ver1.test.conftest

import pytest


def test_food(food):
    assert food.edible()
    food.eat()
    assert not food.edible()
