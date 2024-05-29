#include "VentaArchivo.h"
#include <iostream>
using namespace std;

bool VentaArchivo :: GuardarVenta(Venta obj)
{
    FILE *p;
    bool Escritura;

    p = fopen("VENTAS.DAT", "ab");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR" << endl;
        return false;
    }
    Escritura = fwrite(&obj, sizeof(Venta), 1, p);
    fclose(p);
    return Escritura;
}

Venta VentaArchivo :: LeerVenta(int indice)
{
    FILE *p;

    p = fopen("VENTAS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR" << endl;
        return obj;
    }

    fseek(p, sizeof(Venta) * indice, SEEK_SET);
    fread(&obj, sizeof(Venta), 1, p);
    fclose(p);
    return obj;
}

int VentaArchivo :: ContarRegistrosVenta()
{
    FILE *p;
    int tam;

    p = fopen("VENTAS.DAT", "rb");
    if(p == nullptr)
    {
         cout << "NO PUDO ABRIR" << endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    tam = ftell(p) / sizeof(Venta);
    return tam;
}
