#include "Funciones.h"

Funciones::Funciones(Grafo<Lectura *>* grafo,Vector *vector_escritores){
    this->grafo = grafo;
    this->vector_escritores = vector_escritores;
}

Funciones::~Funciones(){
grafo = 0;
vector_escritores = 0;
}