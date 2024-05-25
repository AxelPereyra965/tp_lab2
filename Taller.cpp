#include <iostream>
#include <cstring>
#include <string>
#include "Taller.h"

using namespace std;

Taller::Taller(int _numero_pedido,string _nombre_taller, string _nombre_prenda, float _precio_confeccion, char modelo_confeccion, string _color, int cant_prendas, Fecha fecha_de_entrega, bool _estado)
{
    setNumeroDePedido(_numero_pedido);
    setNombreTaller(_nombre_taller);
    setNombrePrenda(_nombre_prenda);
    setPrecioConfeccion(_precio_confeccion);
    setModeloConfeccion(modelo_confeccion);
    setColor(_color);
    setCantidadPrendas(cant_prendas);
    setFechaEntrega(fecha_de_entrega);
    setEstado(_estado);
}

int Taller::getNumeroDePedido()
{
    return NumeroDePedido;
}

string Taller :: getNombreTaller()
{
    return NombreTaller;
}
string Taller :: getNombrePrenda()
{
    return NombrePrenda;
}
float Taller :: getPrecioConfeccion()
{
    return PrecioDeConfeccion;
}

char Taller :: getModeloConfeccion()
{
    return ModeloConfeccion;
}

string Taller :: getColor()
{
    return Color;
}

int Taller :: getCantidadPrendas()
{
    return CantidadPrendas;
}

Fecha Taller :: getFechaEntrega()
{
    return FechaDeEntrega;
}

bool Taller:: getEstado()
{
    return Estado;
}

void Taller:: setNumeroDePedido(int _numero_pedido)
{
    NumeroDePedido = _numero_pedido;
}

void Taller :: setNombreTaller(string _nombre_taller)
{
    NombreTaller = _nombre_taller;
}

void Taller :: setNombrePrenda(string _nombre_prenda)
{
    NombrePrenda = _nombre_prenda;
}
void Taller :: setPrecioConfeccion(float _precio_confeccion)
{
    if(_precio_confeccion >= 0)
        {
            PrecioDeConfeccion = _precio_confeccion;
        }else
        {
            PrecioDeConfeccion = 0;
        }
}

void Taller :: setModeloConfeccion(char modelo_confeccion)
{
     char upper_modelo = std::toupper(modelo_confeccion); //convierte un caracter minuscula a mayuscula, y lo toma en rango de la 'a' a la 'h'

    if (upper_modelo >= 'A' && upper_modelo <= 'H') {
        ModeloConfeccion = upper_modelo;
    } else {
        ModeloConfeccion = '0';
    }
}

void Taller :: setColor(string _color)
{
    Color = _color;
}

void Taller :: setCantidadPrendas(int cant_prendas)
{
    if(cant_prendas > 0)
    {
        CantidadPrendas = cant_prendas;
    }else
    {
        CantidadPrendas = 0;
    }
}

void Taller :: setFechaEntrega(Fecha fecha_de_entrega)
{
    FechaDeEntrega = fecha_de_entrega;
}

void Taller:: setEstado(bool _estado)
{
    Estado = _estado;
}

