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

    do{
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

        while (!(cin >> opcion)) { //por si se ingresa una letra
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el input incorrecto
            system("cls");
            cout << "por favor ingrese solo numeros...."<<endl;
            system("pause");
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
        }

        switch(opcion){
            case 1:
                {
                    ManagerPrend.SubmenuCargarPrenda();
                }
                break;
            case 2:
                {
                    ManagerPrend.SubmenuModificarPrenda();
                }
                break;
            case 3:
                {
                    ManagerPrend.SubmenuEliminarPrenda();
                    system("pause");
                }
                break;
            case 4:
                {
                    ManagerVent.SubMenuCargarVenta();
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
                break;
        }

    }while(true);
}

//          MENU DE INVENTARIO

void Menu2()
{
    int opcion;

    do{
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

        while (!(cin >> opcion)) { //por si se ingresa una letra
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el input incorrecto
            system("cls");
            cout << "por favor ingrese solo numeros...."<<endl;
            system("pause");
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
        }

        switch(opcion){
            case 1:
                {
                   ManagerPrend.SubmenuInventario();
                   system("pause");
                }
                break;
            case 2:
                {
                    ManagerPrend.SubmenuDetalleDePrenda();
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
                break;
        }

    }while(true);
}

//              MENU DE ESTADISTICAS

void Menu3()
{
    int opcion;

    do{
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

        while (!(cin >> opcion)) { //por si se ingresa una letra
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el input incorrecto
            system("cls");
            cout << "por favor ingrese solo numeros...."<<endl;
            system("pause");
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
        }

        switch(opcion){
            case 1:
                {
                    ManagerVent.SubMenuEstadisticaProductos();
                    system("pause");
                }
                break;
            case 2:
                {
                    ManagerVent.SubMenuHistorialDeVenta();
                    system("pause");
                }
                break;
            case 3:
                {
                    ManagerVent.SubMenuPorcentaDeInversion();
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
                    system("pause");
                    system("cls");
                break;
        }

    }while(true);
}

#endif // TALLER_H_INCLUDED
