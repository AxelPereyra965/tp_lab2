#include "TallerArchivo.h"
#include <iostream>
using namespace std;

bool TallerArchivo :: GuardarTaller(Taller obj)
{
    FILE *p;
    bool Escritura;

    p = fopen("TALLER.DAT", "ab");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR" << endl;
        return false;
    }
    Escritura = fwrite(&obj, sizeof(Taller), 1, p);
    fclose(p);
    return Escritura;
}

Taller TallerArchivo :: LeerTaller(int indice)
{
    FILE *p;

    p = fopen("TALLER.DAT", "rb");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR" << endl;
        return obj;
    }

    fseek(p, sizeof(Taller) * indice, SEEK_SET);
    fread(&obj, sizeof(Taller), 1, p);
    fclose(p);
    return obj;
}

int TallerArchivo :: ContarRegistrosTaller()
{
    FILE *p;
    int tam;

    p = fopen("TALLER.DAT", "rb");
    if(p == nullptr)
    {
         cout << "NO PUDO ABRIR" << endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    tam = ftell(p) / sizeof(Taller);
    return tam;
}
