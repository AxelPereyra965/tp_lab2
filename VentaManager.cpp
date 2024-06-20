#include "VentaManager.h"

void VentaManager :: ListarVenta()
{
    Venta obj;
    int cantidad = _ArchVenta.ContarRegistrosVenta();

    for(int x = 0 ; x < cantidad ; x ++)
    {
        obj = _ArchVenta.LeerVenta(x);
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
    bool Encontro = false;
    char Salir = 'n';
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
            obj = _ArchVenta.LeerVenta(x);
            if(obj.getVentaFecha().getDia() == dia && obj.getVentaFecha().getMes() == mes && obj.getVentaFecha().getAnio() == anio)
            {
                Encontro = true;
                ListarVenta();
                system("pause");
                break;
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

////////////////////////////////////////////////////////////////////////////////////////

void VentaManager::SubMenuCargarVenta() {
    int CantPrendas = _ArchiPrenda.ContarRegistrosPrenda();
    int cod_venta;
    Prenda _pren;
    Venta _ven;
    Fecha obj;

    if(CantPrendas > 0)
    {
        system("cls");
        cout << "BIENVENIDO! USTED ESTA POR REALIZAR UNA VENTA" << endl;
        cout << "----------------------------------------------" << endl;
        cod_venta = _ArchVenta.NuevoCodigoDeVenta();
        _ven.setCodigoDeVenta(cod_venta); //codigo de venta unico, lo genero aca porque dentro de algun bucle puede generar un numero erroneo

        bool bandera = true;
        int acumVentaxprenda=0;

        while (bandera != false) {
            int CodigoSeleccionado;
            _PrendManager.SubmenuInventario();
            cout << "SELECCIONE EL CODIGO DE LA PRENDA QUE DESEA VENDER: " << endl;
            cin >> CodigoSeleccionado;


            // Entramos al archivo de prenda y recorremos todas las prendas
            // Filtramos por el código elegido
            // seteamos el objeto que creamos
            // lo subimos al archivo de venta

            bool prendaEncontrada = false;  // bandera para controlar el guardado de la venta
            //lo de prendaEncontrada es por q al modificar me duolicaba la prenda

            for (int x = 0; x < CantPrendas; x++) {
                _Prenda = _ArchiPrenda.LeerPrenda(x);

                if (_Prenda.getCodigo() == CodigoSeleccionado) {
                    //_ven.setCodigoPrenda(_Prenda.getCodigo()); //SE PISABAN LOS CODIGOS EN EL ARCHIVO PRENDA AL REALIZAR UNA VENTA, LO COMENTE Y DEJO DE PASAR
                    _ven.setNombrePrenda(_Prenda.getNombrePrenda());
                    _ven.setModelo(_Prenda.getModelo());
                    _ven.setTalle(_Prenda.getTalle());
                    _ven.setColor(_Prenda.getColor());
                    _ven.setCantidad(1);
                    _ven.setVentaFecha(obj.ReturnFechaActual());

                     //Guardamos la venta una sola vez
                    _ArchVenta.GuardarVenta(_ven);
                    prendaEncontrada = true;  // Marcamos que encontramos la prenda

                    break;  // Salimos del bucle una vez que encontramos la prenda
                }
            }

           if (prendaEncontrada) {  // Solo si encontramos la prenda actualizamos el stock
                for (int x = 0; x < CantPrendas; x++) {
                    _Prenda = _ArchiPrenda.LeerPrenda(x);

                    if (_Prenda.getCodigo() == _ven.getCodigo()) {  // Corregimos aquí el código
                        int pos = _ArchiPrenda.BuscarCodigoPrenda(x);
                        _Prenda.setCantidad(_Prenda.getCantidad() - _ven.getCantidad());

                        if (_Prenda.getCantidad() == 0) {  // Si el stock queda en 0 le hacemos una baja lógica
                            _Prenda.setEstadoDePrenda(false);
                        }
                        _ArchiPrenda.SobreescribirArchivoPrenda(pos, _Prenda);
                        break;  // Salimos del bucle una vez que actualizamos la prenda
                    }
                    ///por cada venta encontrada acumule
                    acumVentaxprenda= _ven.getCantidad()* _pren.GetPrecioVenta();
                }

            }

            int continuar;
            cout << "DESEA AGREGAR OTRO PRODUCTO A LA VENTA? 1 - SI // 2 - NO" << endl;
            cin >> continuar;
            system("cls");

            if (continuar == 2) { bandera = false; }
        }
    }else
    {
        cout << "NO HAY PRENDAS REGISTRADAS" << endl;
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
