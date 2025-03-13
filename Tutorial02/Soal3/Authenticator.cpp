#include "Authenticator.hpp"

Authenticator::Authenticator()
/* Constructor:
   * - Menginisialisasi sistem dengan resource rahasia ("Ini adalah data rahasia!")
   * - Tidak ada user yang login (nullptr)
   * - Tidak ada user yang terdaftar
   */
{
    this->secretResource = "Ini adalah data rahasia!";
    this->currentUser = nullptr;
    this->userCount = 0;
}

void Authenticator::registerUser(const string &username, const string &password, bool isAdmin)
/* Mendaftarkan user baru sebagai RegularUser atau AdminUser.
   * Input:
   * - username: Nama pengguna yang ingin didaftarkan.
   * - password: Kata sandi untuk pengguna.
   * - isAdmin: Jika true, user akan dibuat sebagai AdminUser, jika false sebagai User biasa.
   *
   * Output:
   * - "Gagal: Kapasitas user penuh!" jika jumlah user telah mencapai batas maksimum.
   * - "Gagal: Username sudah digunakan!" jika username sudah terdaftar dalam sistem.
   * - "Sukses: User <username> berhasil terdaftar!" jika pendaftaran berhasil.
   *      *<username> diganti dengan nama pengguna yang baru terdaftar.
   */
{
    User* x;
    if (isAdmin){
        x = new AdminUser(username, password);
    } else {
        x = new User(username, password);
    }

    if (userCount < MAX_USERS){
        bool valid = true;
        for (int i = 0; i < userCount; i++){
            if (this->users[i]->getUsername() == username){
                valid = false;
            }
        }

        if (valid){
            cout << "Sukses: User " << x->getUsername() << " berhasil terdaftar!" << endl;
            this->users[userCount] = x;
            this->userCount++;
        } else {
            cout << "Gagal: Username sudah digunakan!" << endl;
        }
    } else {
        cout << "Gagal: Kapasitas user penuh!" << endl;
    }
}

void Authenticator::login(const string &username, const string &password)
  /* Mencoba login dengan username dan password yang diberikan.
   * Input:
   * - username: Nama pengguna yang ingin login.
   * - password: Kata sandi pengguna yang ingin login.
   *
   * Output:
   * - "Gagal: Username atau password salah!" jika kombinasi username dan password tidak ditemukan.
   * - "Sukses: Login berhasil! Selamat datang, <username>." jika login berhasil.
   *      *<username> diganti dengan nama pengguna yang berhasil login.
   */
{
    int userID = -1;
    for (int i = 0; i < userCount; i++){
        if (this->users[i]->getUsername() == username && this->users[i]->checkPassword(password)){
            userID = i;
            break;
        }
    }

    if (userID == -1){
        cout << "Gagal: Username atau password salah!" << endl;
    } else {
        User *cu = this->users[userID];
        cout << "Sukses: Login berhasil! Selamat datang, " << cu->getUsername() << "." << endl;
        this->currentUser = cu;
    }
}

void Authenticator::logout() 
 /* Melakukan logout dari sesi yang sedang berjalan.
   *
   * Output:
   * - "Gagal: Tidak ada user yang sedang login!" jika tidak ada user yang sedang login.
   * - "Sukses: User <username> telah logout." jika logout berhasil.
   *      *<username> diganti dengan nama pengguna yang logout.
   */
{
    if (this->currentUser == nullptr){
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
    } else {
        cout << "Sukses: User " << currentUser->getUsername() << " telah logout." << endl;
        this->currentUser = nullptr;
    }
}

void Authenticator::accessResource() const
  /* Menampilkan resource rahasia jika user sudah login.
   *
   * Output:
   * - "Akses ditolak! Silakan login terlebih dahulu." jika tidak ada user yang login.
   * - "Resource: <secretResource>" jika user sedang login.
   *      *<secretResource> diganti dengan resource rahasia saat ini.
   */
{
    if (this->currentUser == nullptr){
        cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;
    } else {
        cout << "Resource: " << this->secretResource << endl;
    }
}

void Authenticator::setResource(const string &newResource)
 /* Mengubah resource rahasia (hanya AdminUser yang dapat melakukannya).
   * Input:
   * - newResource: Resource baru yang akan disimpan.
   *
   * Output:
   * - "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." jika tidak ada user yang login.
   * - "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." jika user yang login bukan AdminUser.
   * - "Sukses: Resource telah diperbarui oleh <username>." jika resource berhasil diubah.
   *      *<username> diganti dengan nama pengguna admin yang melakukan perubahan.
   */
{
    if (this->currentUser == nullptr){
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << endl;
    } else {
        if (this->currentUser->isAdmin()){
            cout << "Sukses: Resource telah diperbarui oleh " << this->currentUser->getUsername() << "." << endl;
            this->secretResource = newResource;
        } else {
            cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << endl;
        }
    }
}

Authenticator::~Authenticator(){
    for (int i = 0; i < userCount; i++){
        delete this->users[i];
    }
}