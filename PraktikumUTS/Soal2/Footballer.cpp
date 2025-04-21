#include "Footballer.hpp"

// Default cosntructor set nilai attribut sebagai berikut:
// name = "noname"; birthYear = 2000; playPosition = "none";
// nationality = "Indonesia"; height = 180, weight = 70
Footballer::Footballer(){
    name = "noname";
    birthYear = 2000;
    playPosition = "none";
    nationality = "Indonesia";
    height = 180;
    weight = 70;
}

// User-defined constructor:
// set nilai atribut berdasarkan nilai parameter masukan
// dengan urutan: name, birthYear, playPosition, nationality, height, weight
Footballer::Footballer(string n, int by, string pp, string nat, int h, int w){
    name = n;
    birthYear = by;
    playPosition = pp;
    nationality = nat;
    height = h;
    weight = w;
}
// Copy constructor
// ...
Footballer::Footballer(const Footballer &f){
    name = f.name;
    birthYear = f.birthYear;
    playPosition = f.playPosition;
    nationality = f.nationality;
    height = f.height;
    weight = f.weight;
}

// Destructor
// ...
Footballer::~Footballer(){}

// Operator assignment
// ...
Footballer& Footballer::operator=(const Footballer &other){
    name = other.name;
    birthYear = other.birthYear;
    playPosition = other.playPosition;
    nationality = other.nationality;
    height = other.height;
    weight = other.weight;

    return *this;
}

// Getter dan setter name
// setName(...)
// getName()
void Footballer::setName(string n){
    name = n;
}
string Footballer::getName(){
    return name;
}

// Getter dan setter playPosition
// setPlayPosition(...)
// getPlayPosition()
void Footballer::setPlayPosition(string pp){
    playPosition = pp;
}
string Footballer::getPlayPosition(){
    return playPosition;
}

// Getter dan setter nationality
// setNationality(...)
// getNationality()
void Footballer::setNationality(string nat){
    nationality = nat;
}
string Footballer::getNationality(){
    return nationality;
}

// Getter dan setter height and weight
// setHeight(...)
// getHeight()
// setWeight(...)
// getWeight()
void Footballer::setHeight(int h){
    height = h;
}
int Footballer::getHeight(){
    return height;
}
void Footballer::setWeight(int w){
    weight = w;
}
int Footballer::getWeight(){
    return weight;
}

// gunakan CURRENT_YEAR untuk menghitung umur
// getAge()
int Footballer::getAge(){
    return CURRENT_YEAR - birthYear;
}

// gunakan height and weight untuk menghitung BMI
// BMI = weight(kg) / (height(m))²
// getBMI()
double Footballer::getBMI(){
    double mHeight = height / 100.0;
    return weight / (mHeight * mHeight);
}

// gunakan BMI untuk mendapat category
// BMI < 18.5         -> Underweight
// 18.5 ≤ BMI < 25.0  -> Normal
// 25.0 ≤ BMI < 30.0  -> Overweight
// BMI ≥ 30.0         -> Obese
// getCategory() -> string
string Footballer::getCategory(){
    double b = getBMI();
    if (b < 18.5){
        return "Underweight";
    } else if (b >= 18.5 && b < 25){
        return "Normal";
    } else if (b >= 25 && b < 30){
        return "Overweight";
    } else {
        return "Obese";
    }
}

// Mencetak informasi footballer dengan format sebagai berikut:
// Name: {name}
// Age: {hasil pemanggilan getAge()}
// Position: {playPosition}
// Nationality: {nationality}
// BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
// Transfer Rate: {hasil pemanggilan transferRate()}
// displayInfo()
void Footballer::displayInfo(){
    cout << "Name: " << name << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Position: " << playPosition << endl;
    cout << "Nationality: " << nationality << endl;
    cout << "BMI: " << fixed << setprecision(2) << getBMI() << " (" << getCategory() << ")" << endl;
    cout << "Transfer Rate: " << transferRate() << endl; 
}

// Melakukan kalkulasi nilai transfer sesuai umur, playPosition, dan getCategory()
// transferRate() akan diimplementasikan oleh kelas anak Footballer
// yang ada di soal berikutnya. Gunakan tipe data integer.
// ... transferRate()