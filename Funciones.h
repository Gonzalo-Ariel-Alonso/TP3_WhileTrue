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
    // PRE:
    // POST: Imprime el grafo que tiene como atributo
    void imprimir_grafo();
    // PRE:
    // POST: Imprime la tabla de hash con sus respectivas colisiones en caso de existir
    void imprimir_tabla_hash();
    // PRE:
    // POST: Imprime arbol de expansion minima calculado con prim
    void imprimir_arbol_expansion_minima();
    // PRE:
    // POST: Elimina el primer vertice que se dio de alta en el Grafo
    void eliminar_primer_vertice();
    // PRE:
    // POST: Agrega un escritor con los parametro pasados por consola
    void agregar_escritor();
    // PRE:
    // POST: Muestra todos los escritores
    void catalogo_escritores();
    // PRE:
    // POST: Nos da a elegir un escritor para eliminarlo
    void eliminar_escritor();

    void consulta_escritor();
private:
    void borrar_escritor_ISNI(string codigo_ISNI);
    void borrar_escritor_nombre();
};


#endif
