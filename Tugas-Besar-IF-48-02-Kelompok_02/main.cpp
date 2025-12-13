#include <iostream>
#include "main.h"

using namespace std;

int main() {
    int option = -99;

    while (option != 0) {
        system("cls");
        cout << "============ Menu ============\n";
        cout << "|| 1. Test Case             ||\n";
        cout << "|| 2. Study Case            ||\n";
        cout << "|| 0. Exit                  ||\n";
        cout << "==============================\n";
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Kamu Memilih Test Case\n";
                menuAdmin();   // ADMIN / TEST CASE
                break;

            case 2:
                cout << "Kamu Memilih Study Case\n";
                menuUser();    // USER / STUDY CASE
                break;

            case 0:
                cout << "Terima kasih.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
                system("pause");
                break;
        }
    }

    return 0;
}
