#include <iostream>
using namespace std;

// Fungsi untuk menampilkan array 2D integer
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fungsi untuk menukar isi dua array 2D pada posisi tertentu
void tukarPosisiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Fungsi untuk menukar isi dua variabel melalui pointer
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int *ptr1, *ptr2;
    int x = 100, y = 200;
    ptr1 = &x;
    ptr2 = &y;

    cout << "=== Array A ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B ===" << endl;
    tampilArray(B);

    // Menukar posisi tertentu pada kedua array
    cout << "\nMenukar elemen pada baris 1 kolom 2..." << endl;
    tukarPosisiArray(A, B, 1, 2);

    cout << "\n=== Array A setelah ditukar ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B setelah ditukar ===" << endl;
    tampilArray(B);

    // Menukar isi dua variabel melalui pointer
    cout << "\nNilai sebelum ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(ptr1, ptr2);

    cout << "Nilai setelah ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
