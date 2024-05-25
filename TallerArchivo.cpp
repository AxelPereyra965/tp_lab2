#include "TallerArchivo.h"

TallerArchivo::TallerArchivo(string nombreTaller){
    nombreArchTaller=nombreTaller;
}

bool TallerArchivo :: Guardar(Taller obj)
{
    FILE *p;
    bool Guardado;

    p = fopen("TALLERES.DAT", "ab");
    if(p == nullptr)
    {
        cout << "ERROR DE APERTURA" << endl;
        return false;
    }
    Guardado = fwrite(&obj, sizeof(Taller), 1, p);
    fclose(p);
    return Guardado;
}

Taller TallerArchivo::Leer(int indice)
{
   FILE *p;
   Taller obj;

    p = fopen("TALLERES.DAT", "rb");
    if(p == nullptr)
    {
        cout << "ERROR DE APERTURA" << endl;
        return obj;
    }

    fseek(p, sizeof(Taller) * indice, SEEK_SET);
    fread(&obj, sizeof(Taller), 1, p);
    fclose(p);
    return obj;
}

int TallerArchivo :: ContarRegistros()
{
    FILE *ptaller;
    int tam = 0;

    fopen("TALLERES.DAT", "rb");
    if(ptaller == nullptr)
    {
        cout << "ERROR DE APERTURA" << endl;
        return -1;
    }
    fseek(ptaller, 0, SEEK_END); //me posiciono al final y me muevo 0 lugares
    tam = ftell(ptaller) / sizeof(Taller);
    fclose(ptaller);
    return tam; //devuelve la cantidad de registros archivados
}

int TallerArchivo :: NewNumeroPedido()
{
    int cantidad_registros = ContarRegistros();

    if(cantidad_registros > 0) //ejemplo: si tengo 1 registro, y quiero subir otro, para generar un nuevo id solo debo sumarlee uno y fin
    {
        return Leer(cantidad_registros - 1).getNumeroDePedido() + 1;
    }else
    {
        return 1; //si tengo 0 registros, 0 no es mayor que 0 (cant > 0), por ende significa que no tengo registros, y este entrante es el primero, asi que le asigno 1
    }
}

