#include "Vertice.h"

Vertice::Vertice(int peso_conexion, Tipo_de_lectura tipo_de_lectura,std::string titulo){
    this->peso_conexion = peso_conexion;
    this->tipo_de_lectura = tipo_de_lectura;
    this->titulo = titulo;
}
Vertice::Vertice(){

}

Vertice::~Vertice(){

}

int Vertice::get_peso(){
    return peso_conexion;
}

std::string Vertice::get_titulo(){
    return titulo;
} 