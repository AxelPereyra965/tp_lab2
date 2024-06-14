#include "PrendaManager.h"
#include <iostream>
using namespace std;

/*
explicacion del cin.ignore, fflush, getline, etc;

cin.ignore() --> ignora a los caracteres separadores, estos separadores
                estan antes de la secuencia que quieras escribir, y podrian interferir, ignorando el dato a modificar

getline(cin, dato_a_usar) --> permite meter espacios entre caracteres

fflush(stdin) --> limpia el buffer de entrada una vez escrito/rellenado el dato tipo string,
                    que mas adelante provoque errores en la lectura del dato
*/

//          METODOS COMPLEMENTARIOS

void PrendaManager::CargarPrenda() {
    Prenda pren;
    int cod_prenda, cantidad;
    string nombre_prenda, modelo, talle, color;
    float precio_unitario;

    cout << "BIENVENIDO! ESTA USTED POR CARGAR UNA PRENDA" << endl;
    cout << "----------------------------------------------" << endl;

    int OpcionCargar;
    cout << "1 - CARGAR PRENDA EXISTENTE" << endl;
    cout << endl;
    cout << "2 - CARGAR PRENDA NUEVA" << endl;
    cout << "----------------------------------------------" << endl;
    cin >> OpcionCargar;

    switch (OpcionCargar) {
        case 1:
            system("cls");
            SubmenuInventario(); // metodo de la clase para listar el inventario
            int Codigo, Stock,pos, cant;

            cout << "seleccione el codigo de la prenda a stockear: " << endl;
            cin >> Codigo;

            cant = ObjArchivoPrenDa.ContarRegistrosPrenda();

            for(int x=0;x<cant;x++){
                pren = ObjArchivoPrenDa.LeerPrenda(x);

                if(pren.getCodigo()==Codigo){

                    pos =ObjArchivoPrenDa.BuscarCodigoPrenda(pren.getCodigo());

                    cout << "indique la cantidad de stock a agregar de esa prenda " << endl;
                    cin >> Stock;
                    pren.setCantidad(pren.getCantidad() + Stock);
                    ObjArchivoPrenDa.SobreescribirArchivoPrenda(pos,pren);
                }
            }

            cout << "stock agregado" << endl;
            cout << "precione alguna tecla para continuar" << endl;
            break;
        case 2:
            system("cls");
            cod_prenda = ObjArchivoPrenDa.NuevoCodigoPrenda();
            pren.setCodigoPrenda(cod_prenda);
            cout << "CODIGO DE LA PRENDA: " << cod_prenda << endl;
            cout << endl;
            cout << "NOMBRE DE PRENDA: ";
            cin.ignore();
            getline(cin, nombre_prenda);
            fflush(stdin);
            pren.setNombrePrenda(nombre_prenda);
            cout << endl;

            cout << "MODELO DE PRENDA: ";
            getline(cin, modelo);
            fflush(stdin);
            pren.setModelo(modelo);
            cout << endl;

            cout << "TALLE DE PRENDA: ";
            getline(cin, talle);
            //cin >> talle;
            pren.setTalle(talle);
            cout << endl;

            cout << "COLOR DE PRENDA: ";
            getline(cin, color);
            //cin >> color;
            pren.setColor(color);
            cout << endl;

            cout << "PRECIO A VENDER PARA " << nombre_prenda << " POR UNIDAD: ";
            cin >> precio_unitario;
            while(precio_unitario<0){
                cout << "DEBE INGRESAR UN NUMERO VALIDO"<<endl<<endl;
                cout << "PRECIO A VENDER PARA " << nombre_prenda << " POR UNIDAD: ";
                cin >> precio_unitario;
            }
            pren.setPrecioVenta(precio_unitario);
            cout << endl;

            cout << "CANTIDAD DE " << nombre_prenda << " QUE USTED ENCARGO: ";
            cin >> cantidad;
            while(cantidad<0){
                cout << "DEBE INGRESAR UN NUMERO VALIDO"<<endl<<endl;
                cout << "CANTIDAD DE " << nombre_prenda << " QUE USTED ENCARGO: ";
                cin >> cantidad;
            }
            pren.setCantidad(cantidad);
            cout << endl;


            pren.setEstadoDePrenda(true);

           system("cls");
           if(ObjArchivoPrenDa.GuardarPrenda(pren))
           {
              cout << "PRENDA SUBIDA CORRECTAMENTE." << endl;
              system("pause");
           }
            break;
    }
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
                cin.ignore();
                getline(cin, nombre_prenda);
                fflush(stdin);
                obj.setNombrePrenda(nombre_prenda);
                cout << endl;
                break;
            }
        case 2:
            {
                cout << "INDIQUE EL NUEVO MODELO DE PRENDA: ";
                cin.ignore();
                getline(cin, modelo);
                fflush(stdin);
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
   CargarPrenda();
}

void PrendaManager ::SubmenuInventario()
{
    Prenda obj;

    int cantidad = ObjArchivoPrenDa.ContarRegistrosPrenda();

    if(cantidad > 0)
    {
        for(int x = 0 ; x < cantidad ; x ++)
        {
            obj = ObjArchivoPrenDa.LeerPrenda(x);
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

void PrendaManager::SubmenuModificarPrenda()
{
    int seleccion, pos = 0;
    int cantidad = ObjArchivoPrenDa.ContarRegistrosPrenda();
    Prenda _prenda;

    if (cantidad > 0)
    {
        system("cls");
        cout << "INGRESE EL CODIGO DE LA PRENDA A MODIFICAR: " << endl;
        SubmenuInventario();
        cout << endl;
        cout << "(INGRESE '0' EN CASO DE QUERER VOLVER AL MENU PRINCIPAL)" << endl;
        cin >> seleccion;
        while (seleccion != 0){
            system("cls");
            pos = ObjArchivoPrenDa.BuscarCodigoPrenda(seleccion);
            if (pos != -2){ // Pregunto si se encontró en el archivo

                for (int x = 0; x < cantidad; x++){ // Recorro todo el archivo de prendas

                    _prenda = ObjArchivoPrenDa.LeerPrenda(x);

                    if (_prenda.getCodigo() == seleccion){// Una vez encontrada modifico y guardo en el archivo

                        ModificacionDePrenda(_prenda);
                        ObjArchivoPrenDa.SobreescribirArchivoPrenda(pos, _prenda);
                    }
                }
                break; // Salir del bucle una vez realizada la modificacion
            }else{
                cout << "Prenda no encontrada. Por favor, ingrese un codigo de prenda valido: " << endl;
                SubmenuInventario();
                cin >> seleccion;
            }
        }
    }else{
        cout << "No hay prendas disponibles para modificar." << endl;
    }
}

void PrendaManager :: SubmenuEliminarPrenda()
{
    Prenda obj;
    int seleccion, pos = 0;
    bool Eliminar = false;
    int cantidad = ObjArchivoPrenDa.ContarRegistrosPrenda();

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
                pos = ObjArchivoPrenDa.BuscarCodigoPrenda(seleccion);
                if(pos != -2)
                {
                    obj = ObjArchivoPrenDa.LeerPrenda(pos);
                    cout << "DESEA ELIMINAR ESTA PRENDA? 1 - SI / 0 - NO: ";
                    cin >> Eliminar;
                    if(Eliminar)
                    {
                        obj.setEstadoDePrenda(false);
                        if(ObjArchivoPrenDa.SobreescribirArchivoPrenda(pos, obj))
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

void PrendaManager :: SubmenuDetalleDePrenda()
{
    bool Fin = false;
    do                        //la cadena que ingresa el us y el nombre de la prend se conierten a char para compararse
    {
        char Selector[30], copia[30];
        string selector;
        int cantidad = ObjArchivoPrenDa.ContarRegistrosPrenda();
        int Resultado, Salir;
        Prenda obj;

        cout << "INGRESE EL NOMBRE A BUSCAR" << endl;
        cout << "===========================" << endl;
        cout << "(INGRESE CERO SI QUIERE DEJAR DE BUSCAR)" << endl;
        cin.ignore();
        getline(cin, selector);
        fflush(stdin);
        strcpy(Selector, selector.c_str()); //convierto el string a const char para poder meterlo en el strcmp (

        for(int x = 0 ; x < cantidad ; x ++)
        {
            obj = ObjArchivoPrenDa.LeerPrenda(x);
            strcpy(copia, obj.getNombrePrenda().c_str()); //convierto el string a const char para poder meterlo en el strcmp
            Resultado = strcmp(Selector,copia); //comparo las dos cadenas de caracteres
            if(Resultado == 0 && obj.getEstadoDePrenda()) //el strcmp pide devolver un valor entero, si ese valor es '0', significa que las cadenas son iguales
            {
                cout << "=================================" << endl;
                MostrarPrenda(obj);
                cout << "=================================" << endl;
            }
        }
        if(Resultado != 0)
        {
            cout << "PRENDA NO ENCONTRADA" << endl;
        }
        system("pause");
        system("cls");
        cout << "DESEA SEGUIR BUSCANDO? (1- NO / CUALQUIER OTRA TECLA - SI)" << endl;
        cin >> Salir;
        if(Salir == 1)
        {
            Fin = true; //sale del bucle de buscar prendas y termina el metodo
        }
        system("cls");

    }while(Fin != true);

}

