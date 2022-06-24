#ifndef ARISTA_H
#define ARISTA_H

#include "Vertice.h"
//#include "Descanso_entre_lecturas.h"

template <class Dato>
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
    void set_arista_siguiente(Arista * arista_nueva);
    Arista get_arista_siguiente();
    void set_vertice_adyacente(Vertice<Dato> * vertice_adyacente);
    Vertice<Dato> * get_vertice_adyacente();
    int get_peso();
};

template <class Dato>
Arista<Dato>::Arista(){
}


template <class Dato>
Arista<Dato>::~Arista(){
    arista_adyacente = nullptr;
}

template <class Dato>
Arista<Dato>::Arista(Vertice<Dato> * vertice_adyacente){
    this->vertice_adyacente = vertice_adyacente;
    /*Descanso_entre_lecturas Descanso(Vertice_adyacente->get_tipo_de_lectura,arista_adyacente->get_vertice_adyacente()->get_tipo_de_lectura);
    peso = Descanso.get_tiempo_de_descanso();*/
}

template <class Dato>
void Arista<Dato>::set_arista_siguiente(Arista * arista_nueva){
    arista_adyacente = arista_nueva;
}

template <class Dato>
Arista<Dato> Arista<Dato>::get_arista_siguiente(){
    return arista_adyacente;
}

template <class Dato>
void Arista<Dato>::set_vertice_adyacente(Vertice<Dato> * vertice_adyacente){
    this->vertice_adyacente = vertice_adyacente;
}
template <class Dato>
Vertice<Dato> * Arista<Dato>::get_vertice_adyacente(){
    return vertice_adyacente;
}

template <class Dato>
int Arista<Dato>::get_peso(){
    return peso;
}


#endif