#ifndef PRENDA_H_INCLUDED
#define PRENDA_H_INCLUDED
#include <iostream>
using namespace std;
#include <string>
#include <cstring>
class Prenda
{
private:
    int CodigoPrenda;
    string NombrePrenda;
    string Modelo;
    string Talle;
    string Color;
    int Cantidad;
    int PrecioVenta;
    bool EstadoDePrenda;
public:
    Prenda(int _CodigoPrenda, string _NombrePrenda, string _Modelo, string _Talle, string _Color, int _Cantidad,int _PrecioVenta, bool _EstadoDePrenda);
    Prenda();
    //
    int getCodigo();
    string getNombrePrenda();
    string getModelo();
    string getTalle();
    string getColor();
    int getCantidad();
    int GetPrecioVenta();
    bool getEstadoDePrenda();
    //
    void setCodigoPrenda(int _CodigoPrenda);
    void setNombrePrenda(string _NombrePrenda);
    void setModelo(string _Modelo);
    void setTalle(string _Talle);
    void setColor(string _Color);
    void setCantidad(int _Cantidad);
    void setPrecioVenta(int _PrecioVenta);
    void setEstadoDePrenda(bool _EstadoDePrenda);
};

#endif // PRENDA_H_INCLUDED
