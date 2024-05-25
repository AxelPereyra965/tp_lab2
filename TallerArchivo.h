#ifndef TALLERARCHIVO_H_INCLUDED
#define TALLERARCHIVO_H_INCLUDED

#include <string>
using namespace std;

#include "taller.h"

class TallerArchivo
{
    private:
    string nombreArchTaller;
public:
    TallerArchivo(string nombreArchTAller);
    bool Guardar(Taller obj);
    Taller Leer(int indice);
    int ContarRegistros();
    int NewNumeroPedido();
    //si hay que modificar el registro, faltarian una funcion para sobreescribir, seria otro guardar que tiene como parametros el indice del registro a reemplazar y el objeto contenedor
};

#endif // TALLERARCHIVO_H_INCLUDED
