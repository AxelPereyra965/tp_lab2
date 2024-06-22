#include "VentaManager.h"

//////////////////////////////   METODOS DE SUBMENUS   ///////////////////////////////////////////

void VentaManager :: ListarVenta()
{
    Venta obj;
    int cantidad = _ArchVenta.ContarRegistrosVenta(); //calcula la cantidad de registros de venta

    for(int x = 0 ; x < cantidad ; x ++) //recorre todas las ventas registradas
    {
        obj = _ArchVenta.LeerVenta(x); //se para en los objetos
            cout << "=================================================" << endl;
            cout << "VENTA NRO " << obj.getCodigoVenta() << endl;
            cout << "FECHA DE COMPROBANTE: " << obj.getVentaFecha().getDia() << "/" << obj.getVentaFecha().getMes() << "/" << obj.getVentaFecha().getAnio() << endl;
            cout << "---------------------------------------------------" << endl;
            cout << "PRENDA: " << obj.getNombrePrenda() << endl;
            cout << "CANTIDAD: " << obj.getCantidad() << endl;
            cout << "=================================================" << endl;
    }
}

void VentaManager :: BuscarVentaPorFecha()
{
    int dia, mes, anio;
    bool Encontro;  //detecta si se encontro o no una venta en esa fecha
    char Salir = 'n';       //usamos char para evitar que se rompa al tocar cualquier tecla
    int cantidad = _ArchVenta.ContarRegistrosVenta();
    Venta obj;

    do
    {
        system("cls");
        cout << "INGRESE LA FECHA EN LA QUE DESEA BUSCAR UNA VENTA" << endl;
        cout << "--------------------------------------------------" << endl;
        system("pause");
        cout << endl;
        cout << "INDIQUE EL DIA: ";
        cin >> dia;
        cout << endl;
        cout << "INDIQUE EL MES: ";
        cin >> mes;
        cout << endl;
        cout << "INDIQUE EL ANIO: ";
        cin >> anio;
        cout << endl;

        for(int x = 0 ; x < cantidad ; x ++)
        {
            Encontro = false;
            obj = _ArchVenta.LeerVenta(x);
            if(obj.getVentaFecha().getDia() == dia && obj.getVentaFecha().getMes() == mes && obj.getVentaFecha().getAnio() == anio)
            {
                Encontro = true;
                ListarVenta();
                system("pause");
                break;  //para evitar que entre en un bucle infinito
            }
        }
        if(!Encontro)
        {
            cout << "NO SE ENCONTRARON VENTAS EN LA FECHA ' " << dia << "/" << mes << "/" << anio << " '" << endl;
            system("pause");
        }

        system("cls");
        cout << "DESEA SEGUIR BUSCANDO? '1' - NO / CUALQUIER OTRA TECLA - SI" << endl;
        cin >> Salir;

    }while(Salir != '1');

}

//////////////////////////////   DESARROLLO DE SUBMENUS   ///////////////////////////////////////////

void VentaManager::SubMenuCargarVenta() {
    Venta _ven;
    int cod_venta;
    Fecha obj;

    cout << "BIENVENIDO! ESTA USTED POR REALIZAR UNA VENTA" << endl;
    cout << "----------------------------------------------" << endl;
    _PrendManager.SubmenuInventario();

    bool bandera = true;


    int totalVendido=0; ///acumulador de lo q se vendio total
    cod_venta = _ArchVenta.NuevoCodigoDeVenta();
    _ven.setCodigoDeVenta(cod_venta); //codigo de venta unico, lo genero aca porque dentro de algun bucle puede generar un numero erroneo
    while (bandera != false) {


        int CodigoSeleccionado;
        cout << "Seleccione el código de la prenda que desea vender" << endl;
        cin >> CodigoSeleccionado;

        // Entramos al archivo de prenda y recorremos todas las prendas
        // Filtramos por el código elegido
        // seteamos el objeto que creamos
        // lo subimos al archivo de venta

        int CantPrendas = _ArchiPrenda.ContarRegistrosPrenda();
        bool prendaEncontrada = false;  // bandera para controlar el guardado de la venta
        //lo de prendaEncontrada es por q al modificar me duolicaba la prenda

        int cInicial=0; //cantidad de ventas segun prenda

        for (int x = 0; x < CantPrendas; x++) {
            _Prenda= _ArchiPrenda.LeerPrenda(x);
            ///cout<<"entro el codigo dentro del for"<<endl;

            if (_Prenda.getCodigo() == CodigoSeleccionado) {
                _ven.setCodigoPrenda(_Prenda.getCodigo());
                _ven.setNombrePrenda(_Prenda.getNombrePrenda());
                _ven.setModelo(_Prenda.getModelo());
                _ven.setTalle(_Prenda.getTalle());
                _ven.setColor(_Prenda.getColor());
                _ven.setPrecioVenta(_Prenda.GetPrecioVenta());
                _ven.setVentaFecha(obj.ReturnFechaActual());
                prendaEncontrada = true;  // Marcamos que encontramos la prenda
                cInicial++;
                _ven.setCantidad(cInicial);
                 //Guardamos la venta una sola vez
                _ArchVenta.GuardarVenta(_ven);
                cout<<"se guardo correctamente la prenda en ven "<<_ven.getCantidad() <<endl;

                break;  // Salimos del bucle una vez que encontramos la prenda
            }

        }

        if (prendaEncontrada) {  // Solo si encontramos la prenda actualizamos el stock

            for (int x = 0; x < CantPrendas; x++) {
                _Prenda= _ArchiPrenda.LeerPrenda(x);

                if (_Prenda.getCodigo() == _ven.getCodigo()) {  // Corregimos aquí el código
                    int pos = _ArchiPrenda.BuscarCodigoPrenda(x);

                    _Prenda.setCantidad(_Prenda.getCantidad() - cInicial);

                    cout<<"queda al final "<<cInicial<< " con precio "<< _Prenda.GetPrecioVenta() <<endl;

                    if (_Prenda.getCantidad() <= 0) {  // Si el stock queda en 0 le hacemos una baja lógica
                        _Prenda.setEstadoDePrenda(false);
                    }

                     totalVendido+= _ven.getCantidad() * _Prenda.GetPrecioVenta();
                    //_ArchVenta.GuardarVenta(_ven);
                     cout<<"este es el precio actualizado: "<<_ven.getPrecioVenta()<<endl;
                    _ArchiPrenda.SobreescribirArchivoPrenda(pos, _Prenda);
                    cout<<"se guardo correctamen"<<endl;
                    system("pause");
                    break;  // Salimos del bucle una vez que actualizamos la prenda
                }
            }
        }

        _ven.setPrecioVenta(totalVendido);
        ///hacer un for para sobreescrir la venta actualizada


        int continuar;

        ///cout<<"queda al final cham cham"<<_Prenda.getCantidad()<<endl;
        ///_PrendManager.SubmenuInventario();
        cout << "¿Desea agregar otro producto a la venta? 1-si 2-no" << endl;
        cin >> continuar;



        if (continuar == 2) {
                bandera = false;
        }
    }

}

//producto más vendido
void VentaManager::SubMenuEstadisticaProductos()
{
    int CantVentas = _ArchVenta.ContarRegistrosVenta();
    Venta Vent;
    if(CantVentas > 0)
    {

        cout << "CANTIDAD DE VENTAS " << CantVentas << endl;
        // creo un vector dinámico de enteros con el tamaño de la cantidad de ventas
        int* vec = new int[CantVentas];
        if (vec == nullptr) {
            cout << "Error de memoria" << endl;
            return;
        }

        // leo las ventas y acumulo
        for (int x = 0; x < CantVentas; x++) {
            Vent = _ArchVenta.LeerVenta(x);
            vec[Vent.getCodigo()-1] += Vent.getCantidad();
        }

        // ordeno el vector en orden descendente usando un algoritmo de selección
            int maxIndex = 0;
        for (int i = 1; i < CantVentas; i++) {
            for (int j = i + 1; j < CantVentas; j++) {
                if (vec[j] > vec[maxIndex]) {
                    maxIndex = j;
                }
            }
            if (maxIndex != 0) {
                int temp = vec[i];
                vec[i] = vec[maxIndex];
                vec[maxIndex] = temp;
            }
        }

        // Imprimir las ventas en orden descendente
        for (int x = 0; x < CantVentas; x++) {
            cout << "Venta " << x+1 << ": " << vec[x] <<endl; //std::endl;
        }

        // Liberar la memoria
        delete[] vec;
    }else
    {
        cout << "NO SE REGISTRARON VENTAS HASTA EL MOMENTO" << endl;
    }
}

void VentaManager :: SubMenuHistorialDeVenta()
{
    int cantidad_registros = _ArchVenta.ContarRegistrosVenta();
    int Opcion;

    if(cantidad_registros > 0)
    {
        system("cls");
        cout << "REGISTROS CONTABLES DE VENTAS" << endl;
        cout << "---------------------------------" << endl;
        cout << "1 - VER TODOS" << endl;
        cout << endl;
        cout << "2 - VERLOS POR FECHA" << endl;
        cout << endl;
        cout << "0 - MENU ANTERIOR" << endl;
        cout << "----------------------------------" << endl;
        cin >> Opcion;
        switch(Opcion)
        {
        case 1:
            {
                system("cls");
                ListarVenta();
                break;
            }
        case 2:
            {
                BuscarVentaPorFecha();
                break;
            }
        case 0:
            {
                return;
                break;
            }
        }

    }else
    {
        cout << "NO SE REGISTRAN VENTAS" << endl;
        system("pause");
        return;
    }
}
