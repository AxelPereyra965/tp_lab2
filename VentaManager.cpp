#include "VentaManager.h"

void VentaManager::SubMenuCargarVenta(){
    Venta _ven;

    cout << "BIENVENIDO! ESTA USTED POR REALIZAR UNA VENTA" << endl;
    cout << "----------------------------------------------" << endl;
    _PrendManager.SubmenuInventario();

    bool bandera=true;

    while(bandera!=true){
        int CodigoSeleccionado;
        cout<<"seleccione el codigo de la prenda que desea vender"<<endl;
        cin>>CodigoSeleccionado;

        //entramos al archivo de prenda y rrecorremos todas las prendas
        //filtramos por el codigo elegido
        //seteamos el objeto que creamos
        //lo subimos al archivi de venta

       int CantPrendas= _ArchiPrenda.ContarRegistrosPrenda();

       for(int x=0;x<CantPrendas;x++){
            _Prenda=_ArchiPrenda.LeerPrenda(x);

            if(_Prenda.getCodigo()==CodigoSeleccionado){
                _ven.setCodigoPrenda(_Prenda.getCodigo());
                _ven.setNombrePrenda(_Prenda.getNombrePrenda());
                _ven.setModelo(_Prenda.getModelo());
                _ven.setTalle(_Prenda.getTalle());
                _ven.setColor(_Prenda.getColor());
                _ven.setCantidad(1);
                _ven.setColor(_Prenda.getColor());
                //_ven.setVentaFecha();

                //guarda en archivo
            }

       }

        int continuar;
        cout<<"desea agregar otro producto a la venta? 1-si 2-no"<<endl;
        cin>>continuar;

        if(continuar==2){bandera=false;}
    }

}





