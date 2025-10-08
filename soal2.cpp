#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan jumlah array : ";
    cin >> N;

    int *arr = new int[N];
    int *ptr = arr;

    cout << "\nMasukkan " << N << " bilangan bulat:\n";
    for (int i = 0; i < N; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> *(ptr + i);
    }
    int jumlah = 0;
    int maks = *ptr;
    int min = *ptr;

    for (int i = 0; i < N; i++) {
        int nilai = *(ptr + i);
        jumlah += nilai;
        if (nilai > maks) maks = nilai;
        if (nilai < min) min = nilai;
    }
    cout << "\n=== HASIL PERHITUNGAN ===\n";
    cout << "Jumlah seluruh bilangan: " << jumlah << endl;
    cout << "Nilai maksimum: " << maks << endl;
    cout << "Nilai minimum: " << min << endl;

    delete[] arr;
    return 0;
}
