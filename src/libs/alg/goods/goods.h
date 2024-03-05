#pragma once

#include "../date/date.h"

class Goods {
    virtual bool is_expired();

    virtual std::ostream& print(std::ostream& out);
};

class Product : public Goods {
    std::string name;
    int price;
    Date production_date;
    boost::gregorian::date_duration expirates_in;
public:
    Product(std::string name,
            int price,
            Date production_date,
            boost::gregorian::date_duration expirates_in) :
        name(name), price(price), production_date(production_date), expirates_in(expirates_in) {};
};

class Shipment : public Goods {
    std::string name;
    int price;
    int amount;
    Date production_date;
    boost::gregorian::date_duration expirates_in;
public:
    Shipment(std::string name,
            int price,
            int amount,
            Date production_date,
            boost::gregorian::date_duration expirates_in) :
        name(name), price(price), amount(amount), production_date(production_date), expirates_in(expirates_in) {};
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
};

class Base {
    std::vector<Goods*> goods;
public:
    void add_goods(Goods* goods);
    std::ostream& print(std::ostream& out);
    std::vector<Goods*> get_expired();
};

class Account {
    std::vector<Goods*> shopping_cart;

    void add_goods(Goods* goods);
};

class Shop {
    Base base;
    Account account;
public:
    Shop(Base base, Account account) : base(base), account(account) {};

    void add_goods(Goods* goods);
};
