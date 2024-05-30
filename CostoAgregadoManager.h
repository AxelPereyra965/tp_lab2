#ifndef COSTOAGREGADOMANAGER_H_INCLUDED
#define COSTOAGREGADOMANAGER_H_INCLUDED
#include "CostoAgregado.h"
#include "CostoAgregadoArchivo.h"

class CostoAgregadoManager
{
    private:
    bool HayGuardado; //VARIABLE PARA REPREGUNTAR EN CASO QUE YA HAYA UN AVIO Y SE DESEA SOBREESCRIBIR O NO
    public:
    CostoAgregadoManager(bool hayguardado = false){HayGuardado = hayguardado;}
    CostoAgregado CargarAvio();
    void GuardarAvio(); //ESTE VA AL MENU DE CARGAR AVIO
};

#endif // COSTOAGREGADOMANAGER_H_INCLUDED
