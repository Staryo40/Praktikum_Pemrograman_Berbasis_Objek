#include <iostream>
using namespace std;

template<class T>
void func(T p, T q){
    cout << "Masukan Anda: " << p << " dan " << q << ", memiliki tipe yang sama" << endl;
}

template<class T1, class T2>
void func(T1 p, T2 q){
    cout << "Masukan Anda: " << p << " dan " << q << ", mungkin memiliki tipe yang berbeda" << endl;
}

template<>
void func(char c, int x){
    for (int i = 0; i < x; i++){
        cout << c << endl;
    }
}
