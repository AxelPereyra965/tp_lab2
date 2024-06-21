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
        cout << "NO PUDO ABRIR GUARDADO" << endl;
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
        cout << "NO PUDO ABRIR LECTURA" << endl;
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
        //cout << "NO PUDO ABRIR CONTADOR" << endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    tam = ftell(p) / sizeof(Venta);
    fclose(p);
    return tam;
}

int VentaArchivo :: NuevoCodigoDeVenta()
{
    int cantidad = ContarRegistrosVenta();

    if(cantidad > 0)
    {
        return LeerVenta(cantidad - 1).getCodigoVenta() + 1;
    }else
    {
        return 1;
    }
}
bool VentaArchivo:: SobreescribirArchivoVenta(int indice, Venta ven)
{
    bool Resultado;
    FILE *p;

    p = fopen("VENTAS.DAT", "rb+");
    if(p == nullptr)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }
    fseek(p, sizeof ven * indice, SEEK_SET);//te posiciona en el obj
    Resultado = fwrite(&ven, sizeof ven, 1, p); //sobre escribis
    fclose(p);
    return Resultado;
}
