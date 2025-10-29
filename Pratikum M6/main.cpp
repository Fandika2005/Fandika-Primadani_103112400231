#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

typedef ElmList* address;

struct List {
    address first;
    address last;
};

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

bool isExist(List L, string nopol) {
    address Q = L.first;
    while (Q != NULL) {
        if (Q->info.nopol == nopol) {
            return true;
        }
        Q = Q->next;
    }
    return false;
}

void printInfo(List L) {
    cout << "\nDATA LIST 1" << endl;
    address P = L.first;
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first == L.last) {
        P = L.last;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.last;
        L.last = L.last->prev;
        L.last->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

int main() {
    List L;
    createList(L);

    infotype x;
    char lagi;

    do {
        cout << "\nMasukkan Nomor Polisi: ";
        cin >> x.nopol;

        if (isExist(L, x.nopol)) {
            cout << "Nomor polisi sudah terdaftar!" << endl;
        } else {
            cout << "Masukkan Warna Kendaraan: ";
            cin >> x.warna;
            cout << "Masukkan Tahun Kendaraan: ";
            cin >> x.thnBuat;

            address P = alokasi(x);
            insertLast(L, P);
        }

        cout << "Tambah data lagi? (y/n): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    printInfo(L);

    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    string cari;
    cin >> cari;
    address found = findElm(L, cari);
    if (found != NULL) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cari << " tidak ditemukan." << endl;
    }

    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    string hapus;
    cin >> hapus;

    address Q = findElm(L, hapus);
    if (Q == NULL) {
        cout << "Data dengan nomor polisi " << hapus << " tidak ditemukan." << endl;
    } else {
        if (Q == L.first) {
            deleteFirst(L, Q);
        } else if (Q == L.last) {
            deleteLast(L, Q);
        } else {
            address Prec = Q->prev;
            deleteAfter(Prec, Q);
        }
        dealokasi(Q);
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus." << endl;
    }

    printInfo(L);

    return 0;
}
