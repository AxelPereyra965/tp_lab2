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
    string Campania;
    int Cantidad;
    float PorcentajeDeGanancia;
    bool EstadoDePrenda;
public:
    Prenda(int _CodigoPrenda, string _NombrePrenda, string _Modelo, string _Talle, string _Color, string _Campania, int _Cantidad, float _PorcentajeDeGanancia, bool _EstadoDePrenda);
    Prenda();
    //
    int getCodigo();
    string getNombrePrenda();
    string getModelo();
    string getTalle();
    string getColor();
    string getCampania();
    int getCantidad();
    float getPorcentajeDeGanancia();
    bool getEstadoDePrenda();
    //
    void setCodigoPrenda(int _CodigoPrenda);
    void setNombrePrenda(string _NombrePrenda);
    void setModelo(string _Modelo);
    void setTalle(string _Talle);
    void setColor(string _Color);
    void setCampania(string _Campania);
    void setCantidad(int _Cantidad);
    void setPorcentajeDeGanancia(float _PorcentajeDeGanancia);
    void setEstadoDePrenda(bool _EstadoDePrenda);
};

#endif // PRENDA_H_INCLUDED
