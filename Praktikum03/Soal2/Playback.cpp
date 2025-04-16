#include "Playback.hpp"

/*
    * Menambahkan satu lagu ke akhir queue pemutaran.
    * Tidak perlu mengecek apakah lagu sudah ada di queue (boleh ada duplikat)
    */
void Playback::addToQueue(const Song &song){
    this->playbackQueue.push(song);
}

/*
    * Menambahkan semua lagu dari playlist yang diberikan ke akhir queue pemutaran,
    * dengan mempertahankan urutan mereka dari playlist.
    * Tidak perlu mengecek apakah lagu sudah ada di queue (boleh ada duplikat)
    */
void Playback::addToQueue(const Playlist &playlist){
    for (const Song &song : playlist.getSongs()) {
        playbackQueue.push(song);
    }
}

/*
    * Memutar lagu berikutnya: Mencetak dengan format "Memutar: <lagu> <endl>" dan menghapusnya dari queue.
    * Jika queue kosong, mencetak pesan "Antrian kosong"
    */
void Playback::next(){
    if (playbackQueue.empty()) {
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Memutar: " << playbackQueue.front() << endl;
        playbackQueue.pop();  
    }
}

/*
    * Memutar semua lagu dari queue pemutaran.
    * Mencetak dengan format "Memutar: <lagu> <endl>" untuk setiap lagu di queue.
    * Jika queue kosong, mencetak pesan "Antrian kosong"
    */
void Playback::playAll(){
    if (playbackQueue.empty()) {
        cout << "Antrian kosong" << endl;
    } else {
        // Play all songs in the queue
        while (!playbackQueue.empty()) {
            cout << "Memutar: " << playbackQueue.front() << endl;
            playbackQueue.pop();
        }
    }
}

/*
    * Melewati lagu berikutnya: Menghapus lagu dari depan queue tanpa mencetak detail.
    * Jika queue kosong, mencetak pesan "Antrian kosong"
    */
void Playback::skip(){
    if (playbackQueue.empty()){
        cout << "Antrian kosong" << endl;
    } else {
        this->playbackQueue.pop();
    }
}

/*
    * Menghapus semua lagu dari queue pemutaran.
    */
void Playback::clearQueue(){
    while (!playbackQueue.empty()) {
        playbackQueue.pop(); 
    }
}

/*
    * Memeriksa apakah queue pemutaran kosong.
    */
bool Playback::isEmpty() const {
    return this->playbackQueue.empty();
}

/*
    * Mengembalikan jumlah lagu yang ada dalam queue.
    */
size_t Playback::queueSize() const {
    return this->playbackQueue.size();
}