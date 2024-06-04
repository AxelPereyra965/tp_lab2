#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "PrendaManager.h"
#include "VentaManager.h"
#include <iostream>
using namespace std;

//      MENU DE PRENDA

PrendaManager obj_de_submenu_prenda;

void Menu1()

{
     int opcion;
    while (true){
        system("cls");
        cout << "PRENDAS" << endl;
        cout << "----------------" << endl;
        cout << "1) CARGAR PRENDA" << endl;
        cout << "2) MODIFICAR PRENDA" << endl;
        cout << "3) ELIMINAR PRENDA" << endl;
        cout << "4) CARGAR VENTA" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;

        switch(opcion){
            case 1:
                {
                    obj_de_submenu_prenda.SubmenuCargarPrenda();
                }
                break;
            case 2:
                {
                    obj_de_submenu_prenda.SubmenuModificarPrenda();
                }
                break;
            case 3:
                {
                    obj_de_submenu_prenda.SubmenuEliminarPrenda();
                    system("pause");
                }
                break;
            case 4:
                {
                    //CARGAR VENTA
                }
                break;
            case 0:
                {
                    return;
                }
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
            break;
        }

    }
}

//          MENU DE INVENTARIO

void Menu2()
{
    int opcion;
    while (true){
        system("cls");
        cout << "INVENTARIO" << endl;
        cout << "----------------" << endl;
        cout << "1) VER INVENTARIO" << endl;
        cout << "2) DETALLES DE PRENDA" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;

        switch(opcion){
            case 1:
                {
                   obj_de_submenu_prenda.SubmenuInventario();
                   system("pause");
                }
                break;
            case 2:
                {
                    //DETALLES DE PRENDA
                }
                break;
            case 0:
                {
                    return;
                }
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
            break;
        }

    }
}

//              MENU DE ESTADISTICAS

void Menu3()
{
    int opcion;
    while (true){
        system("cls");
        cout << "ESTADISTICA" << endl;
        cout << "----------------" << endl;
        cout << "1) ESTADISTICAS DE PRODUCTOS" << endl;
        cout << "2) HISTORIAL DE VENTA" << endl;
        cout << "3) PORCENTAJE DE GANANCIAS CON RESPECTO A LAS VENTAS DEL AÑO " << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;

        switch(opcion){
            case 1:
                {

                }
                break;
            case 2:
                {

                }
                break;
            case 3:
                {

                }
                break;
            case 0:
                {
                    return;
                }
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
            break;
        }

    }
}

#endif // TALLER_H_INCLUDED
