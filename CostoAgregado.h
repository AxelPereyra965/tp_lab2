#ifndef COSTOAGREGADO_H_INCLUDED
#define COSTOAGREGADO_H_INCLUDED

class CostoAgregado
{
private:
    int CodigoPrenda;
    float CostoPackaging;
    float CostoEtiqueta;
public:
    CostoAgregado(int _CodigoPrenda, float _CostoPackaging, float _CostoEtiqueta);
    int getCodigo();
    float getPackaging();
    float getEtiqueta();
    void setCodigo(int _CodigoPrenda);
    void setPackaging(float _CostoPackaging);
    void setEtiqueta(float _CostoEtiqueta);
};

#endif // COSTOAGREGADO_H_INCLUDED

