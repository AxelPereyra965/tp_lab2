#include "VentaManager.h"
#include <algorithm>

//////////////////////////////   METODOS DE SUBMENUS   ///////////////////////////////////////////

void VentaManager :: ListarVenta()
{
    Venta ven;
    Prenda pren;
    bool SeparadorDeRemitos = false; //BANDERA QUE PERMITE PONER EL PRECIO AL FINAL SIN REPETIRSE ENTRE OBJETOS PRENDAS
    float totalVendido= 0;
    int Reg_Ventas = _ArchVenta.ContarRegistrosVenta(); // calcula la cantidad de registros de venta
    int Reg_Prendas = _ArchiPrenda.ContarRegistrosPrenda();
    int codigoActual = -1; // para almacenar el codigo de venta actual

    for(int x = 0; x < Reg_Ventas; x++) //RECORRO LAS VENTAS POR SU CODIGO Y MUESTRO TODAS LAS EXISTENTES
    {
        ven = _ArchVenta.LeerVenta(x); // me paro en las ventas
        int codigoVenta = ven.getCodigoVenta();

        if (codigoVenta != codigoActual && SeparadorDeRemitos == false) //ACA SOLO SE MOSTRARA EL CODIGO DE VENTA 1
        { //si es un nuevo grupo de venta
            cout << "==========================================" << endl;
            cout << "VENTA NRO " << codigoVenta << endl;
            cout << "FECHA DE COMPROBANTE: "
                 << ven.getVentaFecha().getDia() << "/"
                 << ven.getVentaFecha().getMes() << "/"
                 << ven.getVentaFecha().getAnio() << endl;
            cout << "------------------------------------------" << endl;
            codigoActual = codigoVenta;
            SeparadorDeRemitos = true; //BANDERA SEPARADORA ACTIVADA
            cout << endl;
        }//si es de la misma venta imprime

        for(int i = 0 ; i < Reg_Prendas ; i ++) //RECORRO TODAS LAS PRENDAS, Y MUESTRO SOLO LAS QUE SE VENDIERON
        {
            pren = _ArchiPrenda.LeerPrenda(i);
            if(pren.getCodigo() == ven.getCodigo()) //LAS RELACIONO POR SU CODIGO
            {
                cout << "PRENDA: " << ven.getNombrePrenda() << endl;
                cout << "CANTIDAD: " << ven.getCantidad() << endl;
                cout << "PRECIO DE LA PRENDA: $" << ven.getPrecioVenta() << endl;
                totalVendido+= pren.GetPrecioVenta(); //ACUMULO LO GASTADO, LA PROPIEDAD DE VENTATOTAL NO FUNCIONABA CORRECTAMENTE
                cout << endl;
            }
        }

        if (codigoVenta != codigoActual && SeparadorDeRemitos == true) //VENTAS QUE LE SIGUEN A LA UNO SE MUESTRAN ACA
        { //si es un nuevo grupo de venta
            cout << "TOTAL DE ESTA VENTA: $" << totalVendido << endl; //LO PONGO AFUERA DEL FOR PARA QUE SOLO MUESTRE EL RESULTADO FINAL
            totalVendido = 0; // REINICIO EL CONTADOR PARA LA SIGUIENTE VENTA
            cout << endl;
            cout << "==========================================" << endl;
            cout << "VENTA NRO " << codigoVenta << endl;
            cout << "FECHA DE COMPROBANTE: "
                 << ven.getVentaFecha().getDia() << "/"
                 << ven.getVentaFecha().getMes() << "/"
                 << ven.getVentaFecha().getAnio() << endl;
            cout << "------------------------------------" << endl;
            codigoActual = codigoVenta;
            cout << endl;
        }

    }
        cout << "TOTAL DE ESTA VENTA: $" << totalVendido << endl; // ESTE COUT MOSTRARA EL RESULTADO DE LA ULTIMO REGISTRO VENTA UBICADO EN EL ARCHIVO DE VENTAS
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

void VentaManager::SubMenuEstadisticaProductos() {
    int CantVentas = _ArchVenta.ContarRegistrosVenta();
    if (CantVentas <= 0) {
        cout << "NO SE REGISTRARON VENTAS HASTA EL MOMENTO" << endl;
        return;
    }

     cout << "Productos Mas Vendidos" << endl;

    // Crear vector dinámico para almacenar las cantidades vendidas por producto
    float *vec = new float[CantVentas]();
    Venta _venta;

    // Leer las ventas y acumular las cantidades vendidas por producto
    for (int x = 0; x < CantVentas; x++) {
        _venta = _ArchVenta.LeerVenta(x);
        vec[_venta.getCodigoPrenda() - 1] += _venta.getCantidad();
    }

    //se usa sort para ordenar vec en orden descendente
    sort(vec, vec + CantVentas, [](float a, float b) {
        return a > b; // Comparador para ordenar de mayor a menor
    });

    // Mostrar las estadísticas de ventas ordenadas
    for (int x = 0; x < CantVentas; x++) {
        _venta = _ArchVenta.LeerVenta(x);
        cout << _venta.getNombrePrenda() << ": " << vec[x] << endl;
    }

    // Liberar la memoria del vector dinámico
    delete[] vec;
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
