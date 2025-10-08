#include <iostream>
using namespace std;

void tampilkanSegitiga(int n) {
    for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah baris (n): ";
    cin >> n;

    cout << "\n=== Pola Segitiga Angka ===" << endl;
    tampilkanSegitiga(n);

    return 0;
}
