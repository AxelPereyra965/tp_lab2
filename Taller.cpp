#include <iostream>
#include <cstring>
#include <string>
#include "Taller.h"

using namespace std;



// Constructor

//getters
int Taller::getNumeroDePedido() {
    return NumeroDePedido;
}

string Taller::getNombreTaller() {
    return NombreTaller;
}

string Taller::getNombrePrenda() {
    return NombrePrenda;
}

float Taller::getPrecioConfeccion() {
    return PrecioDeConfeccion;
}

char Taller::getModeloConfeccion() {
    return ModeloConfeccion;
}

string Taller::getColor() {
    return Color;
}

int Taller::getCantidadPrendas() {
    return CantidadPrendas;
}

Fecha Taller::getFechaEntrega() {
    return FechaDeEntrega;
}

bool Taller::getEstado() {
    return Estado;
}

//setters
void Taller::setNumeroDePedido(int _NumeroDePedido) {
    NumeroDePedido = _NumeroDePedido;
}

void Taller::setNombreTaller(string _NombreTaller) {
    NombreTaller = _NombreTaller;
}

void Taller::setNombrePrenda(string _NombrePrenda) {
    NombrePrenda = _NombrePrenda;
}

void Taller::setPrecioConfeccion(float _PrecioDeConfeccion) {
    PrecioDeConfeccion = _PrecioDeConfeccion;
}

void Taller::setModeloConfeccion(char _ModeloConfeccion) {
    ModeloConfeccion = _ModeloConfeccion;
}

void Taller::setColor(string _Color) {
    Color = _Color;
}

void Taller::setCantidadPrendas(int _CantidadPrendas) {
    CantidadPrendas = _CantidadPrendas;
}

void Taller::setFechaEntrega(Fecha _FechaDeEntrega) {
    FechaDeEntrega = _FechaDeEntrega;
}

void Taller::setEstado(bool _Estado) {
    Estado = _Estado;
}

