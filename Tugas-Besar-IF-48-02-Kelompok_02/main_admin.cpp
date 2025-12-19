#include <iostream>
#include "header.h"
#include "main.h"
using namespace std;

void menuAdmin(ListKurir &L) {

    string idK, namaK, idP, penerima, alamat;
    int umur;
    addressK K, precK, hapusK;
    addressP P, precP, hapusP;

    int opsi;

    while (true) {
        cout << "\n===== MENU ADMIN KURIR & PAKET =====\n";
        cout << "1. Tambah Kurir (insert first)\n";
        cout << "2. Tambah Kurir (insert last)\n";
        cout << "3. Tambah Kurir (insert after)\n";
        cout << "4. Hapus Kurir (delete first)\n";
        cout << "5. Hapus Kurir (delete last)\n";
        cout << "6. Hapus Kurir (delete after)\n";
        cout << "7. Cari Kurir\n";
        cout << "8. Tampilkan Semua Kurir\n";

        cout << "\n=== MENU PAKET ===\n";
        cout << "9. Tambah Paket (insert first)\n";
        cout << "10. Tambah Paket (insert last)\n";
        cout << "11. Tambah Paket (insert after)\n";
        cout << "12. Hapus Paket (delete first)\n";
        cout << "13. Hapus Paket (delete last)\n";
        cout << "14. Hapus Paket (delete after)\n";
        cout << "15. Cari Paket\n";
        cout << "16. Tampilkan Semua Paket dari Kurir\n";

        cout << "\n0. Keluar\n";
        cout << "Opsi: ";
        cin >> opsi;

        switch (opsi) {

        case 1:
            cout << "ID Kurir : "; cin >> idK;
            cout << "Nama     : "; cin >> namaK;
            cout << "Umur     : "; cin >> umur;

            K = createKurir(idK, namaK, umur);
            insertFirstKurir(L, K);
            cout << "Kurir berhasil ditambahkan.\n";
            break;

        case 2:
            cout << "ID Kurir : "; cin >> idK;
            cout << "Nama     : "; cin >> namaK;
            cout << "Umur     : "; cin >> umur;

            K = createKurir(idK, namaK, umur);
            insertLastKurir(L, K);
            cout << "Kurir berhasil ditambahkan.\n";
            break;

        case 3:
            cout << "ID Kurir yang dituju: ";
            cin >> idK;

            precK = findKurir(L, idK);
            if (precK != nullptr) {
                cout << "ID Kurir baru : "; cin >> idK;
                cout << "Nama Kurir    : "; cin >> namaK;
                cout << "Umur          : "; cin >> umur;

                K = createKurir(idK, namaK, umur);
                insertAfterKurir(L, precK, K);
                cout << "Insert-after berhasil.\n";
            } else {
                cout << "Kurir tidak ditemukan.\n";
            }
            break;

        case 4:
            deleteFirstKurir(L, hapusK);
            if (hapusK) {
                cout << "Kurir dihapus: " << hapusK->info.nama << endl;
            } else {
                cout << "List kosong.\n";
            }
            break;

        case 5:
            deleteLastKurir(L, hapusK);
            if (hapusK) {
                cout << "Kurir dihapus: " << hapusK->info.nama << endl;
            } else {
                cout << "List kosong.\n";
            }
            break;

        case 6:
            cout << "ID Kurir yang dituju: ";
            cin >> idK;

            precK = findKurir(L, idK);
            if (precK) {
                deleteAfterKurir(L, precK, hapusK);
                if (hapusK) {
                    cout << "Kurir dihapus: " << hapusK->info.nama << endl;
                } else {
                    cout << "Tidak ada kurir setelah yang dituju.\n";
                }
            } else {
                cout << "Kurir tidak ditemukan.\n";
            }
            break;

        case 7:
            cout << "Masukkan ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                cout << "ID   : " << K->info.id << endl;
                cout << "Nama : " << K->info.nama << endl;
                cout << "Umur : " << K->info.umur << endl;
            } else {
                cout << "Kurir tidak ditemukan.\n";
            }
            break;

        case 8:
            showAllKurir(L);
            break;

        case 9:
            cout << "ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                cout << "ID Paket: "; cin >> idP;
                cout << "Nama Penerima: "; cin >> penerima;
                cout << "Alamat: "; cin >> alamat;

                P = createPaket(idP, penerima, alamat);
                insertFirstPaket(K, P);

                cout << "Paket berhasil ditambahkan.\n";
            } else {
                cout << "Kurir tidak ditemukan.\n";
            }
            break;

        case 10:
            cout << "ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                cout << "ID Paket: "; cin >> idP;
                cout << "Nama Penerima: "; cin >> penerima;
                cout << "Alamat: "; cin >> alamat;

                P = createPaket(idP, penerima, alamat);
                insertLastPaket(K, P);

                cout << "Paket berhasil ditambahkan.\n";
            } else {
                cout << "Kurir tidak ditemukan.\n";
            }
            break;

        case 11:
            cout << "ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                cout << "ID Paket yang dituju: ";
                cin >> idP;

                precP = findPaket(K, idP);
                if (precP) {
                    cout << "ID Paket baru: "; cin >> idP;
                    cout << "Nama Penerima: "; cin >> penerima;
                    cout << "Alamat: "; cin >> alamat;

                    P = createPaket(idP, penerima, alamat);
                    insertAfterPaket(K, precP, P);

                    cout << "Insert-after berhasil.\n";
                } else {
                    cout << "Paket yang dituju tidak ditemukan.\n";
                }
            }
            break;

        case 12:
            cout << "ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                deleteFirstPaket(K, hapusP);
                if (hapusP) {
                    cout << "Paket dihapus: " << hapusP->info.idPaket << endl;
                } else {
                    cout << "List paket kosong.\n";
                }
            }
            break;

        case 13:
            cout << "ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                deleteLastPaket(K, hapusP);
                if (hapusP) {
                    cout << "Paket dihapus: " << hapusP->info.idPaket << endl;
                } else {
                    cout << "List paket kosong.\n";
                }
            }
            break;

        case 14:
            cout << "ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                cout << "ID Paket yang dituju: ";
                cin >> idP;

                precP = findPaket(K, idP);
                if (precP) {
                    deleteAfterPaket(K, precP, hapusP);
                    if (hapusP) {
                        cout << "Paket dihapus: " << hapusP->info.idPaket << endl;
                    } else {
                        cout << "Tidak ada paket setelah yang dituju.\n";
                    }
                }
            }
            break;

        case 15:
            cout << "ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                cout << "ID Paket: ";
                cin >> idP;

                P = findPaket(K, idP);
                if (P) {
                    cout << "ID Paket     : " << P->info.idPaket << endl;
                    cout << "Nama Penerima: " << P->info.namaPenerima << endl;
                    cout << "Alamat       : " << P->info.alamat << endl;
                } else {
                    cout << "Paket tidak ditemukan.\n";
                }
            }
            break;

        case 16:
            cout << "ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                showPaketOfKurir(K);
            }
            break;

        case 0:
            return ;

        default:
            cout << "Opsi tidak valid.\n";
        }
    }
}
