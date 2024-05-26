#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Fecha.h"

class Venta
{
private:
    int CodigoPrenda;
    string NombrePrenda;
    string Modelo;
    string Talle;
    string Color;
    string Campania;
    int Cantidad;
    Fecha FechaDeVenta;
public:
    Venta(int codigo_prenda, string nombre_prenda, string modelo, string talle, string color, string campania, int cantidad, Fecha fecha_venta);
    //
    int getCodigo();
    string getNombrePrenda();
    string getModelo();
    string getTalle();
    string getColor();
    string getCampania();
    int getCantidad();
    Fecha getVentaFecha();
    //
    void setCodigoPrenda(int codigo_prenda);
    void setNombrePrenda(string nombre_prenda);
    void setModelo(string modelo);
    void setTalle(string talle);
    void setColor(string color);
    void setCampania(string campania);
    void setCantidad(int cantidad);
    void setVentaFecha(Fecha fecha_venta);
};

#endif // VENTA_H_INCLUDED
