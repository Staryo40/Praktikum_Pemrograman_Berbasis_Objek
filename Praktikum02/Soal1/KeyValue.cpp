#include <iostream>
#include <string>
using namespace std;

int const CAPACITY = 10;

template<class T1, class T2>
class KeyValue {
    protected:
        T1* keys[CAPACITY];
        T2* values[CAPACITY];
        int currentCount = 0;

    public:
        ~KeyValue(){
            for (int i = 0; i < currentCount; i++){
                delete keys[i];
                delete values[i];
            }
        }

        void set(T1 key, T2 value) {
            if (currentCount == CAPACITY) {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
                return;
            }

            for (int i = 0; i < currentCount; i++) {
                if (*keys[i] == key) {
                    *values[i] = value;
                    return;
                }
            }

            keys[currentCount] = new T1(key);
            values[currentCount] = new T2(value);
            currentCount++;
        }

        void display(T1 key) {
            for (int i = 0; i < currentCount; i++) {
                if (*keys[i] == key) {
                    cout << *values[i] << endl;
                    return;
                }
            }
            cout << "Key tidak ditemukan!" << endl;
        }
};

template<class T2>
class KeyValue<double, T2> {
    protected:
        double* keys[CAPACITY];
        T2* values[CAPACITY];
        int currentCount = 0;

    public:
        ~KeyValue(){
            for (int i = 0; i < currentCount; i++){
                delete keys[i];
                delete values[i];
            }
        }

        void set(double key, T2 value) {
            if (currentCount == CAPACITY) {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
                return;
            }

            for (int i = 0; i < currentCount; i++) {
                double diff = *keys[i] - key;
                bool exists = false;
                if (diff < 0){
                    diff = -diff;
                }

                if (diff < 0.01){
                    exists = true;
                }

                if (exists) {
                    *values[i] = value;
                    return;
                }
            }

            keys[currentCount] = new double(key);
            values[currentCount] = new T2(value);
            currentCount++;
        }
        
        void display(double key) {
            for (int i = 0; i < currentCount; i++) {
                double diff = *keys[i] - key;
                bool exists = false;
                if (diff < 0){
                    diff = -diff;
                }

                if (diff < 0.01){
                    exists = true;
                }

                if (exists) {
                    cout << *values[i] << endl;
                    return;
                }
            }
            cout << "Key tidak ditemukan!" << endl;
        }
};

