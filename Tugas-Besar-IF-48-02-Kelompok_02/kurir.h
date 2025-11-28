#ifndef KURIR_H_INCLUDED
#define KURIR_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Paket;

struct Kurir {
    string id;
    string nama;
    string umur;

    Paket* childHead;

    Kurir* next;
    Kurir* prev;
};

typedef Kurir* adrKurir;

struct ListKurir {
    adrKurir first;
    adrKurir last;
};

void createListKurir(ListKurir &L);
adrKurir createKurir(string id, string nama);
void insertKurir(ListKurir &L, adrKurir P);
adrKurir findKurir(ListKurir L, string id);
void deleteKurir(ListKurir &L, string id);
void showAllKurir(ListKurir L);

#endif
