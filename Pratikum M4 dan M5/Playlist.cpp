#include "Playlist.h"

// Konstruktor
Playlist::Playlist() {
    head = nullptr;
}

// Destruktor
Playlist::~Playlist() {
    Lagu* current = head;
    while (current != nullptr) {
        Lagu* temp = current;
        current = current->next;
        delete temp;
    }
}

// Tambah lagu di awal playlist
void Playlist::tambahDepan(string judul, string penyanyi, float durasi) {
    Lagu* baru = new Lagu{judul, penyanyi, durasi, nullptr};
    baru->next = head;
    head = baru;
    cout << "Lagu \"" << judul << "\" ditambahkan di awal playlist.\n";
}

// Tambah lagu di akhir playlist
void Playlist::tambahBelakang(string judul, string penyanyi, float durasi) {
    Lagu* baru = new Lagu{judul, penyanyi, durasi, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Lagu* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Lagu \"" << judul << "\" ditambahkan di akhir playlist.\n";
}

// Tambah lagu setelah playlist ke-3
void Playlist::tambahSetelahKe3(string judul, string penyanyi, float durasi) {
    Lagu* baru = new Lagu{judul, penyanyi, durasi, nullptr};
    Lagu* temp = head;
    int count = 1;

    while (temp != nullptr && count < 3) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Playlist kurang dari 3 lagu. Lagu ditambahkan di akhir.\n";
        tambahBelakang(judul, penyanyi, durasi);
        delete baru; // sudah ditambahkan di fungsi tambahBelakang
        return;
    }

    baru->next = temp->next;
    temp->next = baru;
    cout << "Lagu \"" << judul << "\" ditambahkan setelah lagu ke-3.\n";
}

// Hapus lagu berdasarkan judul
void Playlist::hapusLagu(string judul) {
    if (head == nullptr) {
        cout << "Playlist kosong.\n";
        return;
    }

    if (head->judul == judul) {
        Lagu* temp = head;
        head = head->next;
        delete temp;
        cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
        return;
    }

    Lagu* temp = head;
    while (temp->next != nullptr && temp->next->judul != judul) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Lagu \"" << judul << "\" tidak ditemukan.\n";
    } else {
        Lagu* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
        cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
    }
}

// Tampilkan seluruh lagu dalam playlist
void Playlist::tampilkan() {
    if (head == nullptr) {
        cout << "Playlist kosong.\n";
        return;
    }

    cout << "\n=== Daftar Lagu dalam Playlist ===\n";
    Lagu* temp = head;
    int no = 1;
    while (temp != nullptr) {
        cout << no++ << ". " << temp->judul << " - " << temp->penyanyi 
             << " (" << temp->durasi << " menit)\n";
        temp = temp->next;
    }
    cout << "==================================\n";
}
