#include "VentaManager.h"


void VentaManager::SubMenuCargarVenta(){
    Venta _ven;
    Fecha obj;


    cout << "BIENVENIDO! ESTA USTED POR REALIZAR UNA VENTA" << endl;
    cout << "----------------------------------------------" << endl;
    _PrendManager.SubmenuInventario();

    bool bandera=true;

    while(bandera!=false){
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
                _ven.setVentaFecha(obj.ReturnFechaActual());

                //SI QUEREMOS MOSTRAR EL OBJETO FECHA:    "_ven.getVentaFecha().MostrarFechaActual();"

                 _ArchVenta.GuardarVenta(_ven); //guardo la venta en el archivo

               for(int x=0;x<CantPrendas;x++){ //recorro el archivo de prendas
                _Prenda = _ArchiPrenda.LeerPrenda(x);

                if(_Prenda.getCodigo() == _ven.getCodigo()){ //cuando encuentro la prenda seteo en el archivo
                   int pos = _ArchiPrenda.BuscarCodigoPrenda(x);
                    _Prenda.setCantidad(_Prenda.getCantidad()-_ven.getCantidad());

                    if(_Prenda.getCantidad()==0){ //si el stock queda en 0 le hago una vaja logica
                        _Prenda.setEstadoDePrenda(false);
                    }
                    _ArchiPrenda.SobreescribirArchivoPrenda(pos,_Prenda);
                }
               }
            }
       }

        int continuar;
        cout<<"desea agregar otro producto a la venta? 1-si 2-no"<<endl;
        cin>>continuar;

        if(continuar==2){bandera=false;}
    }

}




