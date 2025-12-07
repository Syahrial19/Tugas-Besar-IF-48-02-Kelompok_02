

void createListPaket(ListPaket &L) {
    L.first = nullptr;
}

adrPaket createPaket(string idPaket, string namaPenerima, string alamat) {
    adrPaket P = new Paket;
    P->idPaket = idPaket;
    P->namaPenerima = namaPenerima;
    P->alamat = alamat;

    P->next = nullptr;
    P->parent = nullptr;

    return P;
}
