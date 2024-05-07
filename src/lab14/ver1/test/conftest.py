from src.lab14.ver1.core.main import Food, Lion, Zoo

import pytest


@pytest.fixture(scope='function')
def food():
    return Food()


@pytest.fixture(scope='session')
def many_plant_food():
    return (Food() for x in range(0, 999999999))


@pytest.fixture(scope='function')
def dingodog():
    return Lion()


@pytest.fixture(scope='session')
def many_lions():
    return (Lion() for x in range(0, 999999999))


@pytest.fixture(scope='function')
def empty_zoo():
    return Zoo([])


@pytest.fixture(scope='function')
def filled_zoo(many_lions):
    return Zoo([next(many_lions) for _ in range(0, 5)])
