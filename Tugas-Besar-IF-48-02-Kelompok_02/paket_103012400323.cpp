#include "kurir.h"
#include <iostream>
using namespace std;

addressP createPaket_103012400323(string idPaket, string namaPenerima, string alamat) {
    addressP P = new elmPaket;
    P->info.idPaket = idPaket;
    P->info.namaPenerima = namaPenerima;
    P->info.alamat = alamat;
    P->next = nullptr;
    return P;
}

bool isEmptyPaket_103012400323(addressK K) {
    return (K == nullptr || K->firstP == nullptr);
}

void insertFirstPaket_103012400323(addressK K, addressP P) {
    if (K->firstP == nullptr) {
        K->firstP = P;
    } else {
        P->next = K->firstP;
        K->firstP = P;
    }
}

void insertLastPaket_103012400323(addressK K, addressP P) {
    if (K->firstP == nullptr) {
        K->firstP = P;
    } else {
        addressP Q = K->firstP;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterPaket_103012400323(addressK K, addressP prec, addressP P) {
    if (prec != nullptr) {
        P->next = prec->next;
        prec->next = P;
    }
}
