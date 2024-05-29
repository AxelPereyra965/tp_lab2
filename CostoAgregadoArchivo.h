#ifndef COSTOAGREGADOARCHIVO_H_INCLUDED
#define COSTOAGREGADOARCHIVO_H_INCLUDED
#include "CostoAgregado.h"

class CostoAgregadoArchivo
{
private:
    CostoAgregado obj;
public:
    bool GuardarCA(CostoAgregado obj);
    CostoAgregado LeerCA(int indice);
    int ContarRegistrosCA();
};
#endif // COSTOAGREGADOARCHIVO_H_INCLUDED
