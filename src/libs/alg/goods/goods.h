#pragma once

#include "../date/date.h"

class Goods {
public:
    virtual bool isExpired() = 0;

    virtual std::ostream& print(std::ostream& out) = 0;
};

class Product : public Goods {
    std::string name;
    int price;
    Date production_date;
    boost::gregorian::date_duration expires_in;
public:
    Product(std::string name,
            int price,
            Date production_date,
            boost::gregorian::date_duration expirates_in) :
        name(name), price(price), production_date(production_date), expires_in(expirates_in) {};

    virtual bool isExpired() override;
    virtual std::ostream& print(std::ostream& out) override;
};

class Shipment : public Goods {
    std::string name;
    int price;
    int amount;
    Date production_date;
    boost::gregorian::date_duration expires_in;
public:
    Shipment(std::string name,
            int price,
            int amount,
            Date production_date,
            boost::gregorian::date_duration expirates_in) :
        name(name), price(price), amount(amount), production_date(production_date), expires_in(expirates_in) {};

    virtual bool isExpired() override;
    virtual std::ostream& print(std::ostream& out) override;
};

class Package : public Goods {
    std::string name;
    int price;
    std::vector<Product> products;
public:
    Package(std::string name,
             int price,
             std::vector<Product> products) :
        name(name), price(price), products(products) {};

    virtual bool isExpired() override;
    virtual std::ostream& print(std::ostream& out) override;
};

class Base {
    std::vector<Goods*> goods;
public:
    bool containsGoods(Goods* goods);
    void addGoods(Goods* goods);
    std::ostream& print(std::ostream& out);
    std::vector<Goods*> getExpired();
};

class Shop {
    Base base;
    std::vector<Goods*> cart;
public:
    void addGoods(Goods* goods);
    void addGoodToCart(Goods* good);
    std::ostream& print(std::ostream& out);
    std::vector<Goods*> getExpired();
};
