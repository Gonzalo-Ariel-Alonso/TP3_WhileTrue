#include <iostream>
#include <string>
using namespace std;

#include "Lectura.h"

Lectura::Lectura (char tipo_de_lectura, string titulo, int tiempo_lectura, int anio, int referencia_autor ){
    this->tipo_de_lectura = de_char_a_enumerado(tipo_de_lectura);
    this->titulo = titulo;
    this->tiempo_lectura = tiempo_lectura;
    this->anio = anio;
    this->referencia_autor = referencia_autor;
}


string Lectura::get_titulo(){
    return titulo;
}
int Lectura::get_tiempo_lectura(){
    return tiempo_lectura;
}

int Lectura::get_anio(){
    return anio;
}


Tipo_de_lecturas Lectura::get_tipo_de_lectura(){
  return tipo_de_lectura;
}


Tipo_de_lecturas Lectura::de_char_a_enumerado(char char_tipo_lectura){

  Tipo_de_lecturas Tipo_de_lecturas;
  if(char_tipo_lectura  == 'N')
    Tipo_de_lecturas = NOVELA;
  else if (char_tipo_lectura == 'C')
    Tipo_de_lecturas = CUENTO;
  else if (char_tipo_lectura  == 'P')
    Tipo_de_lecturas = POEMA;
  else if (char_tipo_lectura  == 'H')
    Tipo_de_lecturas = NOVELA_HISTORICA;

  return Tipo_de_lecturas;

}

Lectura::~Lectura(){
}
