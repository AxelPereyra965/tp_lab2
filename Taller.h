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
    Taller(int _numero_pedido=0 ,string _nombre_taller = "", string _nombre_prenda="", float _precio_confeccion = 0.0f,  char modelo_confeccion = 'n', string _color = "", int cant_prendas = 0, Fecha fecha_de_entrega = Fecha(), bool _estado = false);
    //Taller();
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
    void setNumeroDePedido(int _numero_pedido);
    void setNombreTaller(string _nombre_taller);
    void setNombrePrenda(string _nombre_prenda);
    void setPrecioConfeccion(float _precio_confeccion);
    void setModeloConfeccion(char modelo_confeccion);
    void setColor(string _color);
    void setCantidadPrendas(int cant_prendas);
    void setFechaEntrega(Fecha fecha_de_entrega);
    void setEstado(bool _estado);


};



#endif // TALLER_H_INCLUDED
