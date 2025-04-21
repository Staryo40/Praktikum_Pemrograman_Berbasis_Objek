#include "Midfielder.hpp"

// Default constructor
// set atribut Footballer dengan nilai default,
// set assist dan keyPasses ke 0, dan playPosition ke "midfielder"
// ...
Midfielder::Midfielder(): Footballer(){
    keyPasses = 0;
    assist = 0;
    playPosition = "midfielder";
}

// User-defined constructor
// parameter: string name, int birthYear, int assist, int keyPasses
// set atribut dengan nilai parameter, playPosition tetap "midfielder"
// nationality, height, dan weight gunakan nilai default superclass
// ...
Midfielder::Midfielder(string n, int by, int as, int kp): Footballer(n, by, "midfielder", "Indonesia", 180, 70) {
    keyPasses = kp;
    assist = as;
}

// Getter dan Setter untuk assist
// setAssist(...)
// getAssist()
void Midfielder::setAssist(int as){
    assist = as;
}
int Midfielder::getAssist(){
    return assist;
}

// Getter dan Setter untuk keyPasses
// setKeyPasses(...)
// getKeyPasses()
void Midfielder::setKeyPasses(int kp){
    keyPasses = kp;
}
int Midfielder::getKeyPasses(){
    return keyPasses;
}

// Method tambahan: menghitung playmakerRating
// rumus: (assist * 3) + keyPasses
// return dalam bentuk int
// ...
int Midfielder::playmakerRating(){
    return (assist * 3) + keyPasses;
}

// Override transferRate:
// rumus: (800.000 * assist) + (30.000 * keyPasses)
// hasil berupa int
// ...
int Midfielder::transferRate(){
    return (800000 * assist) + (30000 * keyPasses);
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan midfielder (assist, keyPasses, playmakerRating)
// Format:
// Assists: <assist>
// Key Passes: <keyPasses>
// Playmaker Rating: <playmakerRating>
void Midfielder::displayInfo(){
    Footballer::displayInfo();
    cout << "Assists: " << assist << endl;
    cout << "Key Passes: " << keyPasses << endl;
    cout << "Playmaker Rating: " << playmakerRating() << endl;
}