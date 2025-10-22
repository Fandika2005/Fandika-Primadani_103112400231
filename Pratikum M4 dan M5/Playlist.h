#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk lagu
struct Lagu {
    string judul;
    string penyanyi;
    float durasi;
    Lagu* next;
};

// Kelas Playlist
class Playlist {
private:
    Lagu* head;

public:
    Playlist();                    // Konstruktor
    ~Playlist();                   // Destruktor
    void tambahDepan(string, string, float);
    void tambahBelakang(string, string, float);
    void tambahSetelahKe3(string, string, float);
    void hapusLagu(string);
    void tampilkan();
};

#endif
