#include "CostoAgregado.h"


// Constructor
CostoAgregado::CostoAgregado(){
    CodigoPrenda=0;
    CostoPackaging=0.0f;
    CostoEtiqueta=0.0f;
}
CostoAgregado::CostoAgregado(int _CodigoPrenda, float _CostoPackaging, float _CostoEtiqueta)
{
    setCodigo(_CodigoPrenda);
    setPackaging(_CostoPackaging);
    setEtiqueta(_CostoEtiqueta);
}


// Getters
int CostoAgregado::getCodigo() {
    return CodigoPrenda;
}


float CostoAgregado::getPackaging() {
    return CostoPackaging;
}


float CostoAgregado::getEtiqueta() {
    return CostoEtiqueta;
}

// Setters
void CostoAgregado::setCodigo(int _CodigoPrenda) {
    CodigoPrenda = _CodigoPrenda;
}


void CostoAgregado::setPackaging(float _CostoPackaging) {
    CostoPackaging = _CostoPackaging;
}


void CostoAgregado::setEtiqueta(float _CostoEtiqueta) {
    CostoEtiqueta = _CostoEtiqueta;
}



