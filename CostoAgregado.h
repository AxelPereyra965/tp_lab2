#ifndef COSTOAGREGADO_H_INCLUDED
#define COSTOAGREGADO_H_INCLUDED

class CostoAgregado
{
private:
    int CodigoPrenda;
    float CostoPackaging;
    float CostoEtiqueta;
public:
    CostoAgregado(int codigo_prenda, float costo_packaging, float costo_etiqueta);
    int getCodigo();
    float getPackaging();
    float getEtiqueta();
    void setCodigo(int codigo_prenda);
    void setPackaging(float costo_packaging);
    void setEtiqueta(float costo_etiqueta);
};

#endif // COSTOAGREGADO_H_INCLUDED

