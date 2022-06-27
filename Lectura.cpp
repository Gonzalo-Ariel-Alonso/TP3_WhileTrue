#include <iostream>
#include <string>
using namespace std;

#include "Lectura.h"

Lectura::Lectura (char tipo_de_objeto, string titulo, int tiempo_lectura, int anio, int referencia_autor ){
    this->tipo_de_objeto = tipo_de_objeto;
    this->titulo = titulo;
    this->tiempo_lectura = tiempo_lectura;
    this->anio = anio;
    this->referencia_autor = referencia_autor;
    leido = false;
}

void Lectura::set_leido(bool leido){
    this->leido = leido;
}

bool Lectura::get_leido(){
    return leido;
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


char Lectura::get_tipo_de_objeto(){
  return tipo_de_objeto;
}

void Lectura::mostar_filtrado_por_escritor(Escritor * referencia_a_escritor){

    mostrar();
    cout << endl;

}

void Lectura::mostrar_filtrado_por_genero(Generos genero_a_filtrar){

}

Lectura::~Lectura(){
}
