#include "Goalkeeper.hpp"

// Default constructor
// set atribut Footballer dengan nilai default,
// set cleanSheets, saves, totalShotsOnGoal ke 0, playPosition ke "goalkeeper"
// ...
Goalkeeper::Goalkeeper(): Footballer(){
    cleanSheets = 0;
    saves = 0;
    totalShotsOnGoal = 0;
    playPosition = "goalkeeper";
}

// User-defined constructor
// parameter: string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal
// set atribut dengan nilai parameter, playPosition tetap "goalkeeper"
// nationality, height, dan weight gunakan nilai default superclass
// ...
Goalkeeper::Goalkeeper(string n, int by, int cs, int s, int tsg):Footballer(n, by, "goalkeeper", "Indonesia", 180, 70){
    cleanSheets = cs;
    saves = s;
    totalShotsOnGoal = tsg;
}

// Getter dan Setter untuk cleanSheets
// setCleanSheets(...)
// getCleanSheets()
void Goalkeeper::setCleanSheets(int cs){
    cleanSheets = cs;
}
int Goalkeeper::getCleanSheets(){
    return cleanSheets;
}

// Getter dan Setter untuk saves
// setSaves(...)
// getSaves()
void Goalkeeper::setSaves(int s){
    saves = s;
}
int Goalkeeper::getSaves(){
    return saves;
}

// Getter dan Setter untuk totalShotsOnGoal
// setTotalShotsOnGoal(...)
// getTotalShotsOnGoal()
void Goalkeeper::setTotalShotsOnGoal(int tsg){
    totalShotsOnGoal = tsg;
}
int Goalkeeper::getTotalShotsOnGoal(){
    return totalShotsOnGoal;
}

// Method tambahan: savePercentage
// rumus: (saves / totalShotsOnGoal) * 100
// return dalam bentuk float
// ...
float Goalkeeper::savePercentage(){
    if (totalShotsOnGoal == 0) return 0.0f;
    return ((float)saves / (float)totalShotsOnGoal) * 100;
}

// Override transferRate:
// rumus: (700.000 * cleanSheets) + (50.000 * saves)
// hasil berupa int
// ...
int Goalkeeper::transferRate(){
    return (700000 * cleanSheets) + (50000 * saves);
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan goalkeeper (cleanSheets, saves, savePercentage)
// Format:
// Clean Sheets: <cleanSheets>
// Saves: <saves>
// Save Percentage: <savePercentage>%

// Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
// Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
// ...
void Goalkeeper::displayInfo(){
    Footballer::displayInfo();
    cout << "Clean Sheets: " << cleanSheets << endl;
    cout << "Saves: " << saves << endl;
    cout << "Save Percentage: " << fixed << setprecision(2) << savePercentage() << "%" << endl;
}