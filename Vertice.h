#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "Tipos_de_lecturas.h"

class Vertice {
    private:
        int peso_conexion;
        Tipo_de_lectura tipo_de_lectura;
        std::string titulo;
    public:
        Vertice(int peso_conexion, Tipo_de_lectura tipo_de_lectura,std::string titulo);
        Vertice();
        ~Vertice();
        int get_peso();
        std::string get_titulo();


};

#endif