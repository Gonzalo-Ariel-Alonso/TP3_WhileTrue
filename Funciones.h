#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Vector.h"
#include "Grafo.h"
#include "Lectura.h"

using namespace std;

class Funciones
{
private:
    Grafo<Lectura *> * grafo;
    Vector *vector_escritores;

public:
    Funciones(Grafo<Lectura *> *grafo,Vector *vector_escritores);
    ~Funciones();
    void imprimir_grafo();
    void imprimir_tabla_hash();
    void imprimir_arbol_expansion_minima();
    void eliminar_primer_vertice();
    void agregar_escritor();
    void catalogo_escritores();
};


#endif
