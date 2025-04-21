#include "Kompleks.hpp"

Kompleks::Kompleks(){ // Nilai default 0 + 0i
    real = 0;
    imag = 0;
}              
Kompleks::Kompleks(double r, double i)  // r + i*i
{
    real = r;
    imag = i;
}
Kompleks::Kompleks(const Kompleks& other){
    real = other.real;
    imag = other.imag;
}

double Kompleks::getReal() const{
    return real;
}
double Kompleks::getImag() const{
    return imag;
}

double Kompleks::setReal(double r){
    real = r;
    return r;
}

double Kompleks::setImag(double i){
    imag = i;
    return i;
}

Kompleks Kompleks::operator+(const Kompleks& other) const{
    return Kompleks(real+other.real, imag+other.imag);
}
// Menambahkan dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a + b = (1+3) + (2+4)i = 4 + 6i

Kompleks Kompleks::operator-(const Kompleks& other) const {
    return Kompleks(real-other.real, imag-other.imag);
}
// Mengurangi dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a - b = (1-3) + (2-4)i = -2 - 2i

Kompleks Kompleks::operator*(const Kompleks& other) const {
    double newReal = real * other.real - imag * other.imag;
    double newImag = real * other.imag + imag * other.real;
    return Kompleks(newReal, newImag);
}
// Mengalikan dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a * b = 1*3 + 1*4i + 2i*3 + 2i*4i = 3 + 4i + 6i - 8 = -5 + 10i

bool Kompleks::operator==(const Kompleks& other) const{
    return (real == other.real) && (imag == other.imag);
}
// Membandingkan dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a == b = (1==3) && (2==4) = false
// Misal: a = 1 + 2i, b = 1 + 2i;
// a == b = (1==1) && (2==2) = true

Kompleks& Kompleks::operator=(const Kompleks& other){
    this->imag = other.imag;
    this->real = other.real;
    return *this;
}
// Menyalin dua bilangan kompleks

ostream& operator<<(ostream& os, const Kompleks& c){
    if (c.imag < 0){
        os << c.real << " - " << -c.imag << "i"; 
    } else if (c.imag > 0){
        os << c.real << " + " << c.imag << "i"; 
    } else {
        os << c.real; 
    }
    return os;
}
// Menampilkan bilangan kompleks
// Note: Tidak menggunakan endl
// Misal: Kompleks(1, 2)
// cout << a << endl; // Output: 1 + 2i
// Jika imajiner < 0; Misal: Kompleks(1, -2)
// cout << a << endl; // Output: 1 - 2i
// Jika nilai imajiner 0, jangan tampilkan i; Misal: Kompleks(1, 0)
// cout << a << endl; // Output: 1