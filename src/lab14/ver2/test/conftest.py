import pytest
import random

from src.lab14.ver2.core.animals.animals import Lion, LionVegetarian, DingoDog, Hyena
from src.lab14.ver2.core.food.food import Meat, Plant
from src.lab14.ver2.core.zoo.zoo import Zoo


@pytest.fixture(scope='function')
def meat_food():
    return Meat()


@pytest.fixture(scope='session')
def many_meat_food():
    return (Meat() for x in range(0, 999999999))


@pytest.fixture(scope='function')
def plant_food():
    return Plant()


@pytest.fixture(scope='session')
def many_plant_food():
    return (Plant() for x in range(0, 999999999))


@pytest.fixture(scope='session')
def many_food(many_meat_food, many_plant_food):
    return (random.randint(0, 1) == 0 and next(many_meat_food) or next(many_plant_food) for i in range(0, 999999999))


@pytest.fixture(scope='function')
def lion():
    return Lion()


@pytest.fixture(scope='function')
def dingodog():
    return DingoDog()


@pytest.fixture(scope='function')
def hyena():
    return Hyena()


@pytest.fixture(scope='function')
def vegetarian_lion():
    return LionVegetarian()


@pytest.fixture(scope='session')
def many_lions():
    return (Lion() for x in range(0, 999999999))


@pytest.fixture(scope='function')
def empty_zoo():
    return Zoo([])


@pytest.fixture(scope='function')
def filled_zoo(many_lions):
    return Zoo([next(many_lions) for _ in range(0, 5)])
