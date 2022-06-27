#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>

#include "Vector.h"
#include "Grafo.h"
#include "Tipo_de_lecturas.h"
#include "Escritor.h"
#include "Lectura.h"
#include "Novela_historica.h"
#include "Novela.h"
#include "Cuento.h"
#include "Poema.h"
#include "Genero.h"


using namespace std;

#define TAMANIO_VECTOR 25
/*
TAMAÑO_VECTOR = cantidad elementos / tamaño vector
  TAMAÑO_VECTOR >= 0.8 y como da 25
*/


class Archivos {
private:
  Vector * vector_escritores;
  string escritores_txt;
  Grafo<Lectura*> * grafo_completo;
  string lecturas_txt;

public:
  Archivos( string escritores_txt ,Vector * vector_escritores, Grafo<Lectura*> * grafo, string lecturas_txt);
  Archivos ( string archivo_escritores_txt );
  ~Archivos();
  string sacar_parentesis ( string referencia_escritor );
  void leer_archivo_escritores();
  void carga_vector_escritores(string referencia_escritor, string nombre, string nacionalidad, string anio_nacimiento, string anio_fallecimiento);
  int funcion_hashing ( string referencia_escritor );

  void cargar_grafo();
  Generos de_string_a_enumerado(string genero_string);
  void crear_tipo_lectura(char tipo_lectura, string titulo, string duracion_lectura, string ano_publicacion, int referencia_autor, string referencia_a_lectura);
  void crear_tipo_lectura(char tipo_lectura, string titulo, string duracion_lectura, string ano_publicacion, int referencia_autor, string referencia_a_lectura, string tema);
};



#endif
