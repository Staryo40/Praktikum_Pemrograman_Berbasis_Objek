#include "Weed.hpp"
#include <iostream>
using namespace std;

Weed::Weed():many(1){}
Weed::Weed(int n){
    if (n > 1000){
        many = 1000;
    } else {
        many = n;
    }
}; 
Weed::Weed(const Weed& b){
    many = b.many;
}
Weed::~Weed(){}

void Weed::step(){
    for(int i = 0; i < many; i++){
        cout << "kresek...";
    }
    cout << endl;
}  