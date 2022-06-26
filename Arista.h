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
    Arista(Vertice<Dato> * vertice_adyacente);
    ~Arista();
    void set_arista_siguiente(Arista<Dato> * arista_nueva);
    Arista<Dato>* get_arista_siguiente();
    void set_vertice_adyacente(Vertice<Dato> * vertice_adyacente);
    Vertice<Dato> * get_vertice_destino();
    Dato get_dato_vertice_adyacente();
    int get_peso();
    void set_peso(int peso);
};

template <typename Dato>
Arista<Dato>::Arista(Vertice<Dato> * vertice_destino,int peso){
    this->vertice_destino = vertice_destino;
    this->peso = peso;
    arista_siguiente = nullptr;
    vertice_destino = nullptr;
}

#endif