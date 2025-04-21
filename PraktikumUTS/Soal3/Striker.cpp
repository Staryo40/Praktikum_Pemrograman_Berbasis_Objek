#include "Striker.hpp"

// Default constructor
// set atribut Footballer dengan nilai default,
// set goalScore dan shotsOnTarget ke 0, dan playPosition ke "striker"
// ...
Striker::Striker():Footballer(){
    playPosition = "striker";
    goalScore = 0;
    shotsOnTarget = 0;
}

// User-defined constructor
// parameter: string name, int birthYear, int goalScore, int shotsOnTarget
// set atribut dengan nilai parameter, playPosition tetap "striker"
// nationality, height, dan weight gunakan nilai default superclass
// ...
Striker::Striker(string n, int by, int gs, int sot): Footballer(n, by, "striker", "Indonesia", 180, 70){
    goalScore = gs;
    shotsOnTarget = sot;
}

// Getter dan Setter untuk goalScore
// setGoalScore(...)
// getGoalScore()
void Striker::setGoalScore(int gs){
    goalScore = gs;
}
int Striker::getGoalScore(){
    return goalScore;
}

// Getter dan Setter untuk shotsOnTarget
// setShotsOnTarget(...)
// getShotsOnTarget()
void Striker::setShotsOnTarget(int sot){
    shotsOnTarget = sot;
}
int Striker::getShotsOnTarget(){
    return shotsOnTarget;
}

// Method tambahan: menghitung conversion rate dalam persen
// conversionRate() = (goalScore / shotsOnTarget) * 100
// return dalam bentuk float
// Hint: Gunakan static_cast<float> untuk mengonversi int ke float
// ...
float Striker::conversionRate(){
    if (shotsOnTarget == 0) return 0.0f;
    return (static_cast<float>(goalScore)/ shotsOnTarget) * 100;
}

// Override transferRate:
// rumus: 1.000.000 * goalScore + 10.000 * conversionRate()
// hasil berupa int
// ...
int Striker::transferRate(){
    return 1000000 * goalScore + 10000 * conversionRate();
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan striker (goalScore, conversionRate)
// Format:
// Goals: <goalScore>
// Conversion Rate: <conversionRate>%
void Striker::displayInfo(){
    Footballer::displayInfo();
    cout << "Goals: " << goalScore << endl;
    cout << "Conversion Rate: " << fixed << setprecision(2) << conversionRate() << "%" << endl;
}

// Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
// Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
// ...