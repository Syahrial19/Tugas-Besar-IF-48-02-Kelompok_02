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

addressP findPaket(addressK K, string idPaket) {
    addressP P = K->firstP;

    while (P != nullptr) {
        if (P->info.idPaket == idPaket) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
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
void deletePaketByAlamatAllKurir(ListKurir &L, string alamat) {
    addressK K = L.first;
    bool ditemukan = false;

    while (K != nullptr) {
        addressP P = K->firstP;
        addressP prev = nullptr;

        while (P != nullptr) {
            if (P->info.alamat == alamat) {
                addressP hapus = P;
                ditemukan = true;

                if (prev == nullptr) {
                    K->firstP = P->next;
                    P = K->firstP;
                }

                else {
                    prev->next = P->next;
                    P = P->next;
                }

                hapus->next = nullptr;
                delete hapus;
            } else {
                prev = P;
                P = P->next;
            }
        }

        K = K->next;
    }

    if (ditemukan)
        cout << "Semua paket dengan alamat \"" << alamat << "\" berhasil dihapus\n";
    else
        cout << "Tidak ditemukan paket dengan alamat tersebut\n";
}
void showPaketByAlamatAllKurir(ListKurir L, string alamat) {
    addressK K = L.first;
    bool ditemukan = false;

    while (K != nullptr) {
        addressP P = K->firstP;

        while (P != nullptr) {
            if (P->info.alamat == alamat) {
                if (!ditemukan) {
                    cout << "Daftar paket dengan alamat \""
                         << alamat << "\":\n";
                    cout << "================================\n";
                }

                ditemukan = true;
                cout << "ID Kurir   : " << K->info.id << endl;
                cout << "Nama Kurir : " << K->info.nama << endl;
                cout << "ID Paket   : " << P->info.idPaket << endl;
                cout << "Penerima   : " << P->info.namaPenerima << endl;
                cout << "Alamat     : " << P->info.alamat << endl;
                cout << "--------------------------------\n";
            }
            P = P->next;
        }
        K = K->next;
    }

    if (!ditemukan) {
        cout << "Tidak ditemukan paket dengan alamat tersebut\n";
    }
}


