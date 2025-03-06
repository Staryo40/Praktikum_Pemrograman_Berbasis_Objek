#include "BigNumber.hpp"
#include <iostream>
using namespace std;

void printBigNumber(const BigNumber& bn) {
    int msi = 19;
    for (int i = 19; i >= 0; i--){
        if (bn[i] != 0){
            msi = i;
            break;
        }
    }

    for (int i = msi; i >= 0; i--) {
        std::cout << bn[i];  // Print each digit (you can implement the `operator[]` as required)
    }
    std::cout << std::endl;
}

int main(){
    BigNumber b(52435);
    BigNumber d(52346);
    BigNumber sum = b + d;

    printBigNumber(b);
    printBigNumber(d);
    printBigNumber(sum);

    cout << (b < d) << endl;

    return 0;
}