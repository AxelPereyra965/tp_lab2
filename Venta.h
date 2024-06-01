#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Fecha.h"
#include <string>
#include <cstring>
class Venta
{
private:
    int CodigoPrenda;
    string NombrePrenda;
    string Modelo;
    string Talle;
    string Color;
    int Cantidad;
    Fecha FechaDeVenta;
public:
    Venta(int _CodigoPrenda, string _NombrePrenda, string _Modelo, string _Talle, string _Color, int _Cantidad, Fecha _FechaDeVenta);
    Venta();
    //
    int getCodigo();
    string getNombrePrenda();
    string getModelo();
    string getTalle();
    string getColor();
    int getCantidad();
    Fecha getVentaFecha();
    //
    void setCodigoPrenda(int _CodigoPrenda);
    void setNombrePrenda(string _NombrePrenda);
    void setModelo(string _Modelo);
    void setTalle(string _Talle);
    void setColor(string _Color);
    void setCantidad(int _Cantidad);
    void setVentaFecha(Fecha _FechaDeVenta);
};

#endif // VENTA_H_INCLUDED
