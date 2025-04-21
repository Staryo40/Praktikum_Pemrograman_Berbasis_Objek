#include "Defender.hpp"

// Default constructor
// set atribut Footballer dengan nilai default,
// set tackleSuccess dan interceptions ke 0, dan playPosition ke "defender"
// ...
Defender::Defender(): Footballer(){
    tackleSuccess = 0;
    interceptions = 0;
    playPosition = "defender";
}

// User-defined constructor
// parameter: string name, int birthYear, int tackleSuccess, int interceptions
// set atribut dengan nilai parameter, playPosition tetap "defender"
// nationality, height, dan weight gunakan nilai default superclass
// ...
Defender::Defender(string n, int by, int ts, int i): Footballer(n, by, "defender", "Indonesia", 180, 70){
    tackleSuccess = ts;
    interceptions = i;
}

// Getter dan Setter untuk tackleSuccess
// setTackleSuccess(...)
// getTackleSuccess()
void Defender::setTackleSuccess(int ts){
    tackleSuccess = ts;
}
int Defender::getTackleSuccess(){
    return tackleSuccess;
}

// Getter dan Setter untuk interceptions
// setInterceptions(...)
// getInterceptions()
void Defender::setInterceptions(int i){
    interceptions = i;
}
int Defender::getInterceptions(){
    return interceptions;
}

// Method tambahan: defensiveRating
// rumus: (tackleSuccess * 2) + interceptions
// return dalam bentuk int
// ...
int Defender::defensiveRating(){
    return (tackleSuccess * 2) + interceptions;
}

// Override transferRate:
// rumus: (600.000 * tackleSuccess) + (400.000 * interceptions)
// hasil berupa int
// ...
int Defender::transferRate(){
    return (600000 * tackleSuccess) + (400000 * interceptions);
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan defender (tackleSuccess, interceptions, defensiveRating)
// Format:
// Tackle Success: <tackleSuccess>
// Interceptions: <interceptions>
// Defensive Rating: <defensiveRating>
// ...
void Defender::displayInfo(){
    Footballer::displayInfo();
    cout << "Tackle Success: " << tackleSuccess << endl;
    cout << "Interceptions: " << interceptions << endl;
    cout << "Defensive Rating: " << defensiveRating() << endl;
}