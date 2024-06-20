#ifndef VENTAARCHIVO_H_INCLUDED
#define VENTAARCHIVO_H_INCLUDED
#include "Venta.h"
#include <iostream>
using namespace std;
class VentaArchivo
{
private:
    Venta obj;
public:
    bool GuardarVenta(Venta obj);
    Venta LeerVenta(int indice);
    int ContarRegistrosVenta();
    int NuevoCodigoDeVenta();
};

#endif // VENTAARCHIVO_H_INCLUDED
