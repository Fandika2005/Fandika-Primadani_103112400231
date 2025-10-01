#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string NIM;
};

int main() {
    Mahasiswa mhs;
    mhs.nama = "Fandika Primadani";
    mhs.NIM = "103112400231";

    cout << "Nama : " << mhs.nama << endl << "NIM : " << mhs.NIM;
}