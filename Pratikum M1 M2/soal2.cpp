#include <iostream>
using namespace std;

string satuan[] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima",
                   "Enam", "Tujuh", "Delapan", "Sembilan"};
string belasan[] = {"Sepuluh", "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas",
                    "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh",
                    "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

string terbilang(int n) {
    if (n == 0) return "Nol";
    else if (n == 100) return "Seratus";
    else if (n < 10) return satuan[n];
    else if (n < 20) return belasan[n - 10];
    else {
        int p = n / 10;
        int s = n % 10;
        if (s == 0) return puluhan[p];
        else return puluhan[p] + " " + satuan[s];
    }
}

int main() {
    int angka;
    cout << "Masukkan angka : ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else {
        cout << angka << " : " << terbilang(angka) << endl;
    }

    return 0;
}
