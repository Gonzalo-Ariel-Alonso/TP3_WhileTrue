#ifndef ARISTA_H
#define ARISTA_H

#include <iostream>
#include "Vertice.h"

using namespace std;

template <typename Dato>
class Vertice;

template <typename Dato>
class Arista
{
private:
    Arista<Dato> * arista_siguiente;
    Vertice<Dato> * vertice_destino;
    int peso;

public:
    Arista(Vertice<Dato> * vertice_destino,int peso);
    ~Arista();
    void set_arista_siguiente(Arista<Dato> * arista_nueva);
    Arista<Dato>* get_arista_siguiente();
    void set_vertice_destino(Vertice<Dato> * vertice_destino);
    Vertice<Dato> * get_vertice_destino();
    int get_peso();
};

template <typename Dato>
Arista<Dato>::Arista(Vertice<Dato> * vertice_destino,int peso){
    this->vertice_destino = vertice_destino;
    this->peso = peso;
    arista_siguiente = nullptr;
    vertice_destino = nullptr;
}

template <typename Dato>
void Arista<Dato>::set_arista_siguiente(Arista<Dato> * arista_nueva){
    arista_nueva = arista_siguiente;
}

template <typename Dato>
Arista<Dato>* Arista<Dato>::get_arista_siguiente(){
    return arista_siguiente;
}

template <typename Dato>
void Arista<Dato>::set_vertice_destino(Vertice<Dato> * vertice_destino){
    this->vertice_destino = vertice_destino;
}

template <typename Dato>
int Arista<Dato>::get_peso(){
    return peso;
}

template <typename Dato>
Vertice<Dato> * Arista<Dato>::get_vertice_destino(){
    return vertice_destino;
}

template <typename Dato>
Arista<Dato>::~Arista(){

}
#endif