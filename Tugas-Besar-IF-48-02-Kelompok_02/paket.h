#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Kurir;
struct Paket {
    string idPaket;
    string namaPenerima;
    string alamat;
    Paket* next;
    Kurir* parent;
};
typedef Paket* adrPaket;
struct ListPaket {
    adrPaket first;
};

void createListPaket(ListPaket &L);
adrPaket createPaket(string idPaket, string namaPenerima, string alamat);
void addPaketToKurir(Kurir* K, adrPaket P);
adrPaket findPaketInKurir(Kurir* K, string idPaket);
void deletePaketFromKurir(Kurir* K, string idPaket);
void showPaketOfKurir(Kurir* K);

#endif
