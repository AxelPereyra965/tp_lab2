#include "CostoAgregadoManager.h"
#include <iostream>
using namespace std;

CostoAgregado CostoAgregadoManager :: CargarAvio()
{
    CostoAgregado obj;
    float costo_packaging;
    float costo_etiqueta;

    system("cls");
    cout << "DEFINA LOS COSTOS DE AVIOS PARA LAS PRENDAS" << endl;
    cout << "------------------------------" << endl << endl;
    cout << "COSTO DEL PACKAGING";
    cin >> costo_packaging;
    obj.setPackaging(costo_packaging);
    cout << endl;
    cout << "COSTO DE LA ETIQUETA";
    cin >> costo_etiqueta;
    obj.setEtiqueta(costo_etiqueta);
    cout << endl;
    HayGuardado = true;

    return obj;
}

void CostoAgregadoManager :: GuardarAvio()
{
    CostoAgregadoArchivo Arch;
    bool Sobrescribir;

    if(!HayGuardado)
    {
        if(Arch.GuardarCA(CargarAvio()))
        {
            cout << "CONFIGURACION GUARDADA" << endl;
            system("pause");
            system("cls");
        }
    }else
    {
        cout << "YA HAY AVIOS PREDEFINIDOS, DESEA SOBREESCRIBIRLOS? 1 - SI 0 - NO";
        cin >> Sobrescribir;
        if(Sobrescribir)
        {
                if(Arch.GuardarCA(CargarAvio()))
            {
                cout << "CONFIGURACION GUARDADA" << endl;
                system("pause");
                system("cls");
            }
        }else
        {
            return;
        }
    }
}
