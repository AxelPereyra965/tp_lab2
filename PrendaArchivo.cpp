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
        cout << "NO PUDO ABRIR" << endl;
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
        cout << "NO PUDO ABRIR" << endl;
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
         cout << "NO PUDO ABRIR" << endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    tam = ftell(p) / sizeof(Prenda);
    return tam;
}
