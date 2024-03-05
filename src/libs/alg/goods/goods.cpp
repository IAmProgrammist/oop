#include "goods.h"

bool Product::isExpired() {
    boost::gregorian::date current_date(boost::gregorian::day_clock::local_day());
    Date now(current_date);
    Date exDate = Date(this->production_date.getData() + this->expires_in);
    return now >= exDate;
}

std::ostream& Product::print(std::ostream& out) {
    out << "Name: " << this->name << "\n";
    out << "Price: " << this->price << "\n";
    out << "Production date: " << this->production_date.getData() << "\n";
    out << "Expires at: " << this->production_date.getData() + this->expires_in << "\n";
    out << "Expired: " << (this->isExpired() ? "yup" : "nuh uh") << "\n";

    return out;
}

bool Shipment::isExpired() {
    boost::gregorian::date current_date(boost::gregorian::day_clock::local_day());
    Date now(current_date);
    Date exDate = Date(this->production_date.getData() + this->expires_in);
    return now >= exDate;
}

std::ostream& Shipment::print(std::ostream& out) {
    out << "Name: " << this->name << "\n";
    out << "Price: " << this->price << "\n";
    out << "Amount: " << this->amount << "\n";
    out << "Production date: " << this->production_date.getData() << "\n";
    out << "Expires at: " << this->production_date.getData() + this->expires_in << "\n";
    out << "Expired: " << (this->isExpired() ? "yup" : "nuh uh") << "\n";

    return out;
}

bool Package::isExpired() {
    for (auto& good : this->products)
        if (good.isExpired()) return true;

    return false;
}

std::ostream& Package::print(std::ostream& out) {
    out << "Name: " << this->name << "\n";
    out << "Price: " << this->price << "\n";
    out << "Products:\n";
    out << "=============\n";
    for (auto& prod : this->products) {
        prod.print(out);
    }
    out << "=============\n";

    return out;
}

bool Base::containsGoods(Goods* goods) {
    return std::find(this->goods.begin(), this->goods.end(), goods) != this->goods.end();
}

void Base::addGoods(Goods* goods) {
    if (!containsGoods(goods))
        this->goods.push_back(goods);
}

std::ostream& Base::print(std::ostream& out) {
    std::cout << "*************\n";

    for (auto & good : this->goods) {
        good->print(out);
        std::cout << "*************\n";
    }

    return out;
}

std::vector<Goods*> Base::getExpired() {
    std::vector<Goods*> result;
    for (auto & good : this->goods)
        if (good->isExpired())
            result.push_back(good);

    return result;
}

void Shop::addGoods(Goods* goods) {
    this->base.addGoods(goods);
}

void Shop::addGoodToCart(Goods* good) {
    if (this->base.containsGoods(good))
        this->cart.push_back(good);
}

std::ostream& Shop::print(std::ostream& out) {
    std::cout << "Catalog: \n";
    this->base.print(std::cout);
    std::cout << "Cart: \n";

    std::cout << "*************\n";

    for (auto & good : this->cart) {
        good->print(out);
        std::cout << "*************\n";
    }

    return out;
}

std::vector<Goods*> Shop::getExpired() {
    return this->base.getExpired();
}
