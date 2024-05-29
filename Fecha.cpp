#include "Fecha.h"
#include <ctime>

// Constructor
Fecha::Fecha(){
    Dia = 5;
    Mes = 6;
    Anio = 2024;
}
Fecha::Fecha(int _Dia,int _Mes, int _Anio){
    setDia(_Dia);
    setMes(_Mes);
    setAnio(_Anio);
}


//getters
int Fecha::getDia(){
    return Dia;
}

int Fecha::getMes(){
    return Mes;
}

int Fecha::getAnio(){
    return Anio;
}

//setters
void Fecha::setDia(int _Dia){
    Dia = _Dia;
}

void Fecha::setMes(int _Mes){
    Mes = _Mes;
}

void Fecha::setAnio(int _Anio){
    Anio = _Anio;
}

//mostrar fecha
void Fecha::MostrarFecha() {
    cout << Dia << "/" << Mes << "/" << Anio << endl;
}

//cargar fecha
void Fecha::CargarFecha() {
    int dia, mes, anio;
    bool fechaValida = false;

    while (!fechaValida) {
        cout << "Ingrese dia: ";
        cin >> dia;
        cout << "Ingrese mes: ";
        cin >> mes;
        cout << "Ingrese anio: ";
        cin >> anio;

        // validacion de la fecha ingresaa
        if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio >= 2020 && anio <= 2030) {//el año lo hice entre 2020 y 2030
            fechaValida = true;
        } else {
            cout << "Fecha no válida. Por favor, ingrese nuevamente.\n";
        }
    }

    setDia(dia);
    setMes(mes);
    setAnio(anio);
}



