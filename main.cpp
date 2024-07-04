#include <iostream>
#include <windows.h>
#include "Menus.h"

using namespace std;

void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
//prueba
int main() {
    SetColor(10);
    int opcion;

    do {
        system("cls");
        cout << "     MENU PRINCIPAL" << endl;
        cout << "------------------------" << endl;
        cout << endl;
        cout << "1)     PRENDA" << endl;
        cout << endl;
        cout << "2)    INVENTARIO" << endl;
        cout << endl;
        cout << "3)    ESTADISTICAS" << endl;
        cout << endl;
        cout << "------------------------" << endl;
        cout << endl;
        cout << "0)       SALIR" << endl;

        while (!(cin >> opcion)) { //por si se ingresa una letra
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el input incorrecto
            system("cls");
            cout << "por favor ingrese solo numeros...."<<endl;
            system("pause");
            system("cls");
             cout << "     MENU PRINCIPAL" << endl;
             cout << "------------------------" << endl;
             cout << endl;
             cout << "1)     PRENDA" << endl;
             cout << endl;
             cout << "2)    INVENTARIO" << endl;
             cout << endl;
             cout << "3)    ESTADISTICAS" << endl;
             cout << endl;
             cout << "------------------------" << endl;
             cout << endl;
             cout << "0)       SALIR" << endl;
        }

        switch (opcion) {
            case 1:
                Menu1();
                break;
            case 2:
                Menu2();
                break;
            case 3:
                Menu3();
                break;
            case 0:
                return 0;
            default:
                cout << "OPCION INCORRECTA" << endl;
                system("pause");
                break;
        }

    } while (true);

    return 0;
}

