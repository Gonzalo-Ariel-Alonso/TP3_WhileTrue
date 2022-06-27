#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>

#include "Vector.h"
#include "Grafo.h"

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

  Grafo<Dato> * grafo_completo;
  string lecturas_txt;

public:
  Archivos ( string archivo_escritores_txt );
  string sacar_parentesis ( string referencia_escritor );
  void leer_archivo_escritores();
  void carga_vector_escritores(string referencia_escritor, string titulo, string nombre, string nacionalidad, string anio_nacimiento, string anio fallecimiento);
  int funcion_hashing ( string referencia_escritor );
  void imprimir_vector();

  void cargar_grafo();
  Generos de_string_a_enumerado(string genero_string);
  void crear_tipo_lectura(char tipo_lectura, string titulo, int duracion_lectura, int ano publicacion, int referencia_autor, string referencia_a_lectura);
  void crear_tipo_lectura(char tipo_lectura, string titulo, int duracion_lectura, int ano publicacion, int referencia_autor, string referencia_a_lectura, string tema);
};



#endif
