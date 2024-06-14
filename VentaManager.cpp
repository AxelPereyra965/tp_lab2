#include "VentaManager.h"


void VentaManager::SubMenuCargarVenta() {
    Prenda _pren;
    Venta _ven;
    Fecha obj;

    cout << "BIENVENIDO! ESTA USTED POR REALIZAR UNA VENTA" << endl;
    cout << "----------------------------------------------" << endl;
    _PrendManager.SubmenuInventario();

    bool bandera = true;
    int acumVentaxprenda=0;

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

        for (int x = 0; x < CantPrendas; x++) {
            _Prenda = _ArchiPrenda.LeerPrenda(x);

            if (_Prenda.getCodigo() == CodigoSeleccionado) {
                _ven.setCodigoPrenda(_Prenda.getCodigo());
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
            }
            ///acum
            acumVentaxprenda= CantPrendas* _pren.GetPrecioVenta();
        }

        int continuar;
        cout << "¿Desea agregar otro producto a la venta? 1-si 2-no" << endl;
        cin >> continuar;

        if (continuar == 2) { bandera = false; }
    }
}

void VentaManager::SubMenuEstadisticaProductos() {
    int CantVentas = _ArchVenta.ContarRegistrosVenta();
    Venta Vent;

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
    for (int i = 0; i < CantVentas - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < CantVentas; j++) {
            if (vec[j] > vec[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            int temp = vec[i];
            vec[i] = vec[maxIndex];
            vec[maxIndex] = temp;
        }
    }

    // Imprimir las ventas en orden descendente
    for (int x = 0; x < CantVentas; x++) {
        cout << "Venta " << x+1 << ": " << vec[x] << std::endl;
    }

    // Liberar la memoria
    delete[] vec;
}





