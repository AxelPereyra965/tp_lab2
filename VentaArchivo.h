#ifndef VENTAARCHIVO_H_INCLUDED
#define VENTAARCHIVO_H_INCLUDED
#include "Venta.h"

class VentaArchivo
{
private:
    Venta obj;
public:
    bool GuardarVenta(Venta obj);
    Venta LeerVenta(int indice);
    int ContarRegistrosVenta();
};

#endif // VENTAARCHIVO_H_INCLUDED
