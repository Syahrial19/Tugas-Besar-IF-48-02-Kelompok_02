#include <iostream>
#include "header.h"
using namespace std;

void menuUser() {
    int opsi = -1;
    string idK, idP;
    addressK K;
    ListKurir L;
    while (opsi != 0) {
        system("cls");
        cout << "=========== MENU STUDI KASUS ===========\n";
        cout << "1. Tambah Kurir \n";
        cout << "2. Hapus Kurir TANPA paket\n";
        cout << "5. Cari Kurir berdasarkan ID\n";
        cout << "6. Hitung total paket kurir\n";
        cout << "7. Kurir dengan paket terbanyak\n";
        cout << "8. Tampilkan semua kurir\n";
        cout << "0. Kembali\n";
        cout << "Pilih menu: ";
        cin >> opsi;

        switch (opsi) {

        case 1: { // Insert parent kondisi
            string nama;
            int umur;

            cout << "ID Kurir : "; cin >> idK;
            cout << "Nama     : "; cin >> nama;
            cout << "Umur     : "; cin >> umur;

            if (umur >= 21) {
                K = createKurir(idK, nama, umur);
                insertLastKurir(L, K);
                cout << "Kurir berhasil ditambahkan\n";
            } else {
                cout << "Gagal! Umur Kurang dari 21\n";
            }
            break;
        }

        case 2: { // Delete parent kondisi
            bool ketemu = false;
            K = L.first;

            while (K != nullptr) {
                if (countPaket(K) == 0) {
                    addressK hapus;
                    deleteFirstKurir(L, hapus);
                    cout << "Kurir tanpa paket berhasil dihapus\n";
                    ketemu = true;
                    break;
                }
                K = K->next;
            }

            if (!ketemu) {
                cout << "Tidak ada kurir tanpa paket\n";
            }
            break;
        }

        case 5: { // Searching kondisi
            cout << "Masukkan ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                cout << "Kurir ditemukan\n";
                cout << "Nama : " << K->info.nama << endl;
                cout << "Umur : " << K->info.umur << endl;
            } else {
                cout << "Kurir tidak ditemukan\n";
            }
            break;
        }

        case 6: { // Komputasi 1
            cout << "Masukkan ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                cout << "Total paket kurir: "
                     << countPaket(K) << endl;
            } else {
                cout << "Kurir tidak ditemukan\n";
            }
            break;
        }

        case 7: { // Komputasi 2
            addressK maxKurir = nullptr;
            int maxPaket = -1;

            K = L.first;
            while (K != nullptr) {
                int jml = countPaket(K);
                if (jml > maxPaket) {
                    maxPaket = jml;
                    maxKurir = K;
                }
                K = K->next;
            }

            if (maxKurir) {
                cout << "Kurir tersibuk\n";
                cout << "Nama : " << maxKurir->info.nama << endl;
                cout << "Total Paket : " << maxPaket << endl;
            } else {
                cout << "Data kurir kosong\n";
            }
            break;
        }

        case 8: // Show parent
            showAllKurir(L);
            break;
        }

        system("pause");
    }
}
