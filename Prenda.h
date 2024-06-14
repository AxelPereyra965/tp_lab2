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
    char NombrePrenda[50];
    char Modelo[50];
    char Talle[50];
    char Color[50];
    int Cantidad;
    float PrecioVenta;
    bool EstadoDePrenda;
public:
    Prenda(int _CodigoPrenda, string _NombrePrenda, string _Modelo, string _Talle, string _Color, int _Cantidad,float _PrecioVenta, bool _EstadoDePrenda);
    Prenda();
    //
    int getCodigo();
    string getNombrePrenda();
    string getModelo();
    string getTalle();
    string getColor();
    int getCantidad();
    float GetPrecioVenta();
    bool getEstadoDePrenda();
    //
    void setCodigoPrenda(int _CodigoPrenda);
    void setNombrePrenda(string _NombrePrenda);
    void setModelo(string _Modelo);
    void setTalle(string _Talle);
    void setColor(string _Color);
    void setCantidad(int _Cantidad);
    void setPrecioVenta(float _PrecioVenta);
    void setEstadoDePrenda(bool _EstadoDePrenda);
};

#endif // PRENDA_H_INCLUDED
