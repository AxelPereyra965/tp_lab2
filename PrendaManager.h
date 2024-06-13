#ifndef PRENDAMANAGER_H_INCLUDED
#define PRENDAMANAGER_H_INCLUDED
#include "Prenda.h"
#include "PrendaArchivo.h"

class PrendaManager
{
private:
    PrendaArchivo ObjArchivoPrenDa;//este objeto lo usaremos en el manager.cpp de prenda
    void ModificacionDePrenda(Prenda &obj);
    Prenda CargarPrenda();
    void MostrarPrenda(Prenda obj);
public:
    void SubmenuCargarPrenda();
    void SubmenuInventario();
    void SubmenuModificarPrenda();
    void SubmenuEliminarPrenda();

};

#endif // PRENDAMANAGER_H_INCLUDED
