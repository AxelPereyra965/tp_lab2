#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Fecha
{
private:
    int Dia, Mes, Anio;
public:
    Fecha(int dia, int mes, int anio);
    Fecha();
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void MostrarFecha();
    void CargarFecha();
};


#endif // FECHA_H_INCLUDED
