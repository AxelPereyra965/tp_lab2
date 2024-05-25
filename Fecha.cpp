#include "Fecha.h"
#include <ctime>

void Fecha :: setDia(int dia)
{
        Dia = dia;
}

int Fecha :: getDia()
{
    return Dia;
}

void Fecha :: setMes(int mes)
{
        Mes = mes;
}

int Fecha :: getMes()
{
    return Mes;
}

void Fecha :: setAnio(int anio)
{
        Anio = anio;
}

int Fecha :: getAnio()
{
    return Anio;
}

Fecha :: Fecha()
{
     time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    Dia = f->tm_mday;
    Mes = f->tm_mon+1;
    Anio = f->tm_year+1900;
}

Fecha :: Fecha(int dia, int mes, int anio)
{
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

void Fecha :: MostrarFecha()
{
     if (Dia < 10)
        {
            std::cout << "0";
        }
            std::cout << Dia << "/";
    if (Mes < 10)
    {
        std::cout << "0";
    }
    std::cout << Mes << "/";
    std::cout <<Anio << std::endl;
}

void Fecha :: CargarFecha()
{
    cout << "INGRESE EL DIA: ";
    cin >> Dia;
    cout << endl;
    cout << "INGRESE EL MES: ";
    cin >> Mes;
    cout << endl;
    cout << "INGRESE EL ANIO: ";
    cin >> Anio;
    cout << endl;
    ///hojdosndscnksd
}
