#include "Prenda.h"

int Prenda :: getCodigo()
{
  return CodigoPrenda;
}

string Prenda :: getNombrePrenda()
{
  return NombrePrenda;
}

string Prenda :: getModelo()
{
  return Modelo;
}

string Prenda :: getTalle()
{
  return Talle;
}

string Prenda :: getColor()
{
  return Color;
}

string Prenda :: getCampania()
{
  return Campania;
}

int Prenda :: getCantidad()
{
  return Cantidad;
}

float Prenda ::  getPorcentajeDeGanancia()
{
  return PorcentajeDeGanancia;
}

bool Prenda :: getEstadoDePrenda()
{
  return EstadoDePrenda;
}

void Prenda :: setCodigoDePrenda(int codigo_prenda)
{
  CodigoPrenda = codigo_prenda;
}
