#include <iostream>
#include "header.h"
#include "main.h"

using namespace std;

int main() {
    int option = -99;

    ListKurir L;
    createListKurir(L);

    while (option != 0) {
        system("cls");
        cout << "============ Menu ============\n";
        cout << "|| 1. Test Case (Admin)     ||\n";
        cout << "|| 2. Study Case (User)     ||\n";
        cout << "|| 0. Exit                  ||\n";
        cout << "==============================\n";
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
            case 1:
                menuAdmin(L);
                break;

            case 2:
                menuUser(L);
                break;

            case 0:
                cout << "Terima kasih.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
                system("pause");
        }
    }
    return 0;
}
