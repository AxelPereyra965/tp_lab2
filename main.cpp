#include <iostream>
#include "Menus.h"

using namespace std;

int main()
{
    int opcion;
    while (true){
        system("cls");
        cout << "MENU PRINCIPAL" << endl;
        cout << "----------------" << endl;
        cout << "1) PRENDA" << endl;
        cout << "2) INVENTARIO" << endl;
        cout << "3) ESTADISTICAS" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;

        switch(opcion){
            case 1:
                {
                    Menu1();
                }
                break;
            case 2:
                {
                    Menu2();
                }
                break;
            case 3:
                {
                    Menu3();
                }
                break;
            case 0:
                {
                    return 0;
                }
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
            break;
        }

    }
}
