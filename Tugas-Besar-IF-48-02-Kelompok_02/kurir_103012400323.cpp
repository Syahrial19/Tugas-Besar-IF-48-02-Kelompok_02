#include "header.h"
#include <iostream>
using namespace std;

void deleteFirstKurir(ListKurir &L, addressK &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = nullptr;
        P->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteLastKurir(ListKurir &L, addressK &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.last;
        L.last = P->prev;
        L.last->next = nullptr;
        P->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfterKurir(ListKurir &L, addressK prec, addressK &P) {
    if (prec == nullptr || prec->next == nullptr) {
        P = nullptr;
    } else {
        P = prec->next;
        if (P == L.last) {
            L.last = prec;
            prec->next = nullptr;
            P->prev = nullptr;
            P->next = nullptr;
        } else {
            prec->next = P->next;
            P->next->prev = prec;
            P->next = nullptr;
            P->prev = nullptr;
        }
    }
}

addressK findKurir(ListKurir L, string id) {
    addressK K = L.first;
    while (K != nullptr) {
        if (K->info.id == id) {
            return K;
        }
        K = K->next;
    }
    return nullptr;
}

void showAllKurir(ListKurir L) {
    if (L.first == nullptr) {
        cout << "Tidak ada kurir.\n";
    } else {
        addressK K = L.first;
        while (K != nullptr) {
            cout << "- ID: " << K->info.id
                 << ", Nama: " << K->info.nama
                 << ", Umur: " << K->info.umur << endl;
            K = K->next;
        }
    }
}

int countKurir(ListKurir L) {
    int total = 0;
    addressK K = L.first;
    while (K != nullptr) {
        total++;
        K = K->next;
    }
    return total;
}
