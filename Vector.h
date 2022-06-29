#ifndef VECTOR_H
#define VECTOR_H

// includes de otros TDA
#include "Escritor.h"
#include "Lista.h"

class Vector{
  private:
    //atributos
    Lista<Escritor*> lista_objetos;
    int cantidad_anidados;

  public:
    /*
    Constructor
    Pre: -
    Pos: Inicializa un vector con cantidad 0
    */
    Vector();
    /*
    Agrega un escritor a la lista
    Pre: Un puntero a escritor
    Pos: -
    */
    void agregar_objeto ( Escritor* nuevo_escritor );
    /*
    Elimina un objeto del vector
    Pre: El nombre del objeto a eliminar (string)
    Pos: -
    */
    void eliminar_objeto ( string objeto_sacar );
    // Definida en "Lista.h"
    Escritor* consulta ( string referencia );
    /*
    Devuelve la cantidad de anidados(atributo)
    Pre: -
    Pos: Un numero entero
    */
    int get_cantidad_anidados();
    /*
    Imprime la lista
    Pre: -
    Pos: -
    */
    void imprimir_lista();
  };


#endif //VECTOR_H
