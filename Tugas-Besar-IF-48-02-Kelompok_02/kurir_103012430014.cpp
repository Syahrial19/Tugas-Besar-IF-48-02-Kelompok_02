#include "header.h"
#include <iostream>
using namespace std;

void createListKurir(ListKurir &L){
    L.first = nullptr;
    L.last = nullptr;
}

addressK createKurir(string id, string nama, int umur) {
    addressK K = new elmKurir;
    K->info.id = id;
    K->info.nama = nama;
    K->info.umur = umur;
    K->firstP = nullptr;
    K->next = nullptr;
    K->prev = nullptr;

    return K;
}


void insertFirstKurir(ListKurir &L, addressK K) {
    if (L.first == nullptr) {
        L.first = K;
        L.last = K;
    } else {
        K->next = L.first;
        L.first->prev = K;
        L.first = K;
    }
}

void insertLastKurir(ListKurir &L, addressK K) {
    if (L.first == nullptr) {
        L.first = K;
        L.last = K;
    } else {
        L.last->next = K;
        K->prev = L.last;
        L.last = K;
    }
}

void insertAfterKurir(ListKurir &L, addressK prec, addressK K) {
    if (prec != nullptr) {
        K->next = prec->next;
        K->prev = prec;

        if (prec->next != nullptr) {
            prec->next->prev = K;
        } else {
            L.last = K;
        }
        prec->next = K;
    }
}
