#include <iostream>
using namespace std;

int main() {
    float angka1, angka2;

    cout << "Masukkan bilangan pertama: ";
    cin >> angka1;
    cout << "Masukkan bilangan kedua: ";
    cin >> angka2;

    float jumlah = angka1 + angka2;
    float kurang = angka1 - angka2;
    float kali   = angka1 * angka2;
    float bagi;

    if (angka2 != 0) {
        bagi = angka1 / angka2;
        cout << "\nHasil Penjumlahan: " << jumlah << endl;
        cout << "Hasil Pengurangan: " << kurang << endl;
        cout << "Hasil Perkalian  : " << kali << endl;
        cout << "Hasil Pembagian  : " << bagi << endl;
    } else {
        cout << "\nHasil Penjumlahan: " << jumlah << endl;
        cout << "Hasil Pengurangan: " << kurang << endl;
        cout << "Hasil Perkalian  : " << kali << endl;
        cout << "Hasil Pembagian  : Tidak bisa dibagi dengan nol!" << endl;
    }

    return 0;
}
