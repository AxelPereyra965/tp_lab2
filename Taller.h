#ifndef TALLER_H_INCLUDED
#define TALLER_H_INCLUDED
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "Fecha.h"

class Taller
{
    private:
    int NumeroDePedido;
    string NombreTaller;
    string NombrePrenda;
    float PrecioDeConfeccion;
    char ModeloConfeccion;
    string Color;
    int CantidadPrendas;
    Fecha FechaDeEntrega;
    bool Estado;
public:
    Taller(int _NumeroDePedido=0 ,string _NombreTaller = "", string _NombrePrenda="", float _PrecioDeConfeccion = 0.0f,  char _ModeloConfeccion = 'n', string _Color = "", int _CantidadPrendas = 0, Fecha _FechaDeEntrega = Fecha(), bool _Estado = false);
    Taller();
    //
    int getNumeroDePedido();
    string getNombreTaller();
    string getNombrePrenda();
    float getPrecioConfeccion();
    char getModeloConfeccion();
    string getColor();
    int getCantidadPrendas();
    Fecha getFechaEntrega();
    bool getEstado();
    //
    void setNumeroDePedido(int _NumeroDePedido);
    void setNombreTaller(string _NombreTaller);
    void setNombrePrenda(string _NombrePrenda);
    void setPrecioConfeccion(float _PrecioDeConfeccion);
    void setModeloConfeccion(char _ModeloConfeccion);
    void setColor(string _Color);
    void setCantidadPrendas(int _CantidadPrendas);
    void setFechaEntrega(Fecha _FechaDeEntrega);
    void setEstado(bool _Estado);
};



#endif // TALLER_H_INCLUDED
