#ifndef VECTOR_H
#define VECTOR_H

// includes de otros TDA
#include <string>
#include "Escritor.h"
#include "Lista.h"


const int TAMANIO_VECTOR = 25;

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

    void eliminar_objeto_nombre (string nombre_escritor);

    // Definida en "Lista.h"
    bool consulta ( string referencia );


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

    /*
    Transforma la referencia del escritor a un hash
    Pre: La referencia del escritor(una cadena de numeros)
    Pos: Devuelve la posicion en la que iria el escritor dentro del vector
    */
    int funcion_hashing ( string referencia_escritor );
  };


#endif //VECTOR_H
