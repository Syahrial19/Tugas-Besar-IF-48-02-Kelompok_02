#include <iostream>
#include "header.h"
#include "main.h"
using namespace std;

void menuUser(ListKurir &L) {
    int opsi = -1;
    string idK;
    addressK K;

    while (opsi != 0) {
        system("cls");
        cout << "=========== MENU STUDI KASUS ===========\n";
        cout << "1. Tambah Kurir dengan minimal umur \n";
        cout << "2. Hapus Kurir TANPA paket\n";
        cout << "3. Cari Kurir berdasarkan ID\n";
        cout << "4. Hitung total paket kurir\n";
        cout << "5. Kurir dengan paket terbanyak\n";
        cout << "6. Tampilkan semua kurir & paket\n";
        cout << "7. Tambah Paket ke Kurir dengan Paket Paling Sedikit\n";
        cout << "8. Hapus paket berdasarkan alamat tertentu \n";
        cout << "9. Tampilkan paket berdasarkan alamat tertentu\n";
        cout << "0. Kembali\n";
        cout << "Pilih menu: ";
        cin >> opsi;

        switch (opsi) {

        case 1: {
            string nama;
            int umur;

            cout << "ID Kurir : "; cin >> idK;
            cout << "Nama     : "; cin >> nama;
            cout << "Umur     : "; cin >> umur;

            if (umur >= 21) {
                insertLastKurir(L, createKurir(idK, nama, umur));
                cout << "Kurir berhasil ditambahkan\n";
            } else {
                cout << "Gagal! Umur Kurang dari 21\n";
            }
            break;
        }

        case 2: {
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

        case 3: {
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

        case 4: {
            cout << "Masukkan ID Kurir: ";
            cin >> idK;

            K = findKurir(L, idK);
            if (K) {
                cout << "Total paket kurir: " << countPaket(K) << endl;
            } else {
                cout << "Kurir tidak ditemukan\n";
            }
            break;
        }

        case 5: {
            addressK maxKurir = nullptr;
            int maxPaket = -1;

            for (K = L.first; K != nullptr; K = K->next) {
                int jml = countPaket(K);
                if (jml > maxPaket) {
                    maxPaket = jml;
                    maxKurir = K;
                }
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

        case 6: {
            if (L.first == nullptr) {
                cout << "Data kurir kosong\n";
            } else {
                for (K = L.first; K != nullptr; K = K->next) {
                    cout << "================================\n";
                    cout << "ID Kurir : " << K->info.id << endl;
                    cout << "Nama     : " << K->info.nama << endl;
                    cout << "Umur     : " << K->info.umur << endl;
                    cout << "Daftar Paket:\n";
                    showPaketOfKurir(K);
                }
            }
            break;
        }
        case 7: {
            if (L.first == nullptr) {
                cout << "Belum ada kurir\n";
                break;
            }
                string idP, penerima, alamat;
                cout << "ID Paket       : "; cin >> idP;
                cout << "Nama Penerima  : "; cin >> penerima;
                cout << "Alamat         : "; cin >> alamat;

                addressK target = findKurirPaketTersedikit(L);

            if (target != nullptr) {
                addressP P = createPaket(idP, penerima, alamat);
                insertLastPaket(target, P);
                cout << "Paket berhasil ditambahkan ke kurir:\n";
                cout << "ID   : " << target->info.id << endl;
                cout << "Nama : " << target->info.nama << endl;
                cout << "Total Paket Sekarang: "
                << countPaket(target) << endl;
            }

            break;
    }

        case 8: {
            if (L.first == nullptr) {
            cout << "Belum ada data kurir\n";
            break;
    }
            string alamat;
            cout << "Masukkan alamat pengiriman yang akan dihapus: ";
            cin >> alamat;
            deletePaketByAlamatAllKurir(L, alamat);

    break;
}
            case 9: {
            if (L.first == nullptr) {
            cout << "Belum ada data kurir\n";
            break;
    }

            string alamat;
            cout << "Masukkan alamat pengiriman: ";
            cin >> alamat;
            showPaketByAlamatAllKurir(L, alamat);
            break;
}

        }

        if (opsi != 0) system("pause");
    }
}
