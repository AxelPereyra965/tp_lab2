#ifndef PRENDAARCHIVO_H_INCLUDED
#define PRENDAARCHIVO_H_INCLUDED
#include "Prenda.h"

class PrendaArchivo
{
private:
    Prenda obj;
public:
    bool GuardarPrenda(Prenda obj);
    Prenda LeerPrenda(int indice);
    int ContarRegistrosPrenda();
    int NuevoCodigoPrenda();
};

#endif // PRENDAARCHIVO_H_INCLUDED
