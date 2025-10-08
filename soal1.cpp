#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int mhs = 5;
    const int mk = 3;
    string nama[mhs];
    float nilai[mhs][mk];
    float rata[mhs];

    cout << "=== Input Data Nilai Mahasiswa ===" << endl;
    for (int i = 0; i < mhs; i++) {
        cout << "\nMasukkan nama mahasiswa ke-" << i + 1 << ": ";
        cin >> nama[i];
        float total = 0;
        for (int j = 0; j < mk; j++) {
            cout << "Nilai mata kuliah " << j + 1 << ": ";
            cin >> nilai[i][j];
            total += nilai[i][j];
        }
        rata[i] = total / mk;
    }
    int terbaik = 0;
    for (int i = 1; i < mhs; i++) {
        if (rata[i] > rata[terbaik]) {
            terbaik = i;
        }
    }
    cout << "\n=== Daftar Nilai Mahasiswa ===" << endl;
    cout << left << setw(12) << "Nama"
         << setw(10) << "MK1"
         << setw(10) << "MK2"
         << setw(10) << "MK3"
         << setw(10) << "Rata-rata"
         << "Keterangan" << endl;

    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < mhs; i++) {
        cout << left << setw(12) << nama[i];
        for (int j = 0; j < mk; j++) {
            cout << setw(10) << nilai[i][j];
        }
        cout << setw(10) << fixed << setprecision(2) << rata[i];
        if (i == terbaik)
            cout << " <- TERBAIK";
        cout << endl;
    }

    cout << "\nMahasiswa terbaik adalah: " << nama[terbaik]
         << " dengan rata-rata " << fixed << setprecision(2) << rata[terbaik] << endl;

    return 0;
}
