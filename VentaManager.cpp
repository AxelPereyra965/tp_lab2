#include "VentaManager.h"

//////////////////////////////   METODOS DE SUBMENUS   ///////////////////////////////////////////

void VentaManager :: ListarVenta()
{
     Venta obj;
    int cantidad = _ArchVenta.ContarRegistrosVenta(); // calcula la cantidad de registros de venta

    int codigoActual = -1; // para almacenar el codigo de venta actual

    for(int x = 0; x < cantidad; x++)
    {
        obj = _ArchVenta.LeerVenta(x); // me paro en las ventas
        int codigoVenta = obj.getCodigoVenta();

        if (codigoVenta != codigoActual)
        { //si es un nuevo grupo de venta
            cout << "==========================================" << endl;
            cout << "VENTA NRO " << codigoVenta << endl;
            cout << "FECHA DE COMPROBANTE: "
                 << obj.getVentaFecha().getDia() << "/"
                 << obj.getVentaFecha().getMes() << "/"
                 << obj.getVentaFecha().getAnio() << endl;
            cout << "------------------------------------" << endl;
            codigoActual = codigoVenta;
            cout << endl;
        }//si es de la misma venta imprime
        cout << "PRENDA: " << obj.getNombrePrenda() << endl;
        cout << "CANTIDAD: " << obj.getCantidad() << endl;
        cout << endl;
    }
        cout << "TOTAL DE ESTA VENTA: $" << obj.getPrecioTotal() << endl; //LO PONGO AFUERA DEL FOR PARA QUE SOLO MUESTRE EL RESULTADO FINAL
        cout << endl;
        cout << "==========================================" << endl;
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

void VentaManager::SubMenuCargarVenta()
{
    Venta _ven;
    int cod_venta, CodigoSeleccionado;
    char Salir = 'n';
    Fecha obj;
    int CantPrendas = _ArchiPrenda.ContarRegistrosPrenda();

    if(CantPrendas > 0)
    {
        system("cls");
        cout << "BIENVENIDO! ESTA USTED POR REALIZAR UNA VENTA" << endl;
        cout << "----------------------------------------------" << endl;

        float totalVendido= 0; ///acumulador de lo q se vendio total
        cod_venta = _ArchVenta.NuevoCodigoDeVenta();
        _ven.setCodigoDeVenta(cod_venta); //codigo de venta unico, lo genero aca porque dentro de algun bucle puede generar un numero erroneo
        while (Salir != '1')
        {
            _PrendManager.SubmenuInventario();
            cout << endl;
            cout << "SELECCIONE EL CODIGO DE PRENDA A VENDER: ";
            cout<<"(TOTAL ACUMULADO AL MOMENTO EN ESTA VENTA : $"<< totalVendido <<")" << endl;
            cin >> CodigoSeleccionado;
            cout << endl;

            // Entramos al archivo de prenda y recorremos todas las prendas
            // Filtramos por el código elegido
            // seteamos el objeto que creamos
            // lo subimos al archivo de venta

            bool prendaEncontrada = false;  // bandera para controlar el guardado de la venta
            //lo de prendaEncontrada es por q al modificar me duolicaba la prenda

            int cInicial=0; //cantidad de ventas segun prenda

            for (int x = 0; x < CantPrendas; x++)
            {
                _Prenda= _ArchiPrenda.LeerPrenda(x);

                if (_Prenda.getCodigo() == CodigoSeleccionado && _Prenda.getEstadoDePrenda())
                {
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
                    totalVendido+= _Prenda.GetPrecioVenta();
                    _ven.setPrecioTotal(totalVendido);
                     //Guardamos la venta una sola vez
                    _ArchVenta.GuardarVenta(_ven);
                    system("cls");
                    cout << "----------------------------------------------" << endl << endl;
                    cout <<"CODIGO DE VENTA NUMERO: "<<_ven.getCodigoVenta() << endl;

                    break;  // Salimos del bucle una vez que encontramos la prenda
                }

            }

            if (prendaEncontrada) // Solo si encontramos la prenda actualizamos el stock
            {

                for (int x = 0; x < CantPrendas; x++)
                {
                    _Prenda= _ArchiPrenda.LeerPrenda(x);

                    if (_Prenda.getCodigo() == _ven.getCodigo()) // Corregimos aquí el código
                    {
                        int pos = _ArchiPrenda.BuscarCodigoPrenda(x + 1);

                        _Prenda.setCantidad(_Prenda.getCantidad() - cInicial);

                        if (_Prenda.getCantidad() <= 0)
                        {  // Si el stock queda en 0 le hacemos una baja lógica
                            _Prenda.setEstadoDePrenda(false);
                        }

                        cout <<"EN ESTA VENTA: $"<<totalVendido<< endl << endl;
                        cout << "----------------------------------------------" << endl;
                        _ArchiPrenda.SobreescribirArchivoPrenda(pos, _Prenda);
                        system("pause");
                        break;  // Salimos del bucle una vez que actualizamos la prenda
                    }
                }
            }else
            {
                system("cls");
                cout << "PRENDA NO ENCONTRADA" << endl;
                system("pause");
            }

            ///hacer un for para sobreescrir la venta actualizada
            system("cls");
            cout << "DESEA AGREGAR OTRO PRODUCTO A LA VENTA? CUALQUIER TECLA - SI / 1 - NO" << endl;
            cout<<"(TOTAL ACUMULADO AL MOMENTO EN ESTA VENTA : $"<< totalVendido <<")" << endl;
            cin >> Salir;
            system("cls");

        }

    }else
    {
        cout << "NO SE REGISTRAN VENTAS" << endl;
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
        float * vec = new float[CantVentas];
        if (vec == nullptr) {
            cout << "Error de memoria" << endl;
            return;
        }

        // leo las ventas y acumulo
        for (int x = 0; x < CantVentas; x++) {
            Vent = _ArchVenta.LeerVenta(x);
            vec[CantVentas] += Vent.getPrecioTotal();
        }

        // ordeno el vector en orden descendente usando un algoritmo de selección
        int maxIndex = 0;
        for (int i = 1; i <= CantVentas; i++) {
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
        return;
    }
}
