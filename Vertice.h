#ifndef VERTICE_H
#define VERTICE_H

#include "Arista.h"

template <typename Dato>
class Arista;

template <typename Dato>
class Vertice
{
private:
    Vertice<Dato> * vertice_siguiente;
    Arista<Dato> * primera_arista;
    Dato contenido;
public:
    Vertice(Dato contenido);
    ~Vertice();
    Dato get_contenido();
    Vertice<Dato>* get_vertice_siguiente();
    void set_vertice_siguiente(Vertice<Dato> * vertice_siguiente);
    Arista<Dato> * get_primera_arista();
    void set_primera_arista(Arista<Dato>* primera_arista);

};

template <typename Dato>
Vertice<Dato>::Vertice(Dato contenido){
    this->contenido = contenido;
    primera_arista = nullptr;
    vertice_siguiente = nullptr;
}

template <typename Dato>
Vertice<Dato>::~Vertice()
{
}

template <typename Dato>
Dato Vertice<Dato>::get_contenido(){
    return contenido;
}

template <typename Dato>
Vertice<Dato>* Vertice<Dato>::get_vertice_siguiente(){
    return vertice_siguiente;
}

template <typename Dato>
void Vertice<Dato>::set_vertice_siguiente(Vertice<Dato> * vertice_siguiente){
    this->vertice_siguiente = vertice_siguiente;
}

template <typename Dato>
Arista<Dato> * Vertice<Dato>::get_primera_arista(){
    return primera_arista;
}

template <typename Dato>
void Vertice<Dato>::set_primera_arista(Arista<Dato>* primera_arista){
    this->primera_arista = primera_arista;
}
#endif