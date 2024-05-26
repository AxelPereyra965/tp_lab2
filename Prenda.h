#ifndef PRENDA_H_INCLUDED
#define PRENDA_H_INCLUDED
#include <iostream>
using namespace std;

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
    Prenda(int codigo_prenda, string nombre_prenda, string modelo, string talle, string color, string campania, int cantidad, float porcentaje_ganancia, bool estado);
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
    void setCodigoPrenda(int codigo_prenda);
    void setNombrePrenda(string nombre_prenda);
    void setModelo(string modelo);
    void setTalle(string talle);
    void setColor(string color);
    void setCampania(string campania);
    void setCantidad(int cantidad);
    void setPorcentajeDeGanancia(float porcentaje_ganancia);
    void setEstado(bool estado);
};

#endif // PRENDA_H_INCLUDED
