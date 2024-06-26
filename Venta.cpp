#include "Venta.h"
#include <cstring>

// Constructor
Venta::Venta(){
    CodigoPrenda =0;
    CodigoVenta = 0;
    strcpy(NombrePrenda,"");
    strcpy(Modelo,"");
    strcpy(Talle,"");
    strcpy(Color,"");
    Cantidad=0;
    PrecioVenta= 0.0f;
    FechaDeVenta=Fecha();
}

Venta::Venta(int _CodigoPrenda, int _CodigoVenta, string _NombrePrenda, string _Modelo, string _Talle, string _Color, float _PrecioVenta, int _Cantidad, Fecha _FechaDeVenta)
{
    setCodigoPrenda(_CodigoPrenda);
    setCodigoDeVenta(_CodigoVenta);
    setNombrePrenda(_NombrePrenda);
    setModelo(_Modelo);
    setTalle(_Talle);
    setColor(_Color);
    setCantidad(_Cantidad);
    setPrecioVenta(_PrecioVenta);
    setVentaFecha(_FechaDeVenta);
}

//getters
int Venta::getCodigo() {
    return CodigoPrenda;
}

int Venta :: getCodigoVenta(){
    return CodigoVenta;
}

int Venta :: getCodigoPrenda(){
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

float Venta::getPrecioVenta(){
    return PrecioVenta;
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

void Venta :: setCodigoDeVenta(int _CodigoVenta){
    CodigoVenta = _CodigoVenta;
}

void Venta::setNombrePrenda(string _NombrePrenda) {
    strcpy(NombrePrenda,_NombrePrenda.c_str());
}

void Venta::setModelo(string _Modelo) {
    strcpy(Modelo,_Modelo.c_str());
}

void Venta::setTalle(string _Talle) {
     strcpy(Talle,_Talle.c_str());
}

void Venta::setColor(string _Color) {
    strcpy(Color,_Color.c_str());
}


void Venta::setPrecioVenta(float _PrecioVenta) {
    PrecioVenta = _PrecioVenta;
}

void Venta::setCantidad(int _Cantidad) {
    Cantidad = _Cantidad;
}

void Venta::setVentaFecha(Fecha _FechaDeVenta) {
    FechaDeVenta = _FechaDeVenta;
}
