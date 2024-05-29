#include "CostoAgregadoArchivo.h"
#include <iostream>
using namespace std;


bool CostoAgregadoArchivo :: GuardarCA(CostoAgregado obj)
{
    FILE *p;
    bool Escritura;

    p = fopen("COSTOS.DAT", "ab");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR" << endl;
        return false;
    }
    Escritura = fwrite(&obj, sizeof(CostoAgregado), 1, p);
    fclose(p);
    return Escritura;
}

CostoAgregado CostoAgregadoArchivo :: LeerCA(int indice)
{
    FILE *p;

    p = fopen("COSTOS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR" << endl;
        return obj;
    }

    fseek(p, sizeof(CostoAgregado) * indice, SEEK_SET);
    fread(&obj, sizeof(CostoAgregado), 1, p);
    fclose(p);
    return obj;
}

int CostoAgregadoArchivo :: ContarRegistrosCA()
{
    FILE *p;
    int tam;

    p = fopen("COSTOS.DAT", "rb");
    if(p == nullptr)
    {
         cout << "NO PUDO ABRIR" << endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    tam = ftell(p) / sizeof(CostoAgregado);
    return tam;
}
