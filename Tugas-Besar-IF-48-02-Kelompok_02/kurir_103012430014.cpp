void createListKurir(ListKurir &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrKurir createKurir(string id, string nama, int umur) {
    adrKurir K = new Kurir;
    K->id = id;
    K->nama = nama;
    K->umur = umur;
    K->childHead = nullptr;   // belum punya paket

    K->next = nullptr;
    K->prev = nullptr;

    return K;
}
void insertKurir(ListKurir &L, adrKurir P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

