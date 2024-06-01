#include "Prenda.h"

// Constructor
Prenda::Prenda(){
    CodigoPrenda=0;
    NombrePrenda="";
    Modelo="";
    Talle="";
    Color="";
    Cantidad=0;
    PrecioVenta=0;
    EstadoDePrenda= false;
}
Prenda::Prenda(int _CodigoPrenda, string _NombrePrenda, string _Modelo, string _Talle, string _Color, int _Cantidad,int _PrecioVenta, bool _EstadoDePrenda)
{
    setCodigoPrenda(_CodigoPrenda);
    setNombrePrenda(_NombrePrenda);
    setModelo(_Modelo);
    setTalle(_Talle);
    setColor(_Color);
    setCantidad(_Cantidad);
    setPrecioVenta(_PrecioVenta);
    setEstadoDePrenda(_EstadoDePrenda);
}

//getters
int Prenda::getCodigo() {
    return CodigoPrenda;
}

string Prenda::getNombrePrenda() {
    return NombrePrenda;
}

string Prenda::getModelo() {
    return Modelo;
}

string Prenda::getTalle() {
    return Talle;
}

string Prenda::getColor() {
    return Color;
}


int Prenda::getCantidad() {
    return Cantidad;
}

int Prenda::GetPrecioVenta() {
    return PrecioVenta;
}


bool Prenda::getEstadoDePrenda() {
    return EstadoDePrenda;
}

//setters
void Prenda::setCodigoPrenda(int _CodigoPrenda) {
    CodigoPrenda = _CodigoPrenda;
}

void Prenda::setNombrePrenda(string _NombrePrenda) {
    NombrePrenda = _NombrePrenda;
}

void Prenda::setModelo(string _Modelo) {
    Modelo = _Modelo;
}

void Prenda::setTalle(string _Talle) {
    Talle = _Talle;
}

void Prenda::setColor(string _Color) {
    Color = _Color;
}


void Prenda::setCantidad(int _Cantidad) {
    Cantidad = _Cantidad;
}

void Prenda::setPrecioVenta(int _PrecioVenta) {
    PrecioVenta = _PrecioVenta;
}


void Prenda::setEstadoDePrenda(bool _EstadoDePrenda) {
    EstadoDePrenda = _EstadoDePrenda;
}
