#ifndef KURIR_H_INCLUDED
#define KURIR_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

typedef struct dataKurir infotypeK;
typedef struct elmKurir *addressK;

typedef struct dataPaket infotypeP;
typedef struct elmPaket *addressP;


// data kurir
struct dataKurir {
    string id;
    string nama;
    int umur;
};

struct elmKurir {
    infotypeK info;
    addressP firstP;
    addressK next;
    addressK prev;
};

struct ListKurir {
    addressK first;
    addressK last;
};


// data paket
struct dataPaket {
    string idPaket;
    string namaPenerima;
    string alamat;
};

struct elmPaket {
    infotypeP info;
    addressP next;
};


// kurir
void createListKurir(ListKurir &L);
addressK createKurir(string id, string nama, int umur);
bool isEmptyKurir(ListKurir L);

void insertFirstKurir(ListKurir &L, addressK K);
void insertLastKurir(ListKurir &L, addressK K);
void insertAfterKurir(ListKurir &L, addressK prec, addressK K);

void deleteFirstKurir(ListKurir &L, addressK &P);
void deleteLastKurir(ListKurir &L, addressK &P);
void deleteAfterKurir(ListKurir &L, addressK prec, addressK &P);

addressK findKurir(ListKurir L, string id);
void showAllKurir(ListKurir L);

int countKurir(ListKurir L);
addressK findKurirPaketTersedikit(ListKurir L);

// paket
addressP createPaket(string idPaket, string namaPenerima, string alamat);
bool isEmptyPaket(addressK K);

void insertFirstPaket(addressK K, addressP P);
void insertLastPaket(addressK K, addressP P);
void insertAfterPaket(addressK K, addressP prec, addressP P);

void deleteFirstPaket(addressK K, addressP &P);
void deleteLastPaket(addressK K, addressP &P);
void deleteAfterPaket(addressK K, addressP prec, addressP &P);

addressP findPaket(addressK K, string idPaket);
void showAllPaket(addressK K);
void showPaketOfKurir(addressK K);
int countPaket(addressK K);
void deletePaketByAlamatAllKurir(ListKurir &L, string alamat);
void showPaketByAlamatAllKurir(ListKurir L, string alamat);


#endif
