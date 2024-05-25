#ifndef PRENDA_H_INCLUDED
#define PRENDA_H_INCLUDED

#include <string>
#include "Fecha.h"
#include <cstring>
using namespace std;
class Prenda{

    private:
        int _codigoPrenda;
        char _nombre[50];
        char _talle[50];
        char _Modelo[50];
        char _color[50];
        char _campania[50];
        int _cantidad;
        float _porcentajeGanancia;
        bool _activo;

    public:
        Prenda(int codPren,const char*n, const char *talle, const char *mod ,const char*co, const char *cam, int cant, float pg, bool activo);
        //Prenda();
        void setCodigoPrenda(int codigoPrenda);
        void setNombre(const char*n);
        void setTalle(const char *talle);
        void setModelo(const char *mod);
        void setColor(const char*co);
        void setCampania(const char *cam);
        void setCantidad(int cant);
        void setPorcentajeGanancia(float pg);
        void setActivo(bool activo);

        int getCodigoPrenda();
        char getNombre();
        char getTalle();
        char getModelo();
        char getColor();
        char getCampania();
        int getCantidad();
        float getPorcentajeGanancia();
        bool getActivo();
};

#endif // PRENDA_H_INCLUDED
