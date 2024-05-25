#ifndef TALLERMANAGER_H_INCLUDED
#define TALLERMANAGER_H_INCLUDED

#include <cstring>
using namespace std;
#include "Taller.h"
#include "TallerArchivo.h"

class TaskTaller
{
private:
    void NuevoPedido(); //hago todo el cargar taller y lo adjunto en el metodo guardar
    void ModificarPedido(); //modificar algo del pedido en caso que haya alguna confusion ¿?
    void HistorialPedidos(); //Basicamente Listar todos los pedidos hechos a la fecha
public:
    void MenuTaller();
};


#endif // TALLERMANAGER_H_INCLUDED
