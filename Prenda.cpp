#include "Prenda.h"

// Constructor


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

string Prenda::getCampania() {
    return Campania;
}

int Prenda::getCantidad() {
    return Cantidad;
}

float Prenda::getPorcentajeDeGanancia() {
    return PorcentajeDeGanancia;
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

void Prenda::setCampania(string _Campania) {
    Campania = _Campania;
}

void Prenda::setCantidad(int _Cantidad) {
    Cantidad = _Cantidad;
}

void Prenda::setPorcentajeDeGanancia(float _PorcentajeDeGanancia) {
    PorcentajeDeGanancia = _PorcentajeDeGanancia;
}

void Prenda::setEstado(bool _EstadoDePrenda) {
    EstadoDePrenda = _EstadoDePrenda;
}
