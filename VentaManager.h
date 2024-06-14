#ifndef VENTAMANAGER_H_INCLUDED
#define VENTAMANAGER_H_INCLUDED
#include "VentaArchivo.h"
#include "PrendaManager.h"
#include "Venta.h"
#include "PrendaArchivo.h"
#include "Prenda.h"

class VentaManager{
private:
    VentaArchivo _ArchVenta;
    PrendaManager _PrendManager;
    PrendaArchivo _ArchiPrenda;
    Prenda _Prenda;
public:
    void SubMenuCargarVenta();
    void SubMenuEstadisticaProductos();


};



#endif // VENTAMANAGER_H_INCLUDED
