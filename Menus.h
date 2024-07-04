#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;
#include "PrendaManager.h"
#include "VentaManager.h"

//      MENU DE PRENDA

PrendaManager ManagerPrend; //creamos los objetos que usaremos para llamar a las funciones
VentaManager ManagerVent;

void Menu1()

{
     int opcion;
   bool Error = false;
    while (Error != true){
        system("cls");
        cout << "         PRENDAS" << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "1)    CARGAR PRENDA" << endl;
        cout << endl;
        cout << "2)   MODIFICAR PRENDA" << endl;
        cout << endl;
        cout << "3)   ELIMINAR PRENDA" << endl;
        cout << endl;
        cout << "4)    CARGAR VENTA" << endl;
        cout << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "0)   MENU ANTERIOR" << endl;

        cin >> opcion;

        switch(opcion){
            case 1:
                {
                    ManagerPrend.SubmenuCargarPrenda();
                    Error = true;
                }
                break;
            case 2:
                {
                    ManagerPrend.SubmenuModificarPrenda();
                    Error = true;
                }
                break;
            case 3:
                {
                    ManagerPrend.SubmenuEliminarPrenda();
                    Error = true;
                    system("pause");
                }
                break;
            case 4:
                {
                    ManagerVent.SubMenuCargarVenta();
                    Error = true;
                    system("pause");
                }
                break;
            case 0:
                {
                    return;
                }
                break;
            default:
                 cout << "OPCION INCORRECTA. INDIQUE NUEVAMENTE ALGUNA DE LAS OPCIONES." << endl;
                    system("pause");
                    system("cls");
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "DEBES TOCAR CUALQUIER TECLA PARA VOLVER E INTENTARLO DE NUEVO" << endl;
                    system("pause");
                }
                break;
        }

    }
}

//          MENU DE INVENTARIO

void Menu2()
{
    int opcion;
    bool Error = false;
    while (Error != true){
        system("cls");
        cout << "       INVENTARIO" << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        cout << "1)    VER INVENTARIO" << endl;
        cout << endl;
        cout << "2)   DETALLES DE PRENDA" << endl;
        cout << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "0)    MENU ANTERIOR" << endl;

        cin >> opcion;

        switch(opcion){
            case 1:
                {
                   ManagerPrend.SubmenuInventario();
                   Error = true;
                   system("pause");
                }
                break;
            case 2:
                {
                    ManagerPrend.SubmenuDetalleDePrenda();
                    Error = true;
                    system("pause");
                }
                break;
            case 0:
                {
                    return;
                }
                break;
            default:
                 cout << "OPCION INCORRECTA. INDIQUE NUEVAMENTE ALGUNA DE LAS OPCIONES." << endl;
                    system("pause");
                    system("cls");
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "DEBES TOCAR CUALQUIER TECLA PARA VOLVER E INTENTARLO DE NUEVO" << endl;
                    system("pause");
                }
                break;
        }

    }
}

//              MENU DE ESTADISTICAS

void Menu3()
{
    int opcion;
    bool Error = false;
    while (Error != true){
        system("cls");
        cout << "      ESTADISTICA" << endl;
        cout << "-------------------------" << endl;
        cout << endl;
        cout << "1)  VER PRODUCTOS MAS VENDIDOS" << endl;
        cout << endl;
        cout << "2)   HISTORIAL DE VENTA" << endl;
        cout << endl;
        cout << "3)  PORCENTAJE DE GANANCIAS POR MES" << endl;
        cout << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "0)    MENU ANTERIOR" << endl;

        cin >> opcion;
        switch(opcion){
            case 1:
                {
                    ManagerVent.SubMenuEstadisticaProductos();
                    Error = true;
                    system("pause");
                }
                break;
            case 2:
                {
                    ManagerVent.SubMenuHistorialDeVenta();
                    Error = true;
                    system("pause");
                }
                break;
            case 3:
                {
                    ManagerVent.SubMenuPorcentaDeInversion();
                    Error = true;
                    system("pause");
                }
                break;
            case 0:
                {
                    return;
                }
                break;
            default:
                system("cls");
                    cout << "OPCION INCORRECTA. INDIQUE NUEVAMENTE ALGUNA DE LAS OPCIONES." << endl;
                    //system("pause");

                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout <<endl<< "DEBES TOCAR CUALQUIER TECLA PARA VOLVER E INTENTARLO DE NUEVO" << endl;
                    system("pause");
                }
                break;
        }

    }
}

#endif // TALLER_H_INCLUDED
