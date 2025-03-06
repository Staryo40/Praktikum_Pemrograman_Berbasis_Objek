#include "Item.hpp"
#include <iostream>
using namespace std;

int Item::totalItems = 0;
int Item::totalRevenue = 0;

Item::Item():
    serialNum(++totalItems),
    stock(0),
    price(0),
    sold(0){}

Item::Item(int stock, int price):
    serialNum(++totalItems), 
    stock(stock), 
    price(price), 
    sold(0){}

Item::Item(const Item& other):serialNum(++totalItems) {
    stock = other.stock;
    price = other.price;
    sold = other.sold;
}
Item::~Item() {}

int Item::getSerialNum() const {
    return serialNum;
}

int Item::getSold() const {
    return sold;
}

int Item::getPrice() const {
    return price;
}

void Item::addStock(int addedStock){
    stock += addedStock;
}

void Item::sell(int soldStock){
    int seld;
    if (soldStock > stock){
        seld = stock;
    } else {
        seld = soldStock;
    }
    stock -= seld;
    sold += seld;
    totalRevenue += seld * price;
}

void Item::setPrice(int newPrice){
    price = newPrice;
}


