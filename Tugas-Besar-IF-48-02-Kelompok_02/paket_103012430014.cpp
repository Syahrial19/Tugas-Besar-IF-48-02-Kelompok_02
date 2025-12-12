#include "header.h"
#include <iostream>
using namespace std;

void deleteFirstPaket(addressK K, addressP &P) {
    if (!isEmptyPaket(K)) {
        P = K->firstP;
        K->firstP = P->next;
        P->next = nullptr;
    }
}
void deleteLastPaket(addressK K, addressP &P) {
    if (!isEmptyPaket(K)) {

        if (K->firstP->next == nullptr) {
            deleteFirstPaket(K, P);
        } else {
            addressP Q = K->firstP;

            while (Q->next->next != nullptr) {
                Q = Q->next;
            }

            P = Q->next;
            Q->next = nullptr;
            P->next = nullptr;
        }
    }
}
void deleteAfterPaket(addressK K, addressP prec, addressP &P) {
    if (prec != nullptr && prec->next != nullptr) {
        P = prec->next;
        prec->next = P->next;

        P->next = nullptr;
    }
}

adrKurir findPaket(ListKurir L, string idpaket){
    adrP P = L.first;

    while (P != nullptr){
        if (P->info.idpaket == idpaket){
            return P;
        }
        P = P->next;
    }

    return ;
}

void showAllPaket(addressK K) {
    if (isEmptyPaket(K)) {
        cout << "   (Tidak ada paket)\n";
        return;
    }

    addressP P = K->firstP;
    while (P != nullptr) {
        cout << "   - ID Paket: " << P->info.idPaket
             << ", Nama Penerima: " << P->info.namaPenerima
             << ", Alamat: " << P->info.alamat << endl;
        P = P->next;
    }
}

int countPaket(addressK K) {
    int count = 0;
    addressP P = K->firstP;

    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}
void showPaketOfKurir(addressK K) {
    if (K == nullptr) {
        cout << "Kurir tidak ditemukan." << endl;
        return;
    }

    cout << "== Daftar Paket Kurir ==" << endl;
    cout << "Kurir : " << K->info.nama
         << " (ID: " << K->info.id << ")" << endl;

    addressP P = K->firstP;

    if (P == nullptr) {
        cout << "  Tidak ada paket." << endl;
    } else {
        while (P != nullptr) {
            cout << "  - ID Paket: " << P->info.idPaket
                 << ", Penerima: " << P->info.namaPenerima
                 << ", Alamat: " << P->info.alamat
                 << endl;
            P = P->next;
        }
    }
}


