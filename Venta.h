#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Fecha.h"
#include <string>
#include <cstring>
class Venta
{
private:
    int CodigoPrenda;
    int CodigoVenta;
    char NombrePrenda[50];
    char Modelo[50];
    char Talle[50];
    char Color[50];
    float PrecioVenta;
    float PrecioTotal;
    int Cantidad;
    Fecha FechaDeVenta;
public:
    Venta(int _CodigoPrenda, int _CodigoVenta, string _NombrePrenda, string _Modelo, string _Talle, string _Color, float _PrecioVenta, float _PrecioTotal , int _Cantidad, Fecha _FechaDeVenta);
    Venta();
    //
    int getCodigo();
    int getCodigoVenta();
    string getNombrePrenda();
    string getModelo();
    string getTalle();
    string getColor();
    float getPrecioVenta();
    float getPrecioTotal();
    int getCantidad();
    Fecha getVentaFecha();
    //
    void setCodigoPrenda(int _CodigoPrenda);
    void setCodigoDeVenta(int _CodigoVenta);
    void setNombrePrenda(string _NombrePrenda);
    void setModelo(string _Modelo);
    void setTalle(string _Talle);
    void setColor(string _Color);
    void setPrecioVenta(float _PrecioVenta);
    void setPrecioTotal(float _PrecioTotal);
    void setCantidad(int _Cantidad);
    void setVentaFecha(Fecha _FechaDeVenta);
};

#endif // VENTA_H_INCLUDED
