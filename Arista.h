#ifndef ARISTA_H
#define ARISTA_H

#include "Vertice.h"

//#include "Descanso_entre_lecturas.h"

template <typename Dato>
class Arista
{
private:
    Arista * arista_adyacente;
    Vertice<Dato> * vertice_adyacente;
    int peso;

public:
    Arista();
    Arista(Vertice<Dato> * vertice_adyacente);
    ~Arista();
    void set_arista_siguiente(Arista<Dato> * arista_nueva);
    Arista<Dato>* get_arista_siguiente();
    void set_vertice_adyacente(Vertice<Dato> * vertice_adyacente);
    Vertice<Dato> * get_vertice_adyacente();
    Dato get_dato_vertice_adyacente();
    int get_peso();
};

template <typename Dato>
Arista<Dato>::Arista(){
}


template <typename Dato>
Arista<Dato>::~Arista(){
    arista_adyacente = nullptr;
    vertice_adyacente = nullptr;
}

template <typename Dato>
Arista<Dato>::Arista(Vertice<Dato> * vertice_adyacente){
    this->vertice_adyacente = vertice_adyacente;
    /*Descanso_entre_lecturas Descanso(Vertice_adyacente->get_tipo_de_lectura,arista_adyacente->get_vertice_adyacente()->get_tipo_de_lectura);
    peso = Descanso.get_tiempo_de_descanso();*/
}

template <typename Dato>
void Arista<Dato>::set_arista_siguiente(Arista<Dato> * arista_nueva){
    arista_adyacente = arista_nueva;
}


template <typename Dato>
void Arista<Dato>::set_vertice_adyacente(Vertice<Dato> * vertice_adyacente){
    this->vertice_adyacente = vertice_adyacente;
}

template <typename Dato>
Vertice<Dato> * Arista<Dato>::get_vertice_adyacente(){
    return vertice_adyacente;
}

template <typename Dato>
Dato Arista<Dato>::get_dato_vertice_adyacente(){
  return vertice_adyacente->get_dato_vertice();
}

template <typename Dato>
int Arista<Dato>::get_peso(){
    return peso;
}


#endif
