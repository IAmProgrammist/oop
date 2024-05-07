import src.lab14.ver2.test.conftest

import pytest


def test_plant_food(plant_food):
    assert plant_food.edible()
    plant_food.eat()
    assert not plant_food.edible()
