#include "Playlist.h"
#include "Playlist.cpp"

int main() {
    Playlist playlist;
    int pilihan;
    string judul, penyanyi;
    float durasi;

    do {
        cout << "\n=== MENU PLAYLIST LAGU ===\n";
        cout << "1. Tambah Lagu di Awal\n";
        cout << "2. Tambah Lagu di Akhir\n";
        cout << "3. Tambah Lagu Setelah Lagu ke-3\n";
        cout << "4. Hapus Lagu Berdasarkan Judul\n";
        cout << "5. Tampilkan Playlist\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Judul lagu: "; getline(cin, judul);
                cout << "Penyanyi: "; getline(cin, penyanyi);
                cout << "Durasi (menit): "; cin >> durasi;
                playlist.tambahDepan(judul, penyanyi, durasi);
                break;

            case 2:
                cout << "Judul lagu: "; getline(cin, judul);
                cout << "Penyanyi: "; getline(cin, penyanyi);
                cout << "Durasi (menit): "; cin >> durasi;
                playlist.tambahBelakang(judul, penyanyi, durasi);
                break;

            case 3:
                cout << "Judul lagu: "; getline(cin, judul);
                cout << "Penyanyi: "; getline(cin, penyanyi);
                cout << "Durasi (menit): "; cin >> durasi;
                playlist.tambahSetelahKe3(judul, penyanyi, durasi);
                break;

            case 4:
                cout << "Masukkan judul lagu yang ingin dihapus: ";
                getline(cin, judul);
                playlist.hapusLagu(judul);
                break;

            case 5:
                playlist.tampilkan();
                break;

            case 0:
                cout << "Keluar dari program.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
