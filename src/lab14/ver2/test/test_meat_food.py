import src.lab14.ver2.test.conftest

import pytest


def test_food(meat_food):
    assert meat_food.edible()
    meat_food.eat()
    assert not meat_food.edible()
