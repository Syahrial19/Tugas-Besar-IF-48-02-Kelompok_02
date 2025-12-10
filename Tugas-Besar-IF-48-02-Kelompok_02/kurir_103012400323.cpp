#include "kurir.h"

adrKurir findKurir(ListKurir L, string id) {
    adrKurir p = L.first;
    while (p != nullptr) {
        if (p->id == id) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void deleteKurir(ListKurir &L, string id) {
    adrKurir p = findKurir(L, id);
    if (p == nullptr) return;

    if (p == L.first && p == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    }else if (p == L.first) {
        L.first = p->next;
        L.first->prev = nullptr;
    }else if (p == L.last) {
        L.last = p->prev;
        L.last->next = nullptr;
    }else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    delete p;
}

void showAllKurir(ListKurir L) {
    adrKurir p = L.first;
    while (p != nullptr) {
        cout << "ID: " << p->id << " | Nama: " << p->nama << " | Umur: " << p->umur << endl;
        p = p->next;
    }
}
