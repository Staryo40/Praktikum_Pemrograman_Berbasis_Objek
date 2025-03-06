#include "Item.hpp"
#include <iostream>
using namespace std;

int main(){
    Item i1;
    Item i2(10, 10);
    cout << "i1 serial number = " << i1.getSerialNum() << endl;
    cout << "i2 serial number = " << i2.getSerialNum() << endl;

    cout << "i1 price = " << i1.getPrice() << endl;
    cout << "i1 sold = " << i1.getSold() << endl;
    cout << "i2 price = " << i2.getPrice() << endl;
    cout << "i2 sold = " << i2.getSold() << endl;
    cout << "i2 revenue = " << i2.totalRevenue << endl;

    Item i3(i2);
    cout << "i3 price = " << i3.getPrice() << endl;
    cout << "i3 sold = " << i3.getSold() << endl;

    i2.sell(3);
    cout << "i2 price = " << i2.getPrice() << endl;
    cout << "i2 sold = " << i2.getSold() << endl;
    cout << "i2 revenue = " << i2.totalRevenue << endl;
    return 0;
}