#include "PrendaArchivo.h"
#include <iostream>
using namespace std;

bool PrendaArchivo :: GuardarPrenda(Prenda obj)
{
    FILE *p;
    bool Escritura;

    p = fopen("PRENDAS.DAT", "ab");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR GUARDAR PRENDA "<< endl;
        return false;
    }
    Escritura = fwrite(&obj, sizeof(Prenda), 1, p);
    fclose(p);
    return Escritura;
}

Prenda PrendaArchivo :: LeerPrenda(int indice)
{
    FILE *p;

    p = fopen("PRENDAS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR LEER PRENDA" << endl;
        return obj;
    }

    fseek(p, sizeof(Prenda) * indice, SEEK_SET);
    fread(&obj, sizeof(Prenda), 1, p);
    fclose(p);
    return obj;
}

int PrendaArchivo :: ContarRegistrosPrenda()
{
    FILE *p;
    int tam;

    p = fopen("PRENDAS.DAT", "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, SEEK_END);
    tam = ftell(p) / sizeof(Prenda);
    return tam;
}

int PrendaArchivo :: NuevoCodigoPrenda()
{
    int cantidad = ContarRegistrosPrenda();

    if(cantidad > 0)
    {
        return LeerPrenda(cantidad - 1).getCodigo() + 1;
    }else
    {
        return 1;
    }
}

int PrendaArchivo :: BuscarCodigoPrenda(int Cod)
{
    FILE *p;
    int pos = 0;

    p = fopen("PRENDAS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        return -1;
    }
    while(fread(&obj, sizeof(Prenda), 1, p) == 1)
    {
        if(obj.getCodigo() == Cod)
        {
            fclose(p);
            return pos;
        }
        pos ++;
    }
    fclose(p);
    return -2;
}

bool PrendaArchivo :: SobreescribirArchivoPrenda(int indice, Prenda pren)
{
    bool Resultado;
    FILE *p;

    p = fopen("PRENDAS.DAT", "rb+");
    if(p == nullptr)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }
    fseek(p, sizeof(Prenda) * indice, SEEK_SET);
    Resultado = fwrite(&pren, sizeof(Prenda), 1, p);
    fclose(p);
    return Resultado;
}
