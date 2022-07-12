#ifndef TABLA_HASH_H
#define TABLA_HASH_H

// includes de otros TDA
#include <string>
#include "Vector.h"
#include "Escritor.h"
#include "Lista.h"

const int TAMANIO_VECTOR = 25;


class Tabla_hash{

private:
  Vector * vector_escritores;

public:
  Tabla_hash();

  ~Tabla_hash();

  /*
  Transforma la referencia del escritor a un hash
  Pre: La referencia del escritor(una cadena de numeros)
  Pos: Devuelve la posicion en la que iria el escritor dentro del vector
  */
  int funcion_hashing ( int referencia_escritor );

  void alta(Escritor * nuevo_escritor);

  // PRE:
  // POST: Imprime la tabla de hash con sus respectivas colisiones en caso de existir
  void imprimir_tabla_hash();

  // PRE:
  // POST: Muestra todos los escritores
  void catalogo_escritores();

  void baja_escritor_por_codigo(string codigo_isni );

  void baja_escritor_por_nombre(string nombre_escritor );

  bool buscar_escritor(string nombre_escritor);

};

#endif //TABLA_HASH_H
