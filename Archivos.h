#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>

#include "Vector.h"

using namespace std;

#define TAMANIO_VECTOR 25
/*
TAMAÑO_VECTOR = cantidad elementos / tamaño vector
  TAMAÑO_VECTOR >= 0.8 y como da 25
*/

class Archivos {
private:
  Vector vector_escritores[TAMANIO_VECTOR];
  string escritores_txt;

public:
  Archivos ( string archivo_escritores_txt );
  string sacar_parentesis ( string referencia_escritor );
  void crear_vector_escritores ();
  int funcion_hashing ( string referencia_escritor );
  void imprimir_vector();
};



#endif
