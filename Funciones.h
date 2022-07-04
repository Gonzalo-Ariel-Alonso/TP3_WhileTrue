#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Vector.h"
#include "Grafo.h"
#include "Lectura.h"


class Funciones
{
private:
    Grafo<Lectura *>* grafo;
    Vector *vector_escritores;

public:
    Funciones(Grafo<Lectura *> *grafo,Vector *vector_escritores);
    ~Funciones();

};


#endif