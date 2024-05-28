#include "CostoAgregado.h"


// Constructor


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



