#include "Gradebook.hpp"

/*
    * Menambah atau mengupdate nilai mahasiswa.
    * Jika mahasiswa sudah ada, nilainya akan diupdate.
    * Jika mahasiswa belum ada, akan ditambahkan dengan nilai yang diberikan.
    */
void Gradebook::addOrUpdateStudent(const string &studentName, double grade){
    this->studentGrades[studentName] = grade;
}

/*
    * Menghapus mahasiswa dari gradebook.
    * Mengembalikan true jika mahasiswa ditemukan dan berhasil dihapus,
    * false jika tidak ditemukan.
    */
bool Gradebook::removeStudent(const string &studentName){
    if (this->studentExists(studentName)) {
        studentGrades.erase(studentName);
        return true;
    }
    return false;
}

/*
    * Mengambil nilai dari mahasiswa tertentu.
    * Mengembalikan true jika mahasiswa ditemukan dan nilainya disimpan
    * di parameter 'grade', false jika mahasiswa tidak ditemukan.
    */
bool Gradebook::getGrade(const string &studentName, double &grade) const{
    if (this->studentExists(studentName)) {
        grade = this->studentGrades.at(studentName);
        return true;
    }
    return false;
}

/*
    * Memeriksa apakah mahasiswa ada dalam gradebook.
    * Mengembalikan true jika mahasiswa ada, false jika tidak.
    */
bool Gradebook::studentExists(const string &studentName) const{
    return studentGrades.find(studentName) != studentGrades.end();
}

/*
    * Mencetak semua nama mahasiswa dan nilai mereka
    * Jika gradebook kosong, akan mencetak pesan "Gradebook kosong\n"
    * Format:
    * 1. <nama_mahasiswa>: <nilai>
    * 2. <nama_mahasiswa>: <nilai>
    * ...
    */
void Gradebook::printGrades() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong\n";
        return;
    }
    int index = 1;
    for (const auto &entry : studentGrades) {
        cout << index << ". " << entry.first << ": " << entry.second << endl;
        index++;
    }
}

/*
    * Mencetak semua nama mahasiswa dan nilai mereka, terurut berdasarkan nilai terbesar ke terkecil.
    * Hint: gunakan vector<pair<string, double>> untuk menyimpan semua data mahasiswa untuk memudahkan pengurutan. Gunakan fungsi bantuan untuk komparasi pada std::sort.
    * Format:
    * 1. <nama_mahasiswa>: <nilai>
    * 2. <nama_mahasiswa>: <nilai>
    * ...
    */
void Gradebook::printGradesRank() const {
    // if (studentGrades.empty()) {
    //     cout << "Gradebook kosong\n";
    //     return;
    // }

    vector<pair<string, double>> sortedGrades(studentGrades.begin(), studentGrades.end());

    sort(sortedGrades.begin(), sortedGrades.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    int index = 1;
    for (const auto &entry : sortedGrades) {
        cout << index << ". " << entry.first << ": " << entry.second << endl;
        index++;
    }
}

/*
    * Mengembalikan daftar nama mahasiswa yang nilainya di atas threshold tertentu.
    * Mengembalikan vector berisi nama mahasiswa dengan nilai lebih besar dari threshold,
    * terurut berdasarkan abjad.
    */
vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const {
    vector<string> result;
    for (const auto &entry : studentGrades) {
        if (entry.second > threshold) {
            result.push_back(entry.first);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

/*
    * Menghitung rata-rata nilai semua mahasiswa dalam gradebook.
    * Mengembalikan rata-rata nilai, atau 0.0 jika gradebook kosong.
    */
double Gradebook::getAverageGrade() const {
    if (studentGrades.empty()) {
        return 0.0;
    }

    double total = 0.0;
    for (const auto &entry : studentGrades) {
        total += entry.second;
    }

    return total / studentGrades.size();

}

/*
    * Mengembalikan jumlah mahasiswa yang ada dalam gradebook.
    */
size_t Gradebook::getNumberOfStudents() const {
    return this->studentGrades.size();
}