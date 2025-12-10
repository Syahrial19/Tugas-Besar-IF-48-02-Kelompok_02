#include "paket.h"
#include "kurir.h"
#include <iostream>
using namespace std;

void addPaketToKurir(Kurir* K, adrPaket P) {
    if (K != nullptr) {
        P->next = K->childHead;
        P->parent = K;
        K->childHead = P;
    }
}

adrPaket findPaketInKurir(Kurir* K, string idPaket) {
    adrPaket P = K->childHead;
    while (P != nullptr) {
        if (P->idPaket == idPaket) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void deletePaketFromKurir(Kurir* K, string idPaket) {
    if (K == nullptr || K->childHead == nullptr) return;

    adrPaket P = K->childHead;

    if (P->idPaket == idPaket) {
        K->childHead = P->next;
        delete P;
        return;
    }

    adrPaket prev = nullptr;
    while (P != nullptr && P->idPaket != idPaket) {
        prev = P;
        P = P->next;
    }

    if (P != nullptr) {
        prev->next = P->next;
        delete P;
    }
}

void showPaketOfKurir(Kurir* K) {
    if (K == nullptr) return;

    adrPaket P = K->childHead;
    while (P != nullptr) {
        cout << "ID Paket: " << P->idPaket << endl;
        cout << "Nama Penerima: " << P->namaPenerima << endl;
        cout << "Alamat: " << P->alamat << endl;
        cout << "-------------------------\n";
        P = P->next;
    }
}

