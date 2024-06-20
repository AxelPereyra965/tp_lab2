#ifndef VENTAMANAGER_H_INCLUDED
#define VENTAMANAGER_H_INCLUDED
#include "VentaArchivo.h"
#include "PrendaManager.h"
#include "Venta.h"
#include "PrendaArchivo.h"
#include "Prenda.h"
#include "Fecha.h"

class VentaManager{
private:
    VentaArchivo _ArchVenta;
    PrendaManager _PrendManager;
    PrendaArchivo _ArchiPrenda;
    Prenda _Prenda;
    void ListarVenta();
    void BuscarVentaPorFecha();
public:
    void SubMenuCargarVenta();
    void SubMenuEstadisticaProductos();
    void SubMenuHistorialDeVenta();

};

#endif // VENTAMANAGER_H_INCLUDED
