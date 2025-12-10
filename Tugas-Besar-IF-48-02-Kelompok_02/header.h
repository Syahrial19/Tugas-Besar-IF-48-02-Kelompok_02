#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
struct Paket;

struct Kurir {
    string id;
    string nama;
    int umur;
    Paket* childHead;
    Kurir* next;
    Kurir* prev;
};

typedef Kurir* adrKurir;

struct ListKurir {
    adrKurir first;
    adrKurir last;
};
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
void createListKurir(ListKurir &L);
adrKurir createKurir(string id, string nama, int umur);
void insertKurir(ListKurir &L, adrKurir P);
adrKurir findKurir(ListKurir L, string id);
void deleteKurir(ListKurir &L, string id);
void showAllKurir(ListKurir L);
void createListPaket(ListPaket &L);
adrPaket createPaket(string idPaket, string namaPenerima, string alamat);
void addPaketToKurir(Kurir* K, adrPaket P);
adrPaket findPaketInKurir(Kurir* K, string idPaket);
void deletePaketFromKurir(Kurir* K, string idPaket);
void showPaketOfKurir(Kurir* K);


#endif // HEADER_H_INCLUDED
