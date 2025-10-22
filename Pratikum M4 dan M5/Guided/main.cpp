#include <iostream>
#include <cstdlib>
#include "singlylist.h"
#include "singlylist.cpp"


using namespace std;

int main() {
    list L;
    address P; //cukup satu pointer untuk dignakan berulang kali

    createList(L);

    cout << "mengisi list menggunakan insertlast..." << endl;

    //mengisi list sesuai urutan
    P = alokasi(9);
    insertLast(L, P);

    P = alokasi(12);
    insertLast(L, P);

    P = alokasi(8);
    insertLast(L, P);

    P = alokasi(0);
    insertLast(L, P);

    P = alokasi(2);
    insertLast(L, P);


    cout << "isi list sekarang adalah: ";
    printInfo(L);

    system("pause");
    return 0;
}