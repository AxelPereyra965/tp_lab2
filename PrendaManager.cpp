#include "PrendaManager.h"
#include <iostream>
using namespace std;

//          METODOS COMPLEMENTARIOS

Prenda PrendaManager :: CargarPrenda()
{
    Prenda pren;
    int cod_prenda, cantidad;
    string nombre_prenda, modelo, talle, color;

    cout << "BIENVENIDO! ESTA USTED POR CARGAR UNA PRENDA" << endl;
    cout << "----------------------------------------------" << endl;
    cod_prenda = Arch.NuevoCodigoPrenda();
    pren.setCodigoPrenda(cod_prenda);
    cout << "CODIGO DE LA PRENDA: " << cod_prenda << endl;

    cout << "NOMBRE DE PRENDA: ";
    cin >> nombre_prenda;
    pren.setNombrePrenda(nombre_prenda);
    cout << endl;

    cout << "MODELO DE PRENDA: ";
    cin >> modelo;
    pren.setModelo(modelo);
    cout << endl;

    cout << "TALLE DE PRENDA: ";
    cin >> talle;
    pren.setTalle(talle);
    cout << endl;

    cout << "COLOR DE PRENDA: ";
    cin >> color;
    pren.setColor(color);
    cout << endl;


    cout << "CANTIDAD DE "<< nombre_prenda << " QUE USTED ENCARGO: ";
    cin >> cantidad;
    pren.setCantidad(cantidad);
    cout << endl;

    pren.setEstadoDePrenda(true);

    return pren;
}

void PrendaManager :: ModificacionDePrenda(Prenda &obj)
{
    int cantidad, opcion;
    string nombre_prenda, modelo, talle, color;

        do
        {
        system("cls");
        cout << "ELIJA QUE DATOS QUIERE MODIFICAR" << endl;
        cout << "===========================================" << endl;
        cout << "PRENDA A MODIFICAR: " << obj.getNombrePrenda() << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1) MODIFICAR NOMBRE DE PRENDA" << endl;
        cout << "2) MODIFICAR MODELO" << endl;
        cout << "3) MODIFICAR TALLE" << endl;
        cout << "4) MODIFICAR COLOR" << endl;
        cout << "5) MODIFICAR CANTIDAD DE PRENDAS CARGADAS" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "0) SALIR" << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
            {
                cout << "INDIQUE EL NUEVO NOMBRE DE PRENDA: ";
                cin >> nombre_prenda;
                obj.setNombrePrenda(nombre_prenda);
                cout << endl;
                break;
            }
        case 2:
            {
                cout << "INDIQUE EL NUEVO MODELO DE PRENDA: ";
                cin >> modelo;
                obj.setModelo(modelo);
                cout << endl;
                break;
            }
        case 3:
            {
                cout << "INDIQUE EL NUEVO TALLE DE PRENDA: ";
                cin >> talle;
                obj.setTalle(talle);
                cout << endl;
                break;
            }
        case 4:
            {
                cout << "INDIQUE EL NUEVO COLOR DE PRENDA: ";
                cin >> color;
                obj.setColor(color);
                cout << endl;
                break;
            }
        case 5:
            {
                cout << "INDIQUE EL NUEVO NUMERO DE STOCK: ";
                cin >> cantidad;
                obj.setCantidad(cantidad);
                cout << endl;
                break;
            }
        default:
              if(opcion != 0){
                cout << "OPCION INCORRECTA" << endl;
                }
            break;
        }
        system("pause");
        }while(opcion != 0);
}

void PrendaManager :: MostrarPrenda(Prenda obj)
{
    cout << "CODIGO DE PRENDA: " << obj.getCodigo() << endl;
    cout << "NOMBRE DE PRENDA: " << obj.getNombrePrenda() << endl;
    cout << "TALLE: " << obj.getTalle() << endl;
    cout << "MODELO: " << obj.getModelo() << endl;
    cout << "COLOR: " << obj.getColor() << endl;
    cout << "CANTIDAD DE STOCK: " << obj.getCantidad() << endl;
    cout << "DISPONIBLE: " << (obj.getEstadoDePrenda() ? "SI" : "NO")<< endl;
}

//      METODOS QUE IRAN A LOS SUBMENUS

void PrendaManager :: SubmenuCargarPrenda()
{
    system("cls");
    if(Arch.GuardarPrenda(CargarPrenda()))
    {
        cout << "PRENDA SUBIDA CORRECTAMENTE." << endl;
        system("pause");
    }
}

void PrendaManager ::SubmenuInventario()
{
    Prenda obj;

    int cantidad = Arch.ContarRegistrosPrenda();

    if(cantidad > 0)
    {
        for(int x = 0 ; x < cantidad ; x ++)
        {
            obj = Arch.LeerPrenda(x);
            if(obj.getEstadoDePrenda())
            {
                cout << "=================================================" << endl;
                MostrarPrenda(obj);
                cout << "=================================================" << endl;
            }
        }
    }else
    {
        cout << "NO HAY PRENDAS CARGADAS ACTUALMENTE" << endl;
        return;
    }
}

void PrendaManager :: SubmenuModificarPrenda()
{
    int seleccion, pos = 0;
    int cantidad = Arch.ContarRegistrosPrenda();

    if(cantidad > 0)
    {
        system("cls");
        cout << "INGRESE EL CODIGO DE LA PRENDA A MODIFICAR: " << endl;
        SubmenuInventario();
        cout << endl;
        cout << "(INGRESE '0' EN CASO DE QUERER VOLVER AL MENU PRINCIPAL)" << endl;
        cin >> seleccion;
        cout << endl;
        system("cls");
        if(seleccion != 0)
        {
            pos = Arch.BuscarCodigoPrenda(seleccion);
            if(pos != -1)
            {
                Prenda obj = Arch.LeerPrenda(pos);
                ModificacionDePrenda(obj);
                if(Arch.SobreescribirArchivoPrenda(pos, obj))
                {
                    cout << "EL ARCHIVO SE MODIFICO EXITOSAMENTE" << endl;
                }else
                {
                    cout << "ERROR DE MODIFICACION" << endl;
                }
            }else
            {
                cout << "PRENDA NO EXISTENTE" << endl;
            }
        }else
        {
            return;
        }
    }else
    {
        cout << "NO HAY PRENDAS CARGADAS ACTUALMENTE" << endl;
    }

}

void PrendaManager :: SubmenuEliminarPrenda()
{
    Prenda obj;
    int seleccion, pos = 0;
    bool Eliminar = false;
    int cantidad = Arch.ContarRegistrosPrenda();

    if(cantidad > 0)
    {
        do
        {
            system("cls");
            cout << "INGRESE EL CODIGO DE LA PRENDA QUE DESEA ELIMINAR: " << endl;
            SubmenuInventario();
            cout << endl;
            cout << "(INGRESE '0' EN CASO DE QUERER VOLVER AL MENU PRINCIPAL)" << endl;
            cin >> seleccion;
            cout << endl;
            system("cls");
            if(seleccion != 0)
            {
                pos = Arch.BuscarCodigoPrenda(seleccion);
                if(pos != -1)
                {
                    obj = Arch.LeerPrenda(pos);
                    cout << "DESEA ELIMINAR ESTA PRENDA? 1 - SI / 0 - NO: ";
                    cin >> Eliminar;
                    if(Eliminar)
                    {
                        obj.setEstadoDePrenda(false);
                        if(Arch.SobreescribirArchivoPrenda(pos, obj))
                        {
                            cout << "PRENDA ELIMINADA EXITOSAMENTE" << endl;
                        }else
                        {
                            cout << "ERROR DE ELIMINACION." << endl;
                        }
                    }
                    else
                    {
                        cout << "NO SE ELIMINARA ESTA PRENDA" << endl;
                    }
                }else
                {
                    cout << "PRENDA NO EXISTENTE" << endl;
                }
            }else
            {
                return;
            }
        }while(Eliminar == false);
    }else
    {
        cout << "NO HAY PRENDAS CARGADAS ACTUALMENTE" << endl;
    }
}
