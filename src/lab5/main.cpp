#include <iostream>
#include <windows.h>

#include "../libs/alg/goods/goods.h"

int main() {
    Shop shop;
    shop.addGoods(new Product("Monitor", 10000, Date(5, 3, 2024), boost::gregorian::days(3000)));
    shop.addGoods(new Shipment("Sneakers", 3000, 150, Date(3, 3, 2023), boost::gregorian::days(3000)));
    shop.addGoods(new Package("Vegetrables", 10313,
                           {Product("Tomatoes", 100, Date(5, 3, 2024), boost::gregorian::days(45)),
                            Product("Cucumber", 100, Date(5, 3, 2024), boost::gregorian::days(45)),
                            Product("Salad", 300, Date(5, 3, 2024), boost::gregorian::days(45))}));
    shop.addGoods(new Product("Tomatoes", 100, Date(5, 3, 2024), boost::gregorian::days(0)));

    shop.print(std::cout);
}
