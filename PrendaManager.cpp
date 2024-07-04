#include "PrendaManager.h"
#include <iostream>
#include <limits>
using namespace std;

/*
explicacion del cin.ignore, fflush, getline, etc;

cin.ignore() --> ignora a los caracteres separadores, estos separadores
                estan antes de la secuencia que quieras escribir, y podrian interferir, ignorando el dato a modificar

getline(cin, dato_a_usar) --> permite meter espacios entre caracteres

fflush(stdin) --> limpia el buffer de entrada una vez escrito/rellenado el dato tipo string,
                    que mas adelante provoque errores en la lectura del dato
*/

//FUNCIONES COMPLEMENTARIAS (LAS TRES DEVUELVEN UN STRING QUE POSTERIORMENTE LO CARGARA EN EL SET DEL METODO CARGARPRENDA)


string SeleccionDeTalle()
{
    int selector;
    string talle;
    bool Error = false;

    do
    {

        cout << "SELECCIONE EL TIPO DE TALLE" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1 -    S (Small)" << endl;
        cout << endl;
        cout << "2 -    M (Medium)" << endl;
        cout << endl;
        cout << "3 -    L (Large)" << endl;
        cout << endl;
        cout << "4 -    XL (Extra Large)" << endl;
        cout << endl;
        cout << "5 -    XXL (Double Extra Large)" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> selector;
        switch(selector)
        {
        case 1:
            talle = "S (Small)";
            Error = true;
            break;
        case 2:
            talle = "M (Medium)";
            Error = true;
            break;
        case 3:
            talle = "L (Large)";
            Error = true;
            break;
        case 4:
            talle = "XL (Extra Large)";
            Error = true;
            break;
        case 5:
            talle = "XXL (Double Extra Large)";
            Error = true;
            break;
        default:
            cout << "OPCION INCORRECTA. INDIQUE NUEVAMENTE ALGUNA DE LAS OPCIONES." << endl;
            system("pause");
            system("cls");
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        }
    }while(Error != true);

    return talle;
}

string  SeleccionDeColor()
{
    int selector;
    string color;
    bool Error = false;

    do
    {

        cout << "SELECCIONE EL COLOR DE LA PRENDA" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1 -    NEGRO" << endl;
        cout << endl;
        cout << "2 -    GRIS" << endl;
        cout << endl;
        cout << "3 -    BEIGE" << endl;
        cout << endl;
        cout << "4 -    BLANCO" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> selector;
        switch(selector)
        {
        case 1:
            color = "NEGRO";
            Error = true;
            break;
        case 2:
            color = "GRIS";
            Error = true;
            break;
        case 3:
            color = "BEIGE";
            Error = true;
            break;
        case 4:
            color = "BLANCO";
            Error = true;
            break;
        default:
            cout << "OPCION INCORRECTA. INDIQUE NUEVAMENTE ALGUNA DE LAS OPCIONES." << endl;
            system("pause");
            system("cls");
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        }
    }while(Error != true);

    return color;
}


//          METODOS COMPLEMENTARIOS

void PrendaManager::CargarPrenda() {
    Prenda pren;
    int cod_prenda, cantidad, OpcionCargar, Codigo, Stock, pos, comp1 = -1;
    string nombre_prenda, modelo, talle, color;
    float precio_unitario;
    bool Encontro = false;
    int Cantidad_Registros = ObjArchivoPrenDa.ContarRegistrosPrenda();

    do
    {

        system("cls");
        cout << "BIENVENIDO! ESTA USTED POR CARGAR UNA PRENDA" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1 - CARGAR PRENDA EXISTENTE" << endl;
        cout << endl;
        cout << "2 - CARGAR PRENDA NUEVA" << endl;
        cout << endl;
        cout << "0 - MENU ANTERIOR" << endl;
        cout << "----------------------------------------------" << endl;

        while (!(cin >> OpcionCargar)) { //por si se ingresa una letra
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el input incorrecto
            system("cls");
            cout << "por favor ingrese solo numeros...."<<endl;
            system("pause");
        system("cls");
            cout << "BIENVENIDO! ESTA USTED POR CARGAR UNA PRENDA" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "1 - CARGAR PRENDA EXISTENTE" << endl;
            cout << endl;
            cout << "2 - CARGAR PRENDA NUEVA" << endl;
            cout << endl;
            cout << "0 - MENU ANTERIOR" << endl;
            cout << "----------------------------------------------" << endl;
        }

        switch (OpcionCargar) {
            case 1:
                    if(Cantidad_Registros > 0)
                    {
                        system("cls");
                        for(int x = 0 ; x < Cantidad_Registros ; x ++)
                        {
                            pren = ObjArchivoPrenDa.LeerPrenda(x);
                            cout << "=================================================" << endl;
                            MostrarPrenda(pren);
                            cout << "=================================================" << endl;
                        }

                        cout << "SELECCIONE EL CODIGO DE LA PRENDA A STOCKEAR: " << endl;
                        cin >> Codigo;
                        system("cls");

                        for(int x = 0 ; x < Cantidad_Registros ; x++)
                        {
                            pren = ObjArchivoPrenDa.LeerPrenda(x);

                            if(pren.getCodigo()==Codigo)
                            {
                                pos =ObjArchivoPrenDa.BuscarCodigoPrenda(pren.getCodigo());
                                Encontro = true;
                                cout << "INDIQUE LA CANTIDAD CON LA QUE SE VA A STOCKEAR: ";
                                cin >> Stock;
                                cout << endl;
                                pren.setCantidad(pren.getCantidad() + Stock);
                                if(pren.getEstadoDePrenda() == false || pren.getCantidad() > 0)
                                {
                                    pren.setEstadoDePrenda(true);
                                }
                                ObjArchivoPrenDa.SobreescribirArchivoPrenda(pos,pren);
                                system("cls");
                                cout << "- STOCK ACTUALIZADO DE " << pren.getNombrePrenda() <<" -" << endl;
                                system("pause");
                            }
                        }
                        if(Encontro == false)
                        {
                            cout << "PRENDA NO ENCONTRADA" << endl;
                            system("pause");
                        }
                        break;
                    }else
                    {
                        cout << "NO EXISTEN PRENDAS REGISTRADAS" << endl;
                        system("pause");
                        break;
                    }
            case 2:
                system("cls");
                cod_prenda = ObjArchivoPrenDa.NuevoCodigoPrenda();
                pren.setCodigoPrenda(cod_prenda);
                cout << "CODIGO DE LA PRENDA: " << cod_prenda << endl;
                cout << endl;
                cout << "=============================================================="<< endl;
                cout << endl;
                cout << "NOMBRE DE PRENDA: ";
                cin.ignore();
                getline(cin, nombre_prenda);
                fflush(stdin);
                pren.setNombrePrenda(nombre_prenda);
                cout << endl;
                cout << "=============================================================="<< endl;
                cout << endl;
                cout << "MODELO DE PRENDA: ";
                cin.ignore();
                getline(cin, modelo);
                fflush(stdin);
                pren.setModelo(modelo);
                cout << endl;
                cout << "=============================================================="<< endl;
                cout << endl;
                cout << "TALLE DE PRENDA: ";
                talle = SeleccionDeTalle();
                pren.setTalle(talle);
                cout << endl;
                cout << "=============================================================="<< endl;
                cout << endl;
                cout << "COLOR DE PRENDA: ";
                color = SeleccionDeColor();
                pren.setColor(color);
                cout << endl;
                cout << "=============================================================="<< endl;
                cout << endl;
                cout << "PRECIO A VENDER PARA " << nombre_prenda << " POR UNIDAD: $";
                cin >> precio_unitario;
                while(precio_unitario<0 || cin.fail()){
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cout << "DEBE INGRESAR UN NUMERO VALIDO"<<endl<<endl;
                    system("pause");
                    system("cls");
                    cout << "PRECIO A VENDER PARA " << nombre_prenda << " POR UNIDAD: $";
                    cin >> precio_unitario;
                }
                pren.setPrecioVenta(precio_unitario);
                cout << endl;
                cout << "=============================================================="<< endl;
                cout << endl;
                cout << "CANTIDAD DE " << nombre_prenda << " QUE USTED ENCARGO: ";
                cin >> cantidad;
                while(cantidad<0 || cin.fail()){
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cout << "DEBE INGRESAR UN NUMERO VALIDO"<<endl<<endl;
                    system("pause");
                    system("cls");
                    cout << "CANTIDAD DE " << nombre_prenda << " QUE USTED ENCARGO: ";
                    cin >> cantidad;
                }
                pren.setCantidad(cantidad);
                cout << endl;
                cout << "=============================================================="<< endl;
                cout << endl;

                    pren.setEstadoDePrenda(true);

               system("cls");
               if(ObjArchivoPrenDa.GuardarPrenda(pren))
               {
                  cout << "PRENDA SUBIDA CORRECTAMENTE." << endl;
                  system("pause");
               }else
               {
                  cout << "ALGO SALIO MAL..." << endl;
                  system("pause");
               }
                break;
            case 0:
                {
                    return;
                    break;
                }
            default:
                    cout << "OPCION INCORRECTA" << endl;
                    system("pause");
                    system("cls");
        }
    }while(true);
}

void PrendaManager :: ModificacionDePrenda(Prenda &obj)
{
    int cantidad, opcion;
    string nombre_prenda, modelo, talle, color;
    float price;


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
        cout << "5) MODIFICAR PRECIO UNITARIO" << endl;
        cout << "6) MODIFICAR CANTIDAD DE PRENDAS CARGADAS" << endl;
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
                talle = SeleccionDeTalle();
                obj.setTalle(talle);
                cout << endl;
                break;
            }
        case 4:
            {
                cout << "INDIQUE EL NUEVO COLOR DE PRENDA: ";
                color = SeleccionDeColor();
                obj.setColor(color);
                cout << endl;
                break;
            }
        case 5:
            {
                cout << "INDIQUE EL PRECIO NUEVO: $";
                cin >> price;
            while(cin.fail() || price<0){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "DEBE INGRESAR UN NUMERO VALIDO"<<endl<<endl;
                    cout << "INDIQUE EL PRECIO NUEVO: ";
                    cin >> price;
                }
            obj.setPrecioVenta(price);
            cout << endl;
            break;
            }
        case 6:
            {
                cout << "INDIQUE EL NUEVO NUMERO DE STOCK: ";
                cin >> cantidad;
                while(cin.fail() || cantidad<0){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "DEBE INGRESAR UN NUMERO VALIDO"<<endl<<endl;
                    cout << "INDIQUE EL NUEVO NUMERO DE STOCK: ";
                    cin >> cantidad;
                }
                obj.setCantidad(cantidad);
                cout << endl;
                break;
            }
        default:
              if(opcion != 0){
                cout << "OPCION INCORRECTA" << endl;
                if(cin.fail()) // booleano que detecta si hay un error en la entrada
                {
                cin.clear(); // limpia la entrada
                cin.ignore(); //ignora el caracter erroneo
                }
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
    cout << "PRECIO: $" << obj.GetPrecioVenta() << endl;
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

    system("cls");
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
        cout << endl;
        cout << "OPCION: ";
        cin >> seleccion;
        while (seleccion != 0){
            system("cls");
            pos = ObjArchivoPrenDa.BuscarCodigoPrenda(seleccion);
            if (pos != -2){ // Pregunto si se encontró en el archivo

                for (int x = 0; x < cantidad; x++){ // Recorro todo el archivo de prendas

                    _prenda = ObjArchivoPrenDa.LeerPrenda(x);

                    if(_prenda.getEstadoDePrenda())
                    {
                        if (_prenda.getCodigo() == seleccion){// Una vez encontrada modifico y guardo en el archivo

                            ModificacionDePrenda(_prenda);
                            ObjArchivoPrenDa.SobreescribirArchivoPrenda(pos, _prenda);
                            break;
                        }
                    }else
                    {
                        cout << "CODIGO NO DISPONIBLE" << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                }
                break; // Salir del bucle una vez realizada la modificacion
            }else{
                cout << "PRENDA NO ENCONTRADA. POR FAVOR, INGRESE UN CODIGO DE PRENDA VALIDO: " << endl;
                if(cin.fail())
                {
                cin.clear();
                cin.ignore();
                }
                system("pause");
                SubmenuInventario();
                cout << endl;
                cout << "OPCION: ";
                cin >> seleccion;
            }
        }
    }else{
        cout << "NO EXISTEN REGISTROS DE PRENDAS" << endl;
        system("pause");
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
            if(cin.fail()||seleccion != 0)
            {
                cin.clear();
                cin.ignore();
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
                if(cin.fail())
                {
                cin.clear();
                cin.ignore();
                }
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
    int cantidad = ObjArchivoPrenDa.ContarRegistrosPrenda();

    system("cls");
    if(cantidad > 0)
    {
        do                        //la cadena que ingresa el us y el nombre de la prend se conierten a char para compararse
        {
            char Selector[30], copia[30];
            string selector;
            bool EncontrePrenda = false;
            int Resultado, Salir;
            Prenda obj;

            cout << "INGRESE EL NOMBRE A BUSCAR" << endl;
            cout << "===========================" << endl;
            cout << "(INGRESE CERO SI QUIERE DEJAR DE BUSCAR)" << endl;
            cin.ignore();
            getline(cin, selector);
            if(selector != "0")
            {
                fflush(stdin);
                strcpy(Selector, selector.c_str()); //convierto el string a const char para poder meterlo en el strcmp (

                for(int x = 0 ; x < cantidad ; x ++)
                {
                    obj = ObjArchivoPrenDa.LeerPrenda(x);
                    strcpy(copia, obj.getNombrePrenda().c_str()); //convierto el string a const char para poder meterlo en el strcmp
                    Resultado = strcmp(Selector,copia); //comparo las dos cadenas de caracteres
                    if(Resultado == 0 && obj.getEstadoDePrenda()) //el strcmp pide devolver un valor entero, si ese valor es '0', significa que las cadenas son iguales
                    {
                        EncontrePrenda = true;
                        cout << "=================================" << endl;
                        MostrarPrenda(obj);
                        cout << "=================================" << endl;
                    }
                }
                if(!EncontrePrenda)
                {
                    system("cls");
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
            }else
            {
                system("cls");
                return;
            }
            system("cls");

        }while(Fin != true);
    }else
    {
        cout << "NO HAY PRENDAS CARGADAS ACTUALMENTE" << endl;
    }

}
