#include "Gudang.hpp"
#include "Exception.hpp"
#include "BarangElektronik.hpp"
#include "BarangMakanan.hpp"
#include <iostream>

/*
    Membuat objek Gudang dengan kapasitas, uang, tenaga kerja default.
*/
Gudang::Gudang(){
    this->kapasitasTotal = DEFAULT_KAPASITAS;
    this->kapasitasTerpakai = 0;
    this->tenagaKerja = DEFAULT_TENAGA_KERJA;
    this->uang = DEFAULT_UANG;
}

/*
    Membuat objek Gudang dengan kapasitas, uang, tenaga kerja sesuai argumen.
*/
Gudang::Gudang(int kapasitas, int uang, int tenagaKerja){
    this->kapasitasTotal = kapasitas;
    this->kapasitasTerpakai = 0;
    this->tenagaKerja = tenagaKerja;
    this->uang = uang;
}

/*
    Menghancurkan Gudang. Pastikan semua pointer barang dihapus (delete).
*/
Gudang::~Gudang(){
    for (auto barang : this->daftarBarang) {
        delete barang;
    }
}

/*
    Menambahkan barang ke dalam gudang.
    - Setiap barang membutuhkan:
        kapasitas = berat barang
        uang = 100 per barang
        1 tenaga kerja

    - Jika barang makanan dan sudah kedaluwarsa (hariKedaluwarsa <= 0), lempar BarangKedaluwarsaException, dan tampilkan pesan: "Barang makanan sudah kadaluwarsa, buang dulu."
    - Jika kapasitas tidak cukup, lempar KapasitasPenuhException, tampilkan: "Kapasitas tidak cukup, perluas gudang dulu."
    - Jika uang tidak cukup, lempar UangTidakCukupException, tampilkan: "Uang tidak cukup, cari pemasukan dulu."
    - Jika tidak ada tenaga kerja, lempar TenagaKerjaTidakCukupException, tampilkan: "Tidak ada tenaga kerja, rekrut dulu."

    - Jika gagal, sumber daya tidak berkurang.

    - Jika berhasil, barang ditambahkan dan tampilkan:
        "Barang [<index>] <nama> berhasil disimpan"

    - Index dimulai dari 0
    - Gunakan dynamic cast untuk mendapatkan kadaluarsa dari BarangMakanan
    contoh: Class *x = dynamic_cast<Class *>(input)

    (semua output diakhiri newline)
*/
void Gudang::simpanBarang(Barang *barang){
    try {
        if (barang->getJenis() == "Makanan"){
            BarangMakanan* makanan = dynamic_cast<BarangMakanan*>(barang);
            if (makanan->getHariKedaluwarsa() <= 0){
                throw BarangKedaluwarsaException();
            }
        }

        if (this->kapasitasTotal - this->kapasitasTerpakai < barang->getBerat()){
            throw KapasitasPenuhException();
        }
        if (this->uang < 100){
            throw UangTidakCukupException();
        }
        if (this->tenagaKerja < 1){
            throw TenagaKerjaTidakCukupException();
        }
        pakaiKapasitas(barang->getBerat());
        pakaiUang(100);
        pakaiTenagaKerja();

        this->daftarBarang.push_back(barang);
        cout << "Barang [" << this->daftarBarang.size() - 1 << "] " << barang->getNama() << " berhasil disimpan" << endl;
    } catch (BarangKedaluwarsaException e){
        cout << e.what() << ", buang dulu." << endl;
    } catch (KapasitasPenuhException e){
        cout << e.what() << ", perluas gudang dulu." << endl;
    } catch (UangTidakCukupException e){
        cout << e.what() << ", cari pemasukan dulu." << endl;
    } catch (TenagaKerjaTidakCukupException e){
        cout << e.what() << ", rekrut dulu." << endl;
    } catch (...){
        cout << endl;
    }
}

/*
    Menambahkan kapasitas gudang
*/
void Gudang::tambahKapasitas(int kg){
    this->kapasitasTotal += kg;
}

/*
    Menambahkan tenaga kerja
*/
void Gudang::tambahTenagaKerja(int jumlah){
    this->tenagaKerja += jumlah;
}

/*
    Menambahkan uang
*/
void Gudang::tambahUang(int jumlah){
    this->uang += jumlah;
}

/*
    Menggunakan kapasitas (lempar KapasitasPenuhException jika tidak cukup)
*/
void Gudang::pakaiKapasitas(int kg){
    if (this->kapasitasTerpakai + kg > this->kapasitasTotal) {
        throw KapasitasPenuhException();
    }
    this->kapasitasTerpakai += kg;
}

/*
    Menggunakan uang (lempar UangTidakCukupException jika tidak cukup)
*/
void Gudang::pakaiUang(int jumlah){
    if (this->uang < jumlah) {
        throw UangTidakCukupException();
    }
    this->uang -= jumlah;
}

/*
    Menggunakan tenaga kerja (1 pekerja), lempar TenagaKerjaTidakCukupException jika tidak cukup
*/
void Gudang::pakaiTenagaKerja(){
    if (this->tenagaKerja < 1) {
        throw TenagaKerjaTidakCukupException();
    }
    this->tenagaKerja -= 1;
}

/*
    Menyebut barang di index tertentu. Tampilkan:
    "<nama> - <jenis> - <berat>kg"

    Jika index tidak valid, tampilkan exception bawaan C++ diakhiri newline.
*/
void Gudang::sebutBarang(int idx){
    if (idx < 0 || idx >= this->daftarBarang.size()){
        throw out_of_range("Index out of range");
    }
    cout << this->daftarBarang[idx]->getNama() << " - " << this->daftarBarang[idx]->getJenis() << " - " << this->daftarBarang[idx]->getBerat() << "kg" << endl;
}

/*
    Menampilkan status gudang seperti:

    Status gudang:
        Kapasitas total: <kapasitasTotal> kg
        Kapasitas terpakai: <kapasitasTerpakai> kg
        Uang: <uang>
        Tenaga kerja: <tenagaKerja>
        Barang:
        [0] <nama> - <jenis> - <berat>kg
        ...
*/
void Gudang::statusGudang() const {
    try {
        cout << "Status gudang:" << endl;
        cout << "  Kapasitas total: " << this->kapasitasTotal << " kg" << endl;
        cout << "  Kapasitas terpakai: " << this->kapasitasTerpakai << " kg" << endl;
        cout << "  Uang: " << this->uang << endl;
        cout << "  Tenaga kerja: " << this->tenagaKerja << endl;
        cout << "  Barang:" << endl;
        for (int i = 0; i < this->daftarBarang.size(); i++){
            cout << "    [" << i << "] ";
            const_cast<Gudang*>(this)->sebutBarang(i);
        }
    } catch(const out_of_range& e){
        cout << e.what() << endl;
    }
}