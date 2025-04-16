#include "Playlist.hpp"

// Constructor
Playlist::Playlist(string playlistName){
    this->name = playlistName;
}

// Getters
const string &Playlist::getName() const {
    return this->name;
}

const vector<Song> &Playlist::getSongs() const{
    return this->songs;
}

/*
    * Menambahkan salinan lagu yang diberikan ke akhir playlist apabila lagu tersebut belum ada di playlist.
    * Menggunakan Song::operator== untuk perbandingan.
    */
void Playlist::addSong(const Song &song){
    for (const auto &existingSong : songs) {
        if (existingSong == song) {
            return;  
        }
    }

    songs.push_back(song);
}

/*
    * Menghapus kemunculan pertama dari lagu yang ditentukan dari playlist.
    * Mengembalikan true jika lagu berhasil dihapus, false jika tidak.
    * Menggunakan Song::operator== untuk perbandingan.
    */
bool Playlist::removeSong(const Song &songToRemove){
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if (*it == songToRemove) {
            songs.erase(it); 
            return true;      
        }
    }
    return false; 
}

/*
    * Menghapus lagu pada indeks yang ditentukan.
    * Melempar out_of_range jika indeks tidak valid.
    */
void Playlist::removeSongByIndex(size_t index){
    if (index >= songs.size()) {
        throw out_of_range("Index out of range");
    }
    songs.erase(songs.begin() + index);
}

/*
    * Mengembalikan jumlah lagu dalam playlist.
    */
size_t Playlist::numberOfSongs() const {
    return this->songs.size();
}

/*
    * Friend function untuk mencetak isi playlist.
    * Format:
    * Playlist: <nama_playlist> (<jumlah_lagu> lagu)
    * 1. <lagu1>
    * 2. <lagu2>
    * ...
    * <jumlah_lagu>. <laguN> <endl>
    */
ostream &operator<<(ostream &os, const Playlist &pl) {
    os << "Playlist: " << pl.getName() << " (" <<  pl.numberOfSongs() << " lagu)" << endl;
    for (int i = 0; i < pl.songs.size(); i++){
        os << i + 1 << ". " << pl.songs[i] << endl;
    }
    return os;
}