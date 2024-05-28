#include "Venta.h"


#include "Venta.h"

// Constructor

//getters
int Venta::getCodigo() {
    return CodigoPrenda;
}

string Venta::getNombrePrenda() {
    return NombrePrenda;
}

string Venta::getModelo() {
    return Modelo;
}

string Venta::getTalle() {
    return Talle;
}

string Venta::getColor() {
    return Color;
}

string Venta::getCampania() {
    return Campania;
}

int Venta::getCantidad() {
    return Cantidad;
}

Fecha Venta::getVentaFecha() {
    return FechaDeVenta;
}

//setters
void Venta::setCodigoPrenda(int _CodigoPrenda) {
    CodigoPrenda = _CodigoPrenda;
}

void Venta::setNombrePrenda(string _NombrePrenda) {
    NombrePrenda = _NombrePrenda;
}

void Venta::setModelo(string _Modelo) {
    Modelo = _Modelo;
}

void Venta::setTalle(string _Talle) {
    Talle = _Talle;
}

void Venta::setColor(string _Color) {
    Color = _Color;
}

void Venta::setCampania(string _Campania) {
    Campania = _Campania;
}

void Venta::setCantidad(int _Cantidad) {
    Cantidad = _Cantidad;
}

void Venta::setVentaFecha(Fecha _FechaDeVenta) {
    FechaDeVenta = _FechaDeVenta;
}
